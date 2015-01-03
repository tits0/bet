#ifndef PGDBCOMMON_H
#define PGDBCOMMON_H
#include <boost/shared_ptr.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <string>
#include "soci/core/soci.h"
#include <fstream>
#include "json/json.h"
#include "general_macros.h"
#include "error_codes.h"
#include "LocalCaches.h"

namespace soci{
class session;
class statement;
};


typedef std::vector< std::string > OPT_ARRAY;
class SCreateScheme {
    std::string m_schemename;
    int64_t     m_permission;
    std::tm     m_createtime; 
    std::tm     m_endtime ;
    int64_t     m_usercreated;
    int         m_optseq;
    //std::string    m_opt_name_01, m_opt_name_02, m_opt_name_03, m_opt_name_04, m_opt_name_05,
    //               m_opt_name_06, m_opt_name_07, m_opt_name_08, m_opt_name_09, m_opt_name_10,
    //               m_opt_name_11, m_opt_name_12, m_opt_name_13, m_opt_name_14, m_opt_name_15, 
    //               m_opt_name_16, m_opt_name_17, m_opt_name_18, m_opt_name_19, m_opt_name_20;
    std::string   m_opt_name[MAX_OPTS_BACCT];
    int64_t     m_opt[MAX_OPTS_BACCT];
    int64_t     m_placed_opt[MAX_OPTS_BACCT];
    int64_t     m_sid;
    int64_t     m_total;
    soci::session& m_sql;
    soci::statement m_stCreateScheme;
    soci::statement m_stCreateSchemeOptSumm;
    soci::indicator m_ind[MAX_OPTS_BACCT];
public:
    SCreateScheme(soci::session& sqlsession);
    
    ERROR_CODES_BACCT createRow(
        const std::string& schemename,
        int64_t permission,
        std::tm createtime, 
        std::tm endtime,
        int64_t usercreated, 
        OPT_ARRAY& options_arr,
        int64_t& sid
        );
    
};

class SCreateBet {
    int64_t  m_scheme_id;
    int64_t  m_opt_id;
    int64_t  m_userid;
    int64_t  m_approvedby;
    int64_t  m_points;
    std::tm  m_bettime;
    int64_t  m_curr_points; soci::indicator m_curr_points_ind;
    int64_t  m_curr_gain; soci::indicator m_curr_gain_ind;
    int64_t  m_curr_bonus; soci::indicator m_curr_bonus_ind;
    int64_t  m_curr_purchase; soci::indicator m_curr_purchase_ind;
    std::tm  m_curr_lastlogin; soci::indicator m_curr_lastlogin_ind;
    soci::session& m_sql;
    soci::statement m_stCreateBet;
    soci::statement m_stSelectUPoints;
    soci::statement m_stUpdateUPoints;
 
    boost::shared_ptr<soci::statement> m_stUpdateSumm[MAX_OPTS_BACCT];
    std::string m_update_scheme_option_summary ;
    std::string m_update_scheme_option_summary_where ;
    std::string m_ssql;    
    char m_seqbuffer[201];
public:
    SCreateBet(soci::session& sqlsession);
    
