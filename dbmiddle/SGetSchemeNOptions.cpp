#include "pgdbcommon.h"

SGetSchemeNOptions::SGetSchemeNOptions(soci::session& sqlsession):m_sql(sqlsession), m_stSelectScheme(m_sql) 
{
   try{
        m_stSelectScheme = (m_sql.prepare << "select s_id, scheme_name, permission, createtime, endtime, uid_created, \
            options, \
            opt_name_01, opt_name_02, opt_name_03, opt_name_04, opt_name_05, \
            opt_name_06, opt_name_07,  opt_name_08,  opt_name_09, opt_name_10, \
            opt_name_11, opt_name_12, opt_name_13, opt_name_14, opt_name_15, \
            opt_name_16, opt_name_17,  opt_name_18,  opt_name_19, opt_name_20 \
            from scheme ; ", 
            soci::into(m_sid),
            soci::into( m_schemename),
            soci::into(m_permission), 
            soci::into( m_createtime ), 
            soci::into( m_endtime ),
            soci::into(m_usercreated), 
            soci::into(m_optseq),
            soci::into(m_opt_name[0], m_ind[0]),
            soci::into(m_opt_name[1], m_ind[1]),
            soci::into(m_opt_name[2], m_ind[2]),
            soci::into(m_opt_name[3], m_ind[3]),
            soci::into(m_opt_name[4], m_ind[4]),
            soci::into(m_opt_name[5], m_ind[5]),
            soci::into(m_opt_name[6], m_ind[6]),
            soci::into(m_opt_name[7], m_ind[7]),
            soci::into(m_opt_name[8], m_ind[8]),
            soci::into(m_opt_name[9], m_ind[9]),
            soci::into(m_opt_name[10], m_ind[10]),
            soci::into(m_opt_name[11], m_ind[11]),
            soci::into(m_opt_name[12], m_ind[12]),
            soci::into(m_opt_name[13], m_ind[13]),
            soci::into(m_opt_name[14], m_ind[14]),
            soci::into(m_opt_name[15], m_ind[15]),
            soci::into(m_opt_name[16], m_ind[16]),
            soci::into(m_opt_name[17], m_ind[17]),
            soci::into(m_opt_name[18], m_ind[18]),
            soci::into(m_opt_name[19], m_ind[19]) );
    }
    catch (std::exception const &e)
    {
        std::cerr << "Error: " << e.what() << '\n';
        throw e; 
    }
}

int64_t SGetSchemeNOptions::selectRows(LocalCaches::SSCHEME_OPTIONS* schemeOptions)
{
    cSchemeOptions t;
    optDetails topts;
    cSchemeOptions::OPTIONS_ID_PTS opts;
   
  try{
        m_stSelectScheme.execute(true);
        do 
        {
            for(int i=0; i< m_optseq;++i) {
                topts.optId=i;
                topts.optPoints=m_opt[i];
                opts[m_opt_name[i]]=topts;
            }
            t.setSchemeID(m_sid);
            t.setTotal(m_total);
            t.setOptList(opts);
            
            t.setcreateTime(m_createtime);
            t.setendtime(m_endtime);

            (*schemeOptions)[m_schemename]=t;
        }  while (m_stSelectScheme.fetch());
   }
    catch (std::exception const &e)
    {
        std::cerr << "Error: " << e.what() << '\n';
        throw e; 
    }
    return m_sid;
}

