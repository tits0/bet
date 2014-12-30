#include "pgdbcommon.h"
#include "error_codes.h"

SCreateBet::SCreateBet(soci::session& sqlsession):m_sql(sqlsession), m_stCreateBet(sqlsession),m_stSelectUPoints(sqlsession)
{
    try
    {

        m_stSelectUPoints = (m_sql.prepare << "select points, gain, bonus, purchase, lastlogin from u_table where u_id = :uid; ", 
        soci::into(m_curr_points, m_curr_points_ind),
        soci::into( m_curr_gain, m_curr_gain),
        soci::into(m_curr_bonus, m_curr_bonus ), 
        soci::into( m_curr_purchase, m_curr_purchase), 
        soci::into( m_curr_lastlogin, m_curr_lastlogin ),
        soci::use(m_userid, "userid") );

                   
      //Update scheme_option_summary  according to the option selected.
      m_stUpdateSumm[0].reset( new soci::statement(( m_sql.prepare << "UPDATE scheme_option_summary set seq_01=seq_01+ :seq, placed_seq_01=placed_seq_01+1, total=total+ :seq where s_id= :schemeid",
      soci::use(m_points, "seq"), soci::use(m_scheme_id, "schemeid") )));
      
      m_stUpdateSumm[1].reset( new soci::statement((m_sql.prepare << "UPDATE scheme_option_summary set seq_02=seq_02+ :seq, placed_seq_02=placed_seq_02+1, total=total+ :seq where s_id= :schemeid",
      soci::use(m_points, "seq"), soci::use(m_scheme_id, "schemeid") )));
      m_stUpdateSumm[2].reset( new soci::statement((m_sql.prepare << "UPDATE scheme_option_summary set seq_03=seq_03+ :seq, placed_seq_03=placed_seq_03+1, total=total+ :seq where s_id= :schemeid",
      soci::use(m_points, "seq"), soci::use(m_scheme_id, "schemeid") )));
      m_stUpdateSumm[3].reset( new soci::statement((m_sql.prepare << "UPDATE scheme_option_summary set seq_04=seq_04+ :seq, placed_seq_04=placed_seq_04+1, total=total+ :seq where s_id= :schemeid",
      soci::use(m_points, "seq"), soci::use(m_scheme_id, "schemeid") )));
      m_stUpdateSumm[4].reset( new soci::statement((m_sql.prepare << "UPDATE scheme_option_summary set seq_05=seq_05+ :seq, placed_seq_05=placed_seq_05+1, total=total+ :seq where s_id= :schemeid",
      soci::use(m_points, "seq"), soci::use(m_scheme_id, "schemeid") )));
      m_stUpdateSumm[5].reset( new soci::statement((m_sql.prepare << "UPDATE scheme_option_summary set seq_06=seq_06+ :seq, placed_seq_06=placed_seq_06+1, total=total+ :seq where s_id= :schemeid",
      soci::use(m_points, "seq"), soci::use(m_scheme_id, "schemeid") )));
      m_stUpdateSumm[6].reset( new soci::statement((m_sql.prepare << "UPDATE scheme_option_summary set seq_07=seq_07+ :seq, placed_seq_07=placed_seq_07+1, total=total+ :seq where s_id= :schemeid",
      soci::use(m_points, "seq"), soci::use(m_scheme_id, "schemeid") )));
      m_stUpdateSumm[7].reset( new soci::statement((m_sql.prepare << "UPDATE scheme_option_summary set seq_08=seq_08+ :seq, placed_seq_08=placed_seq_08+1, total=total+ :seq where s_id= :schemeid",
      soci::use(m_points, "seq"), soci::use(m_scheme_id, "schemeid") )));
      m_stUpdateSumm[8].reset( new soci::statement((m_sql.prepare << "UPDATE scheme_option_summary set seq_09=seq_09+ :seq, placed_seq_09=placed_seq_09+1, total=total+ :seq where s_id= :schemeid",
      soci::use(m_points, "seq"), soci::use(m_scheme_id, "schemeid") )));
      m_stUpdateSumm[9].reset( new soci::statement((m_sql.prepare << "UPDATE scheme_option_summary set seq_10=seq_10+ :seq, placed_seq_10=placed_seq_10+1, total=total+ :seq where s_id= :schemeid",
      soci::use(m_points, "seq"), soci::use(m_scheme_id, "schemeid") )));
      m_stUpdateSumm[10].reset( new soci::statement((m_sql.prepare << "UPDATE scheme_option_summary set seq_11=seq_11+ :seq, placed_seq_11=placed_seq_11+1, total=total+ :seq where s_id= :schemeid",
      soci::use(m_points, "seq"), soci::use(m_scheme_id, "schemeid") )));
      m_stUpdateSumm[11].reset( new soci::statement((m_sql.prepare << "UPDATE scheme_option_summary set seq_12=seq_12+ :seq, placed_seq_12=placed_seq_12+1, total=total+ :seq where s_id= :schemeid",
      soci::use(m_points, "seq"), soci::use(m_scheme_id, "schemeid") )));
      m_stUpdateSumm[12].reset( new soci::statement((m_sql.prepare << "UPDATE scheme_option_summary set seq_13=seq_13+ :seq, placed_seq_13=placed_seq_13+1, total=total+ :seq where s_id= :schemeid",
      soci::use(m_points, "seq"), soci::use(m_scheme_id, "schemeid") )));
      m_stUpdateSumm[13].reset( new soci::statement((m_sql.prepare << "UPDATE scheme_option_summary set seq_14=seq_14+ :seq, placed_seq_14=placed_seq_14+1, total=total+ :seq where s_id= :schemeid",
      soci::use(m_points, "seq"), soci::use(m_scheme_id, "schemeid") )));
      m_stUpdateSumm[14].reset( new soci::statement((m_sql.prepare << "UPDATE scheme_option_summary set seq_15=seq_15+ :seq, placed_seq_15=placed_seq_15+1, total=total+ :seq where s_id= :schemeid",
      soci::use(m_points, "seq"), soci::use(m_scheme_id, "schemeid") )));
      m_stUpdateSumm[15].reset( new soci::statement((m_sql.prepare << "UPDATE scheme_option_summary set seq_16=seq_16+ :seq, placed_seq_16=placed_seq_16+1, total=total+ :seq where s_id= :schemeid",
      soci::use(m_points, "seq"), soci::use(m_scheme_id, "schemeid") )));
      m_stUpdateSumm[16].reset( new soci::statement((m_sql.prepare << "UPDATE scheme_option_summary set seq_17=seq_17+ :seq, placed_seq_17=placed_seq_17+1, total=total+ :seq where s_id= :schemeid",
      soci::use(m_points, "seq"), soci::use(m_scheme_id, "schemeid") )));
      m_stUpdateSumm[17].reset( new soci::statement((m_sql.prepare << "UPDATE scheme_option_summary set seq_18=seq_18+ :seq, placed_seq_18=placed_seq_18+1, total=total+ :seq where s_id= :schemeid",
      soci::use(m_points, "seq"), soci::use(m_scheme_id, "schemeid") )));
      m_stUpdateSumm[18].reset( new soci::statement((m_sql.prepare << "UPDATE scheme_option_summary set seq_19=seq_19+ :seq, placed_seq_19=placed_seq_19+1, total=total+ :seq where s_id= :schemeid",
      soci::use(m_points, "seq"), soci::use(m_scheme_id, "schemeid") )));
      m_stUpdateSumm[19].reset( new soci::statement((m_sql.prepare << "UPDATE scheme_option_summary set seq_20=seq_20+ :seq, placed_seq_20=placed_seq_20+1, total=total+ :seq where s_id= :schemeid",
      soci::use(m_points, "seq"), soci::use(m_scheme_id, "schemeid") )));
        
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
            
            if(m_curr_points)
                return ERROR_NOT_ENOUGH_POINTS;
            m_curr_gain;
            m_curr_bonus;
            m_curr_purchase;
            m_curr_lastlogin;

        }  

        
        //check correctness of option id
        if(m_opt_id>MAX_OPTS_BACCT || m_opt_id< 1) {
            return ERROR_OPT_NOT_FOUND;
        }
        m_stUpdateSumm[m_opt_id-1]->execute(true);          
        m_stCreateBet.execute(true);
    }
    catch (std::exception const &e)
    {
        std::cerr << "Error: " << e.what() << '\n';
        return ERROR_BET_FAILED;
    }
    
}
