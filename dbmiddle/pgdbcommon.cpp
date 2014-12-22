#include "pgdbcommon.h"
#include "soci/backends/postgresql/soci-postgresql.h"
#include "general_macros.h"
#include "error_codes.h"


   
pgdbcommon* pgdbcommon::s_pgdbcommon=0;

pgdbcommon* pgdbcommon::GetInstance()
{
    if(s_pgdbcommon==0) {
        try {
            s_pgdbcommon=new pgdbcommon();
            s_pgdbcommon->Init();
        }
        catch (std::exception const &e)
        {
            std::cerr << "Error: " << e.what() << '\n';
            delete s_pgdbcommon;
            s_pgdbcommon=0;
            throw e;
        }
        
    }
    return s_pgdbcommon;
}

pgdbcommon::pgdbcommon():m_sqlptr(new soci::session(soci::postgresql, "dbname=accountdb"))
{
   m_logfile.open("dblog.log");
   m_sqlptr->set_log_stream(&m_logfile);
}

pgdbcommon::~pgdbcommon()
{
}

void pgdbcommon::Init()
{
    try
    {
        //m_sqlptr = boost::shared_ptr<soci::session>(new soci::session(soci::postgresql, "dbname=accountdb"));
    }
    catch (std::exception const &e)
    {
        std::cerr << "Error: " << e.what() << '\n';
        throw e; 
    }
}

bool pgdbcommon::chkInit()
{
    if(m_sqlptr.get()==0) {
        return false;
    } 
    return true;
}


