#include "pgdbcommon.h"

SUser::SUser(soci::session& sqlsession):m_sql(sqlsession), m_stSUser(sqlsession)
{

    try
    {
        
        
        
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
    
int64_t SUser::createRow( 
                    const std::string&  username,
                    const std::string&  address,
                    const std::string&  pass,
                    const int64_t       points,
                    const int64_t       gain,
                    const std::tm      jointime,
                    const std::tm      lastlogintime
                    )
{
    m_address=address;
    m_username=username;
    m_pass=pass;
    m_points=points;
    m_gain=gain;
    m_jointime=jointime;
    m_lastlogintime=lastlogintime;
    m_stSUser.execute(true);
    return m_uid;
}
