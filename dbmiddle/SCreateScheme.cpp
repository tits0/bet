#include "pgdbcommon.h"

SCreateScheme::SCreateScheme(soci::session& sqlsession):m_sql(sqlsession), m_stCreateScheme(m_sql) , 
m_stInsertOpt(m_sql)
{

   try{
       m_stCreateScheme = (m_sql.prepare << "INSERT into scheme ( scheme_name, permission, createtime, endtime, uid_created, options) \
       values ( :schemename, :permission, :createtime, :endtime, :usercreated, :options) returning s_id; " , 
        soci::use( m_schemename, "schemename") ,
        soci::use(m_permission, "permission"), 
        soci::use( m_createtime, "createtime" ), 
        soci::use( m_endtime, "endtime" ),
        soci::use(m_usercreated, "usercreated"), 
        soci::use(m_optseq, "options"),
        soci::into(m_sid) );

      m_stInsertOpt = ( m_sql.prepare << "INSERT into options  (s_id, opt_id, opt_name, opttotal) \
      values ( :schemeid, :optid, :optname, :total);",
      soci::use(m_sid, "schemeid"),
      soci::use(m_optseq, "optid"), 
      soci::use(m_optname, "optname"), 
      soci::use(m_total, "total") );

        
    }
    catch (std::exception const &e)
    {
        std::cerr << "Error: " << e.what() << '\n';
        throw e; 
    }
}

ERROR_CODES_BACCT  SCreateScheme::createRow(
        const std::string& schemename,
        int64_t permission,
        std::tm createtime, 
        std::tm endtime,
        int64_t usercreated, 
        OPT_ARRAY& options_arr,
        int64_t& sid
    )
{
    ERROR_CODES_BACCT ret=ERROR_CODES_BACCT::ERROR_OK;
    //createtime.tm_isdst=0;
    //endtime.tm_isdst=0;
    //
       try{
            m_schemename = schemename;
            m_permission = permission;
            m_createtime = createtime;
            m_endtime    = endtime;
            m_usercreated = usercreated;
            if(options_arr.size()<MIN_OPTS_BACCT) {
                return ERROR_MIN_OPTS_FOR_SCHEME;
            }
            soci::transaction tr(m_sql);

            OPT_ARRAY::iterator it=options_arr.begin();
            u_int i=0;
            m_optseq=options_arr.size();
            m_total=0;
            m_stCreateScheme.execute(true);
            m_optseq=1;
            for(;it!=options_arr.end();++it) {
                m_optname=*it;
                m_stInsertOpt.execute(true);
                ++m_optseq;
            }
            tr.commit();

       }
        catch (std::exception const &e)
        {
            std::cerr << "Error: " << e.what() << '\n';
            ret=ERROR_CODES_BACCT::ERROR_SCHEME_CREATION_FAILED; 
        }
        sid=m_sid;
        return ret;
}

