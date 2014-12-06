#include "pgdbcommon.h"
#include "soci/backends/postgresql/soci-postgresql.h"

SCreateScheme::SCreateScheme(soci::session& sqlsession):m_sql(sqlsession), m_stCreateScheme(m_sql) 
{

   try{
        m_stCreateScheme = (m_sql.prepare <<
        "insert into betscheme ( schemename, permission, createtime, endtime, usercreated ) values ( :schemename, :permission, :createtime, :endtime,  :usercreated);" , 
        soci::use( m_schemename, "schemename") ,
        soci::use(m_permission, "permission"), 
        soci::use( m_createtime, "createtime" ), 
        soci::use( m_endtime, "endtime" ), 
        soci::use(m_usercreated, "usercreated")  );
        
    }
    catch (std::exception const &e)
    {
        std::cerr << "Error: " << e.what() << '\n';
        throw e; 
    }
}

void SCreateScheme::createRow(const std::string& schemename,
    long     permission,
    std::tm  createtime, 
    std::tm  endtime ,
    long     usercreated )
{
    //createtime.tm_isdst=0;
    //endtime.tm_isdst=0;
       try{
            m_schemename = schemename;
            m_permission = permission;
            m_createtime = createtime;
            m_endtime    = endtime;
            m_usercreated = usercreated;
            m_stCreateScheme.execute(true);
       }
        catch (std::exception const &e)
        {
            std::cerr << "Error: " << e.what() << '\n';
            throw e; 
        }
}


SCreateOptions::SCreateOptions(soci::session& sqlsession):m_sql(sqlsession), m_stCreateSchemeOptions(sqlsession)
{
    try
    {

    m_stCreateSchemeOptions =  (m_sql.prepare <<
        "insert into option( schemename , optionname )  \
       values ( :schemename, :optionname );" ,  
        soci::use(m_schemename, "schemename") , 
        soci::use(m_optname, "optionname") ) ;
    }
    catch (std::exception const &e)
    {
        std::cerr << "Error: " << e.what() << '\n';
        throw e; 
    }
}

void SCreateOptions::createRow(
    const std::string& schemename,
    const std::string& optname
)
{
    m_schemename = schemename;
    m_optname    = optname;
    m_stCreateSchemeOptions.execute(true);
}

SCreateBet::SCreateBet(soci::session& sqlsession):m_sql(sqlsession), m_stCreateBet(sqlsession)
{
    try
    {
        m_stCreateBet =  (m_sql.prepare <<
    "insert into bet( schemename , optionname, userid, approvedby, points , bettime ) \
    values ( :schemename, :optionname, :userid , :approvedby, :points, :bettime );" , 
    soci::use( m_schemename, "schemename"), 
    soci::use(m_optname, "optionname"), 
    soci::use(m_userid, "userid"), 
    soci::use(m_approvedby, "approvedby"),
    soci::use(m_points, "points"), 
    soci::use(m_bettime, "bettime") );
       }
        catch (std::exception const &e)
        {
            std::cerr << "Error: " << e.what() << '\n';
            throw e; 
        }
        
}    

void SCreateBet::createRow( const std::string& schemename,
                const std::string& optname,
                long        user,
                long        approvedby,
                long        points,
                std::tm     bettime )
{
    m_schemename = schemename;
    m_optname = optname;
    m_userid = user;
    m_approvedby  = approvedby;
    m_points = points;
    m_bettime = bettime;
    m_stCreateBet.execute(true);
    
}

