#include "pgdbcommon.h"
#include "error_codes.h"

SCreateBet::SCreateBet(soci::session& sqlsession):m_sql(sqlsession), 
m_stCreateBet(sqlsession),
m_stSelectUPoints(sqlsession),
m_stUpdateUPoints(sqlsession),
m_stUpdateOptions(sqlsession)
{
    try
    {

        m_stSelectUPoints = (m_sql.prepare << "select points, gain, bonus, purchase, lastlogin from u_table where u_id = :uid; ", 
        soci::into(m_curr_points, m_curr_points_ind),
        soci::into( m_curr_gain, m_curr_gain_ind),
        soci::into(m_curr_bonus, m_curr_bonus_ind ), 
        soci::into( m_curr_purchase, m_curr_purchase_ind), 
        soci::into( m_curr_lastlogin, m_curr_lastlogin_ind ),
        soci::use(m_userid, "uid") );

        m_stUpdateUPoints = (m_sql.prepare << "update u_table SET points=points-:betpoint where u_id = :uid; ", 
        soci::use(m_points, "betpoint"),
        soci::use(m_userid, "uid") );

                   
      //Update options according to the option selected.
      
      m_stUpdateOptions = (m_sql.prepare << "UPDATE options \
      set opttotal=opttotal+:points, placed=placed+1 where s_id= :schemeid and opt_id =:opt_id",
      soci::use(m_points, "points"), soci::use(m_scheme_id, "schemeid") , soci::use(m_opt_id, "opt_id") );
      
      m_stCreateBet =  (m_sql.prepare << 
        "insert into bet( s_id, opt_id , u_id, points, bettime ) \
        values ( :schemeid, :optionid, :userid, :points, :bettime );" , 
        soci::use(m_scheme_id, "schemeid"),
        soci::use(m_opt_id, "optionid"), 
        soci::use(m_userid, "userid"), 
        soci::use(m_points, "points"), 
        soci::use(m_bettime, "bettime") );
    }
    catch (std::exception const &e)
    {
        std::cerr << "Error: " << e.what() << '\n';
        throw e; 
    }

}    

ERROR_CODES_BACCT SCreateBet::createRow( const int64_t schemeid,
    const int64_t optid,
    const int64_t user,
    const int64_t approvedby,
    const int64_t points,
    std::tm     bettime )
{
    ERROR_CODES_BACCT ret=ERROR_CODES_BACCT::ERROR_BET_FAILED;
    try
    {
        m_scheme_id = schemeid;
        m_opt_id = optid;
        m_userid = user;
        m_approvedby  = approvedby;
        m_points = points;
        m_bettime = bettime;

        m_stSelectUPoints.execute(false);
        if(m_stSelectUPoints.fetch())
        {
            ///search for the user and if user has enough points.
           if (m_stSelectUPoints.got_data()) {
                
            if(soci::i_ok == m_curr_points_ind) {
                if(m_points > m_curr_points) {
                    return ERROR_CODES_BACCT::ERROR_NOT_ENOUGH_POINTS;
                }
             } else {
                return ERROR_CODES_BACCT::ERROR_USER_POINTS_NULL;
            }
            } else {
                ///search for the user failed.
                return ERROR_CODES_BACCT::ERROR_USER_NOT_FOUND;
            }
               
       } else {
            return ERROR_CODES_BACCT::ERROR_QUERY_FAILED;
       }
 
        
        //check correctness of option id
        if(m_opt_id>MAX_OPTS_BACCT || m_opt_id< 1) {
            return ERROR_CODES_BACCT::ERROR_OPT_NOT_FOUND;
        }
        soci::transaction tr(m_sql);
        m_stUpdateOptions.execute(true);
        m_stCreateBet.execute(true);
        m_stUpdateUPoints.execute(true);
        tr.commit();
    }
    catch (std::exception const &e)
    {
        std::cerr << "Error: " << e.what() << '\n';
        ret=ERROR_CODES_BACCT::ERROR_BET_FAILED;
    }
    ret=ERROR_CODES_BACCT::ERROR_OK;
    return ret;
}