    ERROR_CODES_BACCT  createRow( const int64_t schemeid,
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


    int64_t  m_userid;
    int64_t  m_curr_points; soci::indicator m_curr_points_ind;
    int64_t  m_curr_gain; soci::indicator m_curr_gain_ind;
    int64_t  m_curr_bonus; soci::indicator m_curr_bonus_ind;
    int64_t  m_curr_purchase; soci::indicator m_curr_purchase_ind;
    std::tm  m_curr_lastlogin; soci::indicator m_curr_lastlogin_ind;

    soci::session&  m_sql;
    soci::statement m_stSUser;
    soci::statement m_stSelectUPoints;
    
public:
    SUser(soci::session& sqlsession);


inline int64_t  getUID() { return m_uid;}
ERROR_CODES_BACCT  getPoints(  
                    int64_t&  purchase,
                    int64_t&  bonus,
                    int64_t&  points,
                    int64_t&  gain,
                    std::tm&  lastlogintime,
                    const int64_t uid
                    );


ERROR_CODES_BACCT  createRow(  
                    const std::string&  username,
                    const std::string&  address,
                    const std::string&  pass,
                    const int64_t       points,
                    const int64_t       gain,
                    const std::tm      jointime,
                    const std::tm      lastlogintime,
                    int64_t & uid
                    );

};


class SGetSchemeNOptions {
    soci::session& m_sql;
    soci::statement m_stSelectScheme;
    soci::indicator m_ind[MAX_OPTS_BACCT];
    public:
    std::string m_schemename;
    int64_t     m_permission;
    std::tm     m_createtime; 
    std::tm     m_endtime ;
    int64_t     m_usercreated;
    int         m_optseq;
    std::string   m_opt_name[MAX_OPTS_BACCT];
    int64_t     m_opt[MAX_OPTS_BACCT];
    int64_t     m_placed_opt[MAX_OPTS_BACCT];
    int64_t     m_sid;
    int64_t     m_total;
public:
    SGetSchemeNOptions(soci::session& sqlsession);
    void test(void) { std::cout << " hello \n";  }
    int64_t selectRows(LocalCaches::SSCHEME_OPTIONS* schemeOptions);
    
};


class pgdbcommon
{
    boost::shared_ptr<soci::session> m_sqlptr;
    boost::shared_ptr<SCreateScheme> m_SCreateScheme;

    boost::shared_ptr<SCreateBet> m_SCreateBet;
    boost::shared_ptr<SFinalizeScheme> m_SFinalizeScheme;
    boost::shared_ptr<SUser>  m_SUser;
    boost::shared_ptr<SGetSchemeNOptions> m_SGetSchemeNOptions;
    std::ofstream m_logfile;
    
    static pgdbcommon* s_pgdbcommon;
    
    
    bool chkInit();
    void Init();
public:
    pgdbcommon();
    ~pgdbcommon();
    static pgdbcommon* GetInstance();
    
    ERROR_CODES_BACCT createInitialScheme();
    void Prepare();
    void exec(std::string& sql);

    

    ERROR_CODES_BACCT createScheme(const std::string& schemename,
                    int64_t  permission,
                    std::tm  createtime, 
                    std::tm  endtime,
                    int64_t  usercreated,
                    const Json::Value& opt_array,
                    int64_t&  sid
                    );

    ERROR_CODES_BACCT createSchemeOptions(const int64_t schemename,
                    const std::string&  optname);

    ERROR_CODES_BACCT createBet( const int64_t  schemeid,
                    const int64_t optid,
                    long        user,
                    long        approvedby,
                    long        points,
                    std::tm     bettime );


    ERROR_CODES_BACCT finalizeBet(const int64_t scheme_id,
                    const int64_t optionwon,
                    const int64_t optionofuser,
                    const int64_t user,
                    const int64_t pointsinvested,
                    const int64_t gain,
                    std::tm       finalizetime);

    ERROR_CODES_BACCT  createuser(
                    const std::string&  username,
                    const std::string&  address,
                    const std::string&  pass,
                    int64_t      points,
                    int64_t      gain,
                    std::tm      jointime,
                    std::tm      lastlogintime,
                    int64_t&     uid
                    );


    ERROR_CODES_BACCT getFullSchemeOptionNamesID(Json::Value& root);

};



class testpgdbcommon {
public:
Json::Value testparseJSON(std::string spjson);
Json::Value testBetparseJSON(std::string spjson);

ERROR_CODES_BACCT testCreateInitialScheme();
ERROR_CODES_BACCT testCreateScheme();
ERROR_CODES_BACCT testCreateBet();
ERROR_CODES_BACCT testGetSchemeOptList();
ERROR_CODES_BACCT testCreateUser();
ERROR_CODES_BACCT testFinalizeUser();
};

 
#endif // PGDBCOMMON_H
