#include "pgdbcommon.h"
#include "soci/backends/postgresql/soci-postgresql.h"
#include "general_macros.h"
#include "error_codes.h"
#include "ConfigLocal.h"


   
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


ERROR_CODES_BACCT pgdbcommon::createInitialScheme()
{
    soci::session& sql = *m_sqlptr.get();
    try
    {
        
      sql << "DROP TABLE IF EXISTS u_table CASCADE;";
      sql << "create table IF NOT EXISTS  u_table ( u_id bigserial, u_idc varchar NOT NULL, points bigint NOT NULL, \
        gain bigint NOT NULL DEFAULT 0, bonus bigint NOT NULL DEFAULT 0, purchase bigint NOT NULL DEFAULT 0, \
        name varchar NOT NULL, namev varchar NOT NULL, joindate timestamp NOT NULL, lastlogin timestamp NOT NULL);" ;
        
      sql << "DROP TABLE IF EXISTS scheme CASCADE;";
      sql << "create table IF NOT EXISTS scheme( s_id bigserial, scheme_name varchar NOT NULL, permission integer, \
        createtime timestamp NOT NULL, endtime timestamp NOT NULL, uid_created bigint NOT NULL, \
       options integer DEFAULT 0, \
       opt_name_01 varchar NOT NULL, opt_name_02 varchar NOT NULL, opt_name_03 varchar, opt_name_04 varchar, opt_name_05 varchar, opt_name_06 varchar, opt_name_07 varchar,  opt_name_08 varchar,  opt_name_09 varchar,   opt_name_10 varchar, \
       opt_name_11 varchar, opt_name_12 varchar, opt_name_13 varchar, opt_name_14 varchar, opt_name_15 varchar, opt_name_16 varchar, opt_name_17 varchar,  opt_name_18 varchar,  opt_name_19 varchar,   opt_name_20 varchar, \
       isarchived smallint \
       );" ;
      
      sql << "DROP TABLE  IF EXISTS schemearchive CASCADE;";
      sql << "create table IF NOT EXISTS schemearchive( LIKE scheme );" ;

      sql << "DROP TABLE  IF EXISTS scheme_option_summary CASCADE;";
      sql << "create table IF NOT EXISTS scheme_option_summary( s_id bigint, no_of_opts int NOT NULL, \
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
      
      sql << "DROP TABLE IF EXISTS bet CASCADE;";
      sql << "create table IF NOT EXISTS bet( s_id bigint NOT NULL, opt_id bigint NOT NULL, u_id bigint NOT NULL,  points bigint NOT NULL,\
        bettime timestamp NOT NULL);" ;

      sql << "DROP TABLE IF EXISTS bonus CASCADE;";
      sql << "create table IF NOT EXISTS bonus( u_id bigint NOT NULL,  points bigint NOT NULL,\
        btime timestamp NOT NULL);" ;
        
        
      sql << "DROP TABLE IF EXISTS bet_archive CASCADE;";
      sql << "create table IF NOT EXISTS  bet_archive( LIKE scheme );" ;
       

      sql << "DROP TABLE IF EXISTS finalizebet CASCADE;";
      sql << "create table IF NOT EXISTS finalizebet( s_id bigint NOT NULL, \
      opt_won bigint NOT NULL, \
      finalizetime timestamp NOT NULL);" ;
      
      m_SCreateScheme.reset( new SCreateScheme(*m_sqlptr.get() ) );
      
      m_SCreateBet.reset( new SCreateBet(*m_sqlptr.get() ) );
      m_SFinalizeScheme.reset(new SFinalizeScheme(*m_sqlptr.get()) ); 
      m_SUser.reset( new SUser(*m_sqlptr.get()) );
      m_SGetSchemeNOptions.reset( new SGetSchemeNOptions(*m_sqlptr.get()) );
      
    }
    catch (std::exception const &e)
    {
        std::cerr << "Error: " << e.what() << '\n';
        return ERROR_OTHER;
    }    
    return ERROR_OK;
}
     

ERROR_CODES_BACCT pgdbcommon::createScheme(
        const std::string& schemename,
        int64_t  permission,
        std::tm  createtime, 
        std::tm  endtime,
        int64_t  usercreated,
        const Json::Value& opt_array,
        int64_t&  sid)
{
    ERROR_CODES_BACCT ret = ERROR_OK;
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
                    optarr,
                    sid);

    }
    catch (std::exception const &e)
    {
        std::cerr << "Error: " << e.what() << '\n';
        throw e; 
    }

    return ret;
}


ERROR_CODES_BACCT pgdbcommon::createBet( 
    const int64_t  scheme_id,
    const int64_t opt_id,
    long        user,
    long        approvedby,
    long        points,
    std::tm     bettime )
{
    ERROR_CODES_BACCT ret=ERROR_OTHER;
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
        ret=ERROR_OTHER; 
    }
    return ret;
}


ERROR_CODES_BACCT pgdbcommon::finalizeBet(
        const int64_t scheme_id,
        const int64_t optionwon,
        std::tm       finalizetime
        )
{
    ERROR_CODES_BACCT ret=ERROR_OTHER;
    try
    {
        ret=m_SFinalizeScheme->createRow(scheme_id, 
                optionwon,
                finalizetime);
        
    }
    catch (std::exception const &e)
    {
        std::cerr << "Error: " << e.what() << '\n';
        ret=ERROR_FINALIZE_FAILED; 
    }
    return ret;
}

ERROR_CODES_BACCT  pgdbcommon::createuser( 
                    const std::string&  username,
                    const std::string&  address,
                    const std::string&  pass,
                    int64_t      points,
                    int64_t      gain,
                    std::tm      jointime,
                    std::tm      lastlogintime,
                    int64_t&      uid
                    )
{
    ERROR_CODES_BACCT ret = ERROR_CODES_BACCT::ERROR_USER_CREATION_FAILED;
    try
    {
        
    points = ConfigLocal::Instance()->m_joinBonus;
    gain=0;
    ret = m_SUser->createRow(
                    username,
                    address,
                    pass,
                    points,
                    gain,
                    jointime,
                    lastlogintime,
                    uid);
    }
    catch (std::exception const &e)
    {
        std::cerr << "Error: " << e.what() << '\n';
        
    }
    return ret;
}

ERROR_CODES_BACCT pgdbcommon::getFullSchemeOptionNamesID(Json::Value& root) {

   ERROR_CODES_BACCT ret=ERROR_OTHER ;
   try
    {
        LocalCaches::SSCHEME_OPTIONS schemeOptions;
        m_SGetSchemeNOptions->test();
        m_SGetSchemeNOptions->selectRows(&schemeOptions);
        LocalCaches *pCache =LocalCaches::Instance();
        pCache->setFullSchemeOptionNamesIDMap(schemeOptions);   
        pCache->getFullSchemeOptionNamesID(root);
        ret=ERROR_OK;
    }
    catch (std::exception const &e)
    {
        std::cerr << "Error: " << e.what() << '\n';
        throw e; 
    }
    return ret;
}