void pgdbcommon::createInitialScheme()
{
    soci::session& sql = *m_sqlptr.get();
    try
    {
      sql << "DROP TABLE  IF EXISTS u_table  CASCADE;";
      sql << "create table  IF NOT EXISTS  u_table ( u_id bigserial, u_idc varchar, points bigint, gain bigint, name varchar, namev varchar, joindate timestamp, lastlogin timestamp);" ;
      sql << "DROP TABLE  IF EXISTS scheme  CASCADE;";
      sql << "create table IF NOT EXISTS scheme( s_id bigserial, scheme_name varchar, permission integer, createtime timestamp, endtime timestamp, uid_created bigint, \
       options integer ,\
       opt_name_01 varchar, opt_name_02 varchar, opt_name_03 varchar, opt_name_04 varchar, opt_name_05 varchar, opt_name_06 varchar, opt_name_07 varchar,  opt_name_08 varchar,  opt_name_09 varchar,   opt_name_10 varchar, \
       opt_name_11 varchar, opt_name_12 varchar, opt_name_13 varchar, opt_name_14 varchar, opt_name_15 varchar, opt_name_16 varchar, opt_name_17 varchar,  opt_name_18 varchar,  opt_name_19 varchar,   opt_name_20 varchar );" ;
      
      sql << "DROP TABLE  IF EXISTS schemearchive CASCADE;";
      sql << "create table IF NOT EXISTS schemearchive( s_id bigint, scheme_name varchar, permission integer, createtime timestamp, endtime timestamp, uid_created bigint, archivetime timestamp );" ;

      sql << "DROP TABLE  IF EXISTS scheme_option_summary CASCADE;";
      sql << "create table IF NOT EXISTS scheme_option_summary( s_id bigint, no_of_opts int, \
                  seq_01 bigint, seq_02 bigint, seq_03 bigint, \
                  seq_04 bigint, seq_05 bigint, seq_06 bigint, seq_07 bigint, seq_08 bigint, seq_09 bigint, seq_10 bigint, \
                  seq_11 bigint, seq_12 bigint, seq_13 bigint, seq_14 bigint, seq_15 bigint, seq_16 bigint, seq_17 bigint, \
                  seq_18 bigint, seq_19 bigint, seq_20 bigint, \
                  placed_seq_01 bigint, placed_seq_02 bigint, placed_seq_03 bigint, \
                  placed_seq_04 bigint, placed_seq_05 bigint, placed_seq_06 bigint, placed_seq_07 bigint, placed_seq_08 bigint, placed_seq_09 bigint, placed_seq_10 bigint, \
                  placed_seq_11 bigint, placed_seq_12 bigint, placed_seq_13 bigint, placed_seq_14 bigint, placed_seq_15 bigint, placed_seq_16 bigint, placed_seq_17 bigint, \
                  placed_seq_18 bigint, placed_seq_19 bigint, placed_seq_20 bigint, \
                  total numeric);" ;
       //gain_1 = (total-seq1)
       //gain_1 = (total-seq1) opt_id1_1/seq1
 
      sql << "DROP TABLE IF EXISTS u_scheme_option_summary CASCADE;";
      sql << "create table IF NOT EXISTS u_scheme_option_summary( u_id bigint, s_id bigint, \
                  sid_1 bigint, opts_1 int,\
                  opt_id1_1 bigint, opt_id1_2 bigint, opt_id1_3 bigint, \
                  opt_id1_4 bigint, opt_id1_5 bigint,  \
                  opt_gain_id1_1 bigint, opt_gain_id1_2 bigint, opt_gain_id1_3 bigint, \
                  opt_gain_id1_4 bigint, opt_gain_id1_5 bigint,  \
                  total_1 bigint, total_gain_1 bigint, \
                  sid_2 bigint, opts_2 int, \
                  opt_id2_1 bigint, opt_id2_2 bigint, opt_id2_3 bigint, \
                  opt_id2_4 bigint, opt_id2_5 bigint,  \
                  opt_gain_id2_1 bigint, opt_gain_id2_2 bigint, opt_gain_id2_3 bigint, \
                  opt_gain_id2_4 bigint, opt_gain_id2_5 bigint,  \
                  total_2 bigint, total_gain_2 bigint, \
                  sid_3 bigint, opts_3 int, \
                  opt_id3_1 bigint, opt_id3_2 bigint, opt_id3_3 bigint, \
                  opt_id3_4 bigint, opt_id3_5 bigint,  \
                  opt_gain_id3_1 bigint, opt_gain_id3_2 bigint, opt_gain_id3_3 bigint, \
                  opt_gain_id3_4 bigint, opt_gain_id3_5 bigint,  \
                  total_3 bigint, total_gain_3 bigint, \
                  sid_4 bigint, opts_4 int, \
                  opt_id4_1 bigint, opt_id4_2 bigint, opt_id4_3 bigint, \
                  opt_id4_4 bigint, opt_id4_5 bigint,  \
                  opt_gain_id4_1 bigint, opt_gain_id4_2 bigint, opt_gain_id4_3 bigint, \
                  opt_gain_id4_4 bigint, opt_gain_id4_5 bigint,  \
                  total_4 bigint, total_gain_4 bigint, \
                  sid_5 bigint, opts_5 int, \
                  opt_id5_1 bigint, opt_id5_2 bigint, opt_id5_3 bigint, \
                  opt_id5_4 bigint, opt_id5_5 bigint,  \
                  opt_gain_id5_1 bigint, opt_gain_id5_2 bigint, opt_gain_id5_3 bigint, \
                  opt_gain_id5_4 bigint, opt_gain_id5_5 bigint,  \
                  total_5 bigint , total_gain_5 bigint, \
                  sid_6 bigint, opts_6 int, \
                  opt_id6_1 bigint, opt_id6_2 bigint, opt_id6_3 bigint, \
                  opt_id6_4 bigint, opt_id6_5 bigint,  \
                  opt_gain_id6_1 bigint, opt_gain_id6_2 bigint, opt_gain_id6_3 bigint, \
                  opt_gain_id6_4 bigint, opt_gain_id6_5 bigint,  \
                  total_6 bigint, total_gain_6 bigint, \
                  sid_7 bigint, opts_7 int, \
                  opt_id7_1 bigint, opt_id7_2 bigint, opt_id7_3 bigint, \
                  opt_id7_4 bigint, opt_id7_5 bigint,  \
                  opt_gain_id7_1 bigint, opt_gain_id7_2 bigint, opt_gain_id7_3 bigint, \
                  opt_gain_id7_4 bigint, opt_gain_id7_5 bigint,  \
                  total_7 bigint, total_gain_7 bigint, \
                  sid_8 bigint, opts_8 int, \
                  opt_id8_1 bigint, opt_id8_2 bigint, opt_id8_3 bigint, \
                  opt_id8_4 bigint, opt_id8_5 bigint,  \
                  opt_gain_id8_1 bigint, opt_gain_id8_2 bigint, opt_gain_id8_3 bigint, \
                  opt_gain_id8_4 bigint, opt_gain_id8_5 bigint,  \
                  total_8 bigint, total_gain_8 bigint, \
                  sid_9 bigint, opts_9 int, \
                  opt_id9_1 bigint, opt_id9_2 bigint, opt_id9_3 bigint, \
                  opt_id9_4 bigint, opt_id9_5 bigint,   \
                  opt_gain_id9_1 bigint, opt_gain_id9_2 bigint, opt_gain_id9_3 bigint, \
                  opt_gain_id9_4 bigint, opt_gain_id9_5 bigint,  \
                  total_9 bigint, total_gain_9 bigint, \
                  sid_10 bigint, opts_10 int, \
                  opt_id10_1 bigint, opt_id10_2 bigint, opt_id10_3 bigint, \
                  opt_id10_4 bigint, opt_id10_5 bigint, \
                  opt_gain_id10_1 bigint, opt_gain_id10_2 bigint, opt_gain_id10_3 bigint, \
                  opt_gain_id10_4 bigint, opt_gain_id10_5 bigint,  \
                  total_10 bigint, total_gain_10 bigint, \
                  total numeric);" ;


      sql << "DROP TABLE IF EXISTS bet CASCADE;";
      sql << "create table  IF NOT EXISTS bet( s_id bigint, opt_id bigint, u_id bigint,  points bigint,\
        bettime timestamp );" ;
        
      sql << "DROP TABLE IF EXISTS bet_archive CASCADE;";
      sql << "create table IF NOT EXISTS  bet_archive( s_id bigint, opt_id bigint, u_id bigint, points bigint,\
        bettime timestamp, archivetime timestamp );" ;

      sql << "DROP TABLE IF EXISTS finalizebet CASCADE;";
      sql << "create table IF NOT EXISTS finalizebet( s_id bigint, \
      opt_won bigint, opt_of_user bigint, u_id bigint, \
      points_invested bigint, gain bigint, finalizetime timestamp );" ;
      
      m_SCreateScheme.reset( new SCreateScheme(*m_sqlptr.get() ) );
      
      m_SCreateBet.reset( new SCreateBet(*m_sqlptr.get() ) );
      m_SFinalizeScheme.reset(new SFinalizeScheme(*m_sqlptr.get()) ); 
      m_SUser.reset( new SUser(*m_sqlptr.get()) );
      
    }
    catch (std::exception const &e)
    {
        std::cerr << "Error: " << e.what() << '\n';
    }    
}

