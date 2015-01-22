#include "pgdbcommon.h"

SFinalizeScheme::SFinalizeScheme(soci::session& sqlsession):m_sql(sqlsession), m_stFinalizeScheme(sqlsession)
{
    try
    {
        m_stFinalizeScheme =  (m_sql.prepare <<
        "insert into finalizebet( s_id, \
        opt_won,  finalizetime ) \
        values ( :schemeid, :optionwon, :finalizetime );" , 
        soci::use( m_scheme_id, "schemeid"), 
        soci::use(m_optionwon, "optionwon"), 
        soci::use(m_finalizetime, "finalizetime") ) ;
    }
    catch (std::exception const &e)
    {
        std::cerr << "Error: " << e.what() << '\n';
        throw e; 
    }
        
}
    
ERROR_CODES_BACCT SFinalizeScheme::createRow( const int64_t scheme_id,
                    const int64_t optionwon,
                    std::tm       finalizetime)
{
    ERROR_CODES_BACCT ret=ERROR_CODES_BACCT::ERROR_FINALIZE_FAILED;
    m_scheme_id = scheme_id;
    m_optionwon = optionwon;
    m_finalizetime = finalizetime;
    try
    {
        m_stFinalizeScheme.execute(true);
        ret=ERROR_CODES_BACCT::ERROR_OK;
    }
    catch (std::exception const &e)
    {
        std::cerr << "Error: " << e.what() << '\n';
         
    }
    return ret;
}
