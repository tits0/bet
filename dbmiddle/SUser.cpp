#include "pgdbcommon.h"

SUser::SUser(soci::session& sqlsession):m_sql(sqlsession), m_stSUser(sqlsession),m_stSelectUPoints(sqlsession)
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
        
    m_stSUser =  (m_sql.prepare <<
    "insert into u_table( u_idc, points, gain, name, namev, joindate, lastlogin ) \
       values ( :address, :points, :gain, :username, :pass, :jointime, :lastlogintime) \
        returning u_id ;" , 
        soci::use( m_address, "address"), 
        soci::use( m_points,  "points"), 
        soci::use( m_gain, "gain"),
        soci::use( m_username, "username"), 
        soci::use( m_pass, "pass"), 
        soci::use(m_jointime, "jointime"), 
        soci::use(m_lastlogintime, "lastlogintime") ,
        soci::into(m_uid) ) ;
       }
       catch (std::exception const &e)
       {
            std::cerr << "Error: " << e.what() << '\n';
            throw e; 
       }
        
}
    
ERROR_CODES_BACCT SUser::createRow( 
                    const std::string&  username,
                    const std::string&  address,
                    const std::string&  pass,
                    const int64_t       points,
                    const int64_t       gain,
                    const std::tm      jointime,
                    const std::tm      lastlogintime,
                    int64_t& uid
                    )
{
    
    m_address=address;
    m_username=username;
    m_pass=pass;
    m_points=points;
    m_gain=gain;
    m_jointime=jointime;
    m_lastlogintime=lastlogintime;
    ERROR_CODES_BACCT ret=ERROR_CODES_BACCT::ERROR_OK;

       try {
        m_stSUser.execute(true);
        uid=m_uid;
       }
       catch (std::exception const &e)
       {
            std::cerr << "Error: " << e.what() << '\n';
            ret=ERROR_CODES_BACCT::ERROR_USER_CREATION_FAILED;
       }
    return ret;
}


ERROR_CODES_BACCT  SUser::getPoints(  
                    int64_t&  purchase,
                    int64_t&  bonus,
                    int64_t&  points,
                    int64_t&  gain,
                    std::tm&  lastlogintime,
                    const int64_t uid
                    )
{
    m_userid=uid;
    ERROR_CODES_BACCT ret=ERROR_CODES_BACCT::ERROR_OK;

       try {
            m_stSelectUPoints.execute(false);
            if(m_stSelectUPoints.fetch())
            {
                ///search for the user and if user has enough points.
               if (m_stSelectUPoints.got_data()) {
                ///null stoted in points
                if(soci::i_ok == m_curr_points_ind) {
                    if(m_points > m_curr_points) {
                        return ERROR_CODES_BACCT::ERROR_NOT_ENOUGH_POINTS;
                    }
                 } else {
                    return ERROR_CODES_BACCT::ERROR_USER_POINTS_NULL;
                }///search for the user and if user has enough points.
                } else {
                    ///search for the user failed.
                    return ERROR_CODES_BACCT::ERROR_USER_NOT_FOUND;
                }

                points=m_curr_points;
                gain=m_curr_gain;
                bonus=m_curr_bonus;
                purchase=m_curr_purchase;
                lastlogintime=m_curr_lastlogin;

                   
           } else {
                return ERROR_CODES_BACCT::ERROR_QUERY_FAILED;
           }
     
           
       }
       catch (std::exception const &e)
       {
            std::cerr << "Error: " << e.what() << '\n';
            ret=ERROR_CODES_BACCT::ERROR_USER_CREATION_FAILED;
       }
    return ret;
}