int64_t pgdbcommon::createScheme(
        const std::string& schemename,
        int64_t  permission,
        std::tm  createtime, 
        std::tm  endtime,
        int64_t  usercreated,
        const Json::Value& opt_array)
{
    int64_t ret = ERROR_OK;
    try
    {
        OPT_ARRAY optarr;
        for(unsigned int j=0; j< opt_array.size(); j++) {
            if(j>=MAX_OPTS_BACCT) 
                break;
            optarr.push_back(opt_array[j].asString()) ;
        }     
        ret = m_SCreateScheme->createRow(schemename,
                    permission,
                    createtime,
                    endtime ,
                    usercreated, 
                    optarr);

    }
    catch (std::exception const &e)
    {
        std::cerr << "Error: " << e.what() << '\n';
        throw e; 
    }

    return ret;
}


int pgdbcommon::createBet( 
    const int64_t  scheme_id,
    const int64_t opt_id,
    long        user,
    long        approvedby,
    long        points,
    std::tm     bettime )
{
    int ret=ERROR_OTHER;
    try
    {
        ret=m_SCreateBet->createRow(scheme_id,
                opt_id,
                user,
                approvedby,
                points,
                bettime );

    }
    catch (std::exception const &e)
    {
        std::cerr << "Error: " << e.what() << '\n';
        throw e; 
    }
    return ret;
}


void pgdbcommon::finalizeBet(
        const int64_t scheme_id,
        const int64_t optionwon,
        const int64_t optionofuser,
        const int64_t user,
        const int64_t pointsinvested,
        const int64_t gain,
        std::tm       finalizetime
        )
{
    try
    {
        m_SFinalizeScheme->createRow(scheme_id, 
                optionwon,
                optionofuser,
                user,
                pointsinvested,
                gain,
                finalizetime);
    }
    catch (std::exception const &e)
    {
        std::cerr << "Error: " << e.what() << '\n';
        throw e; 
    }
}

int64_t  pgdbcommon::createuser( 
                    const std::string&  username,
                    const std::string&  address,
                    const std::string&  pass,
                    const int64_t      points,
                    const int64_t      gain,
                    const std::tm      jointime,
                    const std::tm      lastlogintime
                    )

{
    try
    {
        
       m_SUser->createRow( 
                    username,
                    address,
                    pass,
                    points,
                    gain,
                    jointime,
                    lastlogintime);
        
    }
    catch (std::exception const &e)
    {
        std::cerr << "Error: " << e.what() << '\n';
        throw e; 
    }
    return m_SUser->getUID();
}


