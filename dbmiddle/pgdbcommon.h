#ifndef PGDBCOMMON_H
#define PGDBCOMMON_H
#include <boost/shared_ptr.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <string>
#include "soci/core/soci.h"
#include <fstream>
#include "json/json.h"
namespace soci{
class session;
class statement;
};

const unsigned int MAX_OPTS=20;

extern const char *UID_TAG ;    
extern const char *SESSION_TAG ;
extern const char *SCHEME_TAG ;
extern const char *OPTIONS_TAG ; 

typedef std::vector< std::string > OPT_ARRAY;
class SCreateScheme {
    std::string m_schemename;
    int64_t     m_permission;
    std::tm     m_createtime; 
    std::tm     m_endtime ;
    int64_t     m_usercreated;
    int m_optseq;
    //std::string    m_opt_name_01, m_opt_name_02, m_opt_name_03, m_opt_name_04, m_opt_name_05,
    //               m_opt_name_06, m_opt_name_07, m_opt_name_08, m_opt_name_09, m_opt_name_10,
    //               m_opt_name_11, m_opt_name_12, m_opt_name_13, m_opt_name_14, m_opt_name_15, 
    //               m_opt_name_16, m_opt_name_17, m_opt_name_18, m_opt_name_19, m_opt_name_20;
    std::string   m_opt_name[MAX_OPTS];
    int64_t     m_opt[MAX_OPTS];
    int64_t     m_placed_opt[MAX_OPTS];
    int64_t     m_sid;
    int64_t     m_total;
    soci::session& m_sql;
    soci::statement m_stCreateScheme;
    soci::statement m_stCreateSchemeOptSumm;
    soci::indicator m_ind[MAX_OPTS];
public:
    SCreateScheme(soci::session& sqlsession);
    
    void createRow(
        const std::string& schemename,
        int64_t permission,
        std::tm createtime, 
        std::tm endtime,
        int64_t usercreated, 
        OPT_ARRAY& options_arr
        );
    
};


class SCreateBet {
    int64_t  m_scheme_id;
    int64_t  m_opt_id; 
    int64_t  m_userid;
    int64_t  m_approvedby;
    int64_t  m_points;
    std::tm  m_bettime; 
    soci::session& m_sql;
    soci::statement m_stCreateBet;
public:
    SCreateBet(soci::session& sqlsession);
    
    void createRow( const int64_t schemeid,
                    const int64_t optid,
                    const int64_t user,
                    const int64_t approvedby,
                    const int64_t points,
                    std::tm     bettime );
    
};

class SFinalizeScheme {
    int64_t  m_scheme_id;
    int64_t  m_optionwon;
    int64_t  m_optionofuser;
    int64_t  m_userid;
    int64_t  m_pointsinvested;
    int64_t  m_gain;
    std::tm        m_finalizetime;

    soci::session&  m_sql;
    soci::statement m_stFinalizeScheme;
public:
    SFinalizeScheme(soci::session& sqlsession);
    
    void createRow( const int64_t schemename,
                    const int64_t optionwon,
                    const int64_t optionofuser,
                    const int64_t user,
                    const int64_t pointsinvested,
                    const int64_t gain,
                    std::tm       finalizetime);
    
};

class SUser {
    int64_t      m_uid;
    std::string  m_address;
    std::string  m_username;
    std::string  m_pass;
    int64_t      m_points;
    int64_t      m_gain;
    std::tm      m_jointime;
    std::tm      m_lastlogintime;

    soci::session&  m_sql;
    soci::statement m_stSUser;
public:
    SUser(soci::session& sqlsession);

inline int64_t  getUID() { return m_uid;}
int64_t  createRow(  
                    const std::string&  username,
                    const std::string&  address,
                    const std::string&  pass,
                    const int64_t       points,
                    const int64_t       gain,
                    const std::tm      jointime,
                    const std::tm      lastlogintime
                    );
};


class pgdbcommon
{
    boost::shared_ptr<soci::session> m_sqlptr;
    boost::shared_ptr<SCreateScheme> m_SCreateScheme;

    boost::shared_ptr<SCreateBet> m_SCreateBet;
    boost::shared_ptr<SFinalizeScheme> m_SFinalizeScheme;
    boost::shared_ptr<SUser>  m_SUser;
    std::ofstream m_logfile;
    
    static pgdbcommon* s_pgdbcommon;
    
    
    bool chkInit();
    void Init();
public:
    pgdbcommon();
    ~pgdbcommon();
    static pgdbcommon* GetInstance();
    
    void createInitialScheme();
    void Prepare();
    void exec(std::string& sql);

    void createScheme(const std::string& schemename,
                    int64_t  permission,
                    std::tm  createtime, 
                    std::tm  endtime,
                    int64_t  usercreated,
                    const Json::Value& opt_array
                    );

    void createSchemeOptions(const int64_t schemename,
                    const std::string&  optname);

    void createBet( const int64_t  schemeid,
                    const int64_t optid,
                    long        user,
                    long        approvedby,
                    long        points,
                    std::tm     bettime );


    void finalizeBet(const int64_t scheme_id,
                    const int64_t optionwon,
                    const int64_t optionofuser,
                    const int64_t user,
                    const int64_t pointsinvested,
                    const int64_t gain,
                    std::tm       finalizetime);

    int64_t   createuser(
                    const std::string&  username,
                    const std::string&  address,
                    const std::string&  pass,
                    const int64_t      points,
                    const int64_t      gain,
                    const std::tm      jointime,
                    const std::tm      lastlogintime
                    );


};

class testpgdbcommon {
public:
Json::Value testparseJSON(std::string spjson);
void testCreateInitialScheme();
void testCreateScheme();
};


#endif // PGDBCOMMON_H
