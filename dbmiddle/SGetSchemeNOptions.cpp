#include "pgdbcommon.h"
#include "logger.h"

SGetSchemeNOptions::SGetSchemeNOptions(soci::session& sqlsession):m_sql(sqlsession), m_stSelectScheme(m_sql) ,
m_stSelectOptions(m_sql)
{
   try{
        m_stSelectScheme = (m_sql.prepare << "select scheme.s_id, scheme.scheme_name, scheme.permission, scheme.createtime, \
            scheme.endtime, scheme.uid_created, scheme.options \
            from scheme ; ", 
            soci::into(m_sid),
            soci::into( m_schemename),
            soci::into(m_permission), 
            soci::into( m_createtime ), 
            soci::into( m_endtime ),
            soci::into(m_usercreated), 
            soci::into(m_optseq)
             );

        m_stSelectOptions = (m_sql.prepare << "select options.opt_id, options.opt_name, options.opttotal \
            from options where options.s_id=:sid; ", 
            soci::into( m_optid),
            soci::into( m_opt_name ),
            soci::into( m_opttotal),
            soci::use( m_sid, "sid")  );

    }
    catch (std::exception const &e)
    {
        std::cerr << "Error: " << e.what() << '\n';
        throw e; 
    }
}

int64_t SGetSchemeNOptions::selectRows(LocalCaches::SSCHEME_OPTIONS* schemeOptions)
{
    cSchemeOptions SchemeOptions;
    optDetails topts;
    cSchemeOptions::OPTIONS_ID_PTS opts;
   
  try {
        m_sid=0;
        m_stSelectScheme.execute(true);
        do 
        {
            SchemeOptions.setSchemeID(m_sid);
            m_opttotal=0;
            SchemeOptions.setTotal(m_opttotal);
            SchemeOptions.setOptList(opts);
            
            SchemeOptions.setcreateTime(m_createtime);
            SchemeOptions.setendtime(m_endtime);

            (*schemeOptions)[m_schemename]=SchemeOptions;
        }  while (m_stSelectScheme.fetch());
        LocalCaches::SSCHEME_OPTIONS::iterator it = (*schemeOptions).begin();
        LocalCaches::SSCHEME_OPTIONS::iterator eit = (*schemeOptions).end();
        for (;it!=eit;++it)
        {
            m_sid=it->second.getSchemeID();
            opts.clear();
            m_stSelectOptions.execute(true);
            do 
            {
                topts.optId=m_optid;    
                topts.optPoints=m_opttotal;
                LOG(INFO) << "m_opt_name=" <<m_opt_name << " :m_optid=" << m_optid << " :m_sid=" << m_sid << std::endl;
                opts[m_opt_name]=topts;
                
            } while (m_stSelectOptions.fetch());
            (*schemeOptions)[it->first].setOptList(opts);
        }  

 
  }
    catch (std::exception const &e)
    {
        std::cerr << "Error: " << e.what() << '\n';
        throw e; 
    }
    return m_sid;
}