SFinalizeScheme::SFinalizeScheme(soci::session& sqlsession):m_sql(sqlsession), m_stFinalizeScheme(sqlsession)
{

    try
    {
    m_stFinalizeScheme =  (m_sql.prepare <<
    "insert into finalizebet( schemename , \
      optionwon , optionofuser , userid , \
      pointsinvested, gain , finalizetime ) \
    values ( :schemename, :optionwon, :optionofuser, :userid, :pointsinvested, :gain, :finalizetime );" , 
    soci::use( m_schemename, "schemename"), 
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
    
void SFinalizeScheme::createRow( const std::string&  schemename,
                    const std::string&  optionwon,
                    const std::string&  optionofuser,
                    long          user,
                    long          pointsinvested,
                    long          gain,
                    std::tm       finalizetime)
{
    m_schemename = schemename;
    m_optionwon = optionwon;
    m_optionofuser = optionofuser;
    m_userid = user;
    m_pointsinvested = pointsinvested;
    m_gain = gain;
    m_finalizetime = finalizetime;
    m_stFinalizeScheme.execute(true);
                        
}
    


SUser::SUser(soci::session& sqlsession):m_sql(sqlsession), m_stSUser(sqlsession)
{

    try
    {
    m_stSUser =  (m_sql.prepare <<
    "insert into user( userid , username , pass , points , gain , jointime , lastlogintime ) \
       values ( :userid , :username , :pass , :points , :gain , :jointime , :lastlogintime);" , 
        soci::use( m_userid, "userid"), 
        soci::use( m_username, "username"), 
        soci::use( m_pass, "pass"), 
        soci::use( m_points, "points"), 
        soci::use( m_gain, "gain"),
        soci::use(m_jointime, "jointime"), 
        soci::use(m_lastlogintime, "lastlogintime") ) ;
       }
       catch (std::exception const &e)
       {
            std::cerr << "Error: " << e.what() << '\n';
            throw e; 
       }
        
}
    
void SUser::createRow( const long      userid,
                    const std::string  username,
                    const std::string  address,
                    const std::string  pass,
                    const long         points,
                    const long         gain,
                    const std::tm      jointime,
                    const std::tm      lastlogintime
                    )
{
    m_userid=userid;
    m_username=username;
    m_pass=pass;
    m_points=points;
    m_gain=gain;
    m_jointime=jointime;
    m_lastlogintime=lastlogintime;
    m_stSUser.execute(true);
}

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

pgdbcommon::pgdbcommon():m_sqlptr(new soci::session(soci::postgresql, "dbname=accountdb")),
m_SCreateScheme(*(m_sqlptr.get())),
m_SCreateOptions(  *(m_sqlptr.get())), 
m_SCreateBet(*(m_sqlptr.get())), 
m_SFinalizeScheme(*(m_sqlptr.get())),
m_SUser(*(m_sqlptr.get()))
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
      sql << "create table user( u_id bigint auto, points numeric, name varchar, joindate timestamp, lastlogin timestamp);" ;
      sql << "create table scheme( s_id bigint auto, schemename varchar, permission integer, createtime timestamp, endtime timestamp, uid_created bigint);" ;
      sql << "create table schemearchive( s_id bigint, s_name varchar, s_permission integer, createtime timestamp, endtime timestamp, uid_created bigint, archivetime timestamp );" ;
      
      sql << "create table option( opt_id bigint auto, schemeid bigint, opt_name varchar, optseq);" ;
      sql << "create table optionarchive( opt_id bigint, schemename varchar, option_name varchar, archivetime timestamp );" ;

      sql << "create table scheme_option_summary( s_id bigint, no_of_opts int \
                  seq1 bigint, seq2 bigint, seq3 bigint, \
                  seq4 bigint, seq5 bigint, seq6 bigint, seq7 bigint, seq8 bigint, seq9 bigint, seq10 bigint, \
                  seq11 bigint, seq12 bigint, seq13 bigint, seq14 bigint, seq15 bigint, seq16 bigint, seq17 bigint, \
                  seq18 bigint, seq19 bigint, seq20 bigint, \
                  placed_seq1 bigint, placed_seq2 bigint, placed_seq3 bigint, \
                  placed_seq4 bigint, placed_seq5 bigint, placed_seq6 bigint, placed_seq7 bigint, placed_seq8 bigint, placed_seq9 bigint, placed_seq10 bigint, \
                  placed_seq11 bigint, placed_seq12 bigint, placed_seq13 bigint, placed_seq14 bigint, placed_seq15 bigint, placed_seq16 bigint, placed_seq17 bigint, \
                  placed_seq18 bigint, placed_seq19 bigint, placed_seq20 bigint, \
                  total number);" ;
       //gain_1 = (total-seq1)
       //gain_1 = (total-seq1) opt_id1_1/seq1
 
      sql << "create table u_scheme_option_summary( u_id bigint, s_id bigint, \
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
                  total bigint);" ;


      sql << "create table  bet( s_id bigint, opt_id bigint, u_id bigint,  points bigint,\
        bettime timestamp );" ;
        
      sql << "create table  bet_archive( s_id bigint, opt_id bigint, u_id bigint, points bigint,\
        bettime timestamp, archivetime timestamp );" ;

      sql << "create table finalizebet( schemename varchar, \
      optionwon varchar, optionofuser varchar, userid bigint, \
      pointsinvested bigint, gain bigint, finalizetime timestamp );" ;
      
    }
    catch (std::exception const &e)
    {
        std::cerr << "Error: " << e.what() << '\n';
    }    
}



void pgdbcommon::createScheme(const std::string& schemename,
                long     permission,
                std::tm  createtime, 
                std::tm  endtime ,
                long     usercreated )
{
    try
    {
        m_SCreateScheme.createRow(schemename,
                    permission,
                    createtime, 
                    endtime ,
                    usercreated );

    }
    catch (std::exception const &e)
    {
        std::cerr << "Error: " << e.what() << '\n';
        throw e; 
    }

}

void pgdbcommon::createSchemeOptions(const std::string& schemename,
                const std::string&  optname)
{
    try
    {
        m_SCreateOptions.createRow( schemename,
                            optname);

    }
    catch (std::exception const &e)
    {
        std::cerr << "Error: " << e.what() << '\n';
        throw e; 
    }

}

void pgdbcommon::createBet( const std::string& schemename,
                const std::string& optname,
                long        user,
                long        approvedby,
                long        points,
                std::tm     bettime )
{
    try
    {
        m_SCreateBet.createRow(schemename,
                optname,
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
}


void pgdbcommon::finalizeBet( const std::string&  schemename,
                const std::string&  optionwon,
                const std::string&  optionofuser,
                long          user,
                long          pointsinvested,
                long          gain,
                std::tm       finalizetime)
{
    try
    {
        m_SFinalizeScheme.createRow(schemename, 
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

void pgdbcommon::createuser( const long   userid,
                    const std::string  username,
                    const std::string  address,
                    const std::string  pass,
                    const long         points,
                    const long         gain,
                    const std::tm      jointime,
                    const std::tm      lastlogintime
                    )

{
    try
    {
        
       m_SUser.createRow( userid,
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
}


void testpgdbcommon::testCreateScheme() {
    pgdbcommon* pPgdbcommon  =   pgdbcommon::GetInstance();
 
    boost::posix_time::ptime createdTime = boost::posix_time::second_clock::universal_time();
    std::cout << "createdTime:" << createdTime << std::endl;
    boost::posix_time::ptime endtimecal(createdTime);
    std::cout << "endtimecal date:" << endtimecal << std::endl;
    endtimecal = endtimecal +  boost::gregorian::days(0) + boost::posix_time::hours(1);
    std::cout << "endtimecal date+hour:" << endtimecal << std::endl;

    std::cout << "endtimecal:" << endtimecal << std::endl;
    
    std::string schemename="s1";
    pPgdbcommon->createScheme((std::string&)schemename, (long)1, 
    boost::posix_time::to_tm(createdTime), boost::posix_time::to_tm(endtimecal) , 1);
}
