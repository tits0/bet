#include "pgdbcommon.h"

SFinalizeScheme::SFinalizeScheme(soci::session& sqlsession):m_sql(sqlsession), m_stFinalizeScheme(sqlsession)
{

    try
    {
    m_stFinalizeScheme =  (m_sql.prepare <<
    "insert into finalizebet( s_id, \
    opt_won,  opt_of_user, u_id, \
    points_invested, gain, finalizetime ) \
    values ( :schemeid, :optionwon, :optionofuser, :userid, :pointsinvested, :gain, :finalizetime );" , 
    soci::use( m_scheme_id, "schemeid"), 
    soci::use(m_optionwon, "optionwon"), 
    soci::use(m_optionofuser, "optionofuser"), 
    soci::use(m_userid, "userid"), 
    soci::use(m_pointsinvested, "pointsinvested"),
    soci::use(m_gain, "gain"), 
    soci::use(m_finalizetime, "finalizetime") ) ;
       }
        catch (std::exception const &e)
        {
            std::cerr << "Error: " << e.what() << '\n';
            throw e; 
        }
        
}
    
void SFinalizeScheme::createRow( const int64_t scheme_id,
                    const int64_t optionwon,
                    const int64_t optionofuser,
                    const int64_t user,
                    const int64_t pointsinvested,
                    const int64_t gain,
                    std::tm       finalizetime)
{
    m_scheme_id = scheme_id;
    m_optionwon = optionwon;
    m_optionofuser = optionofuser;
    m_userid = user;
    m_pointsinvested = pointsinvested;
    m_gain = gain;
    m_finalizetime = finalizetime;
    m_stFinalizeScheme.execute(true);
                        
}
