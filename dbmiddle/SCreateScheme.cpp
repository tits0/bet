#include "pgdbcommon.h"

SCreateScheme::SCreateScheme(soci::session& sqlsession):m_sql(sqlsession), m_stCreateScheme(m_sql) , 
m_stCreateSchemeOptSumm(m_sql)
{

   try{
        m_stCreateScheme = (m_sql.prepare << "insert into scheme ( scheme_name , permission , createtime , endtime , uid_created , \
       options, \
       opt_name_01 , opt_name_02 , opt_name_03 , opt_name_04 , opt_name_05 , opt_name_06 , opt_name_07 ,  opt_name_08,  opt_name_09, opt_name_10 , \
       opt_name_11 , opt_name_12, opt_name_13, opt_name_14, opt_name_15, opt_name_16, opt_name_17,  opt_name_18,  opt_name_19, opt_name_20) \
       values ( :schemename, :permission, :createtime, :endtime,  :usercreated, :options, \
       :opt_name_01, :opt_name_02, :opt_name_03, :opt_name_04, :opt_name_05, :opt_name_06, :opt_name_07, :opt_name_08, :opt_name_09, :opt_name_10 , \
       :opt_name_11, :opt_name_12, :opt_name_13, :opt_name_14, :opt_name_15, :opt_name_16, :opt_name_17,  :opt_name_18, :opt_name_19, :opt_name_20) returning s_id; " , 
        soci::use( m_schemename, "schemename") ,
        soci::use(m_permission, "permission"), 
        soci::use( m_createtime, "createtime" ), 
        soci::use( m_endtime, "endtime" ),
        soci::use(m_usercreated, "usercreated"), 
        soci::use(m_optseq, "options"),
        soci::use(m_opt_name[0], m_ind[0], "opt_name_01"),
        soci::use(m_opt_name[1], m_ind[1], "opt_name_02"),
        soci::use(m_opt_name[2], m_ind[2], "opt_name_03"),
        soci::use(m_opt_name[3], m_ind[3], "opt_name_04"),
        soci::use(m_opt_name[4], m_ind[4], "opt_name_05"),
        soci::use(m_opt_name[5], m_ind[5], "opt_name_06"),
        soci::use(m_opt_name[6], m_ind[6], "opt_name_07"),
        soci::use(m_opt_name[7], m_ind[7], "opt_name_08"),
        soci::use(m_opt_name[8], m_ind[8], "opt_name_09"),
        soci::use(m_opt_name[9], m_ind[9], "opt_name_10"),
        soci::use(m_opt_name[10], m_ind[10], "opt_name_11"),
        soci::use(m_opt_name[11], m_ind[11], "opt_name_12"),
        soci::use(m_opt_name[12], m_ind[12], "opt_name_13"),
        soci::use(m_opt_name[13], m_ind[13], "opt_name_14"),
        soci::use(m_opt_name[14], m_ind[14], "opt_name_15"),
        soci::use(m_opt_name[15], m_ind[15], "opt_name_16"),
        soci::use(m_opt_name[16], m_ind[16], "opt_name_17"),
        soci::use(m_opt_name[17], m_ind[17], "opt_name_18"),
        soci::use(m_opt_name[18], m_ind[18], "opt_name_19"),
        soci::use(m_opt_name[19], m_ind[19], "opt_name_20"),
        soci::into(m_sid) );

        m_stCreateSchemeOptSumm = (m_sql.prepare << "insert into scheme_option_summary( s_id, no_of_opts, \
        seq_01, seq_02, seq_03, \
        seq_04, seq_05, seq_06, seq_07, seq_08, seq_09, seq_10, \
        seq_11, seq_12, seq_13, seq_14, seq_15, seq_16, seq_17, \
        seq_18, seq_19, seq_20, \
        placed_seq_01, placed_seq_02, placed_seq_03, \
        placed_seq_04, placed_seq_05, placed_seq_06, placed_seq_07, placed_seq_08, placed_seq_09, placed_seq_10, \
        placed_seq_11, placed_seq_12, placed_seq_13, placed_seq_14, placed_seq_15, placed_seq_16, placed_seq_17, \
        placed_seq_18, placed_seq_19, placed_seq_20, \
        total ) values ( :sid, :options, \
       :opt_01, :opt_02, :opt_03, :opt_04, :opt_05, \
       :opt_06, :opt_07, :opt_08, :opt_09, :opt_10, \
       :opt_11, :opt_12, :opt_13, :opt_14, :opt_15, \
       :opt_16, :opt_17, :opt_18, :opt_19, :opt_20, \
       :placed_opt_01, :placed_opt_02, :placed_opt_03, :placed_opt_04, :placed_opt_05, \
       :placed_opt_06, :placed_opt_07, :placed_opt_08, :placed_opt_09, :placed_opt_10, \
       :placed_opt_11, :placed_opt_12, :placed_opt_13, :placed_opt_14, :placed_opt_15, \
       :placed_opt_16, :placed_opt_17,  :placed_opt_18, :placed_opt_19, :placed_opt_20, \
       :mtotal \
       ); " , 
        soci::use(m_sid, "sid"),
        soci::use(m_optseq, "options"),
        soci::use(m_opt[0], m_ind[0], "opt_01"),
        soci::use(m_opt[1], m_ind[1], "opt_02"),
        soci::use(m_opt[2], m_ind[2], "opt_03"),
        soci::use(m_opt[3], m_ind[3], "opt_04"),
        soci::use(m_opt[4], m_ind[4], "opt_05"),
        soci::use(m_opt[5], m_ind[5], "opt_06"),
        soci::use(m_opt[6], m_ind[6], "opt_07"),
        soci::use(m_opt[7], m_ind[7], "opt_08"),
        soci::use(m_opt[8], m_ind[8], "opt_09"),
        soci::use(m_opt[9], m_ind[9], "opt_10"),
        soci::use(m_opt[10], m_ind[10], "opt_11"),
        soci::use(m_opt[11], m_ind[11], "opt_12"),
        soci::use(m_opt[12], m_ind[12], "opt_13"),
        soci::use(m_opt[13], m_ind[13], "opt_14"),
        soci::use(m_opt[14], m_ind[14], "opt_15"),
        soci::use(m_opt[15], m_ind[15], "opt_16"),
        soci::use(m_opt[16], m_ind[16], "opt_17"),
        soci::use(m_opt[17], m_ind[17], "opt_18"),
        soci::use(m_opt[18], m_ind[18], "opt_19"),
        soci::use(m_opt[19], m_ind[19], "opt_20"),
        soci::use(m_placed_opt[0], m_ind[0], "placed_opt_01"),
        soci::use(m_placed_opt[1], m_ind[1], "placed_opt_02"),
        soci::use(m_placed_opt[2], m_ind[2], "placed_opt_03"),
        soci::use(m_placed_opt[3], m_ind[3], "placed_opt_04"),
        soci::use(m_placed_opt[4], m_ind[4], "placed_opt_05"),
        soci::use(m_placed_opt[5], m_ind[5], "placed_opt_06"),
        soci::use(m_placed_opt[6], m_ind[6], "placed_opt_07"),
        soci::use(m_placed_opt[7], m_ind[7], "placed_opt_08"),
        soci::use(m_placed_opt[8], m_ind[8], "placed_opt_09"),
        soci::use(m_placed_opt[9], m_ind[9], "placed_opt_10"),
        soci::use(m_placed_opt[10], m_ind[10], "placed_opt_11"),
        soci::use(m_placed_opt[11], m_ind[11], "placed_opt_12"),
        soci::use(m_placed_opt[12], m_ind[12], "placed_opt_13"),
        soci::use(m_placed_opt[13], m_ind[13], "placed_opt_14"),
        soci::use(m_placed_opt[14], m_ind[14], "placed_opt_15"),
        soci::use(m_placed_opt[15], m_ind[15], "placed_opt_16"),
        soci::use(m_placed_opt[16], m_ind[16], "placed_opt_17"),
        soci::use(m_placed_opt[17], m_ind[17], "placed_opt_18"),
        soci::use(m_placed_opt[18], m_ind[18], "placed_opt_19"),
        soci::use(m_placed_opt[19], m_ind[19], "placed_opt_20"),
        soci::use(m_total, "mtotal") );

        
    }
    catch (std::exception const &e)
    {
        std::cerr << "Error: " << e.what() << '\n';
        throw e; 
    }
}

