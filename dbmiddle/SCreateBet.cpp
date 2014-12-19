#include "pgdbcommon.h"

SCreateBet::SCreateBet(soci::session& sqlsession):m_sql(sqlsession), m_stCreateBet(sqlsession)
{
    try
    {
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

void SCreateBet::createRow( const int64_t schemeid,
                    const int64_t optid,
                    const int64_t user,
                    const int64_t approvedby,
                    const int64_t points,
                    std::tm     bettime )
{
    m_scheme_id = schemeid;
    m_opt_id = optid;
    m_userid = user;
    m_approvedby  = approvedby;
    m_points = points;
    m_bettime = bettime;
    m_stCreateBet.execute(true);
}