int64_t  SCreateScheme::createRow(
        const std::string& schemename,
        int64_t permission,
        std::tm createtime, 
        std::tm endtime,
        int64_t usercreated, 
        OPT_ARRAY& options_arr
    )
{
    //createtime.tm_isdst=0;
    //endtime.tm_isdst=0;
       try{
            m_schemename = schemename;
            m_permission = permission;
            m_createtime = createtime;
            m_endtime    = endtime;
            m_usercreated = usercreated;
            if(options_arr.size()<MIN_OPTS_BACCT) {
                return -2;
            }
            if(options_arr.size()<2) {
                options_arr.resize(MAX_OPTS_BACCT);
            }
            OPT_ARRAY::iterator it=options_arr.begin();
            u_int i=0;
            for(;i<MAX_OPTS_BACCT;++i) {
                m_opt_name[i]="";
                m_ind[i] = soci::i_null;
                m_opt[i]=0;
                m_placed_opt[i]=0;
            }
            m_optseq=0;
            
            for(;it!=options_arr.end();++it) {
                m_opt_name[m_optseq]=*it;
                m_ind[m_optseq] = soci::i_ok;
                ++m_optseq;
            }
            m_total=0;
            
            m_stCreateScheme.execute(true);
            m_stCreateSchemeOptSumm.execute(true);
       }
        catch (std::exception const &e)
        {
            std::cerr << "Error: " << e.what() << '\n';
            throw e; 
        }
        return m_sid;
}

