#ifndef PGDBCOMMON_H
#define PGDBCOMMON_H
#include <boost/shared_ptr.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <string>
#include "soci/core/soci.h"
#include <fstream>

namespace soci{
class session;
class statement;
};

class SCreateScheme {
    std::string m_schemename;
    long        m_permission;
    std::tm     m_createtime; 
    std::tm     m_endtime ;
    long        m_usercreated;
    soci::session& m_sql;
    soci::statement m_stCreateScheme;
public:
    SCreateScheme(soci::session& sqlsession);
    
    void createRow(const std::string& schemename,
                    long     permission,
                    std::tm  createtime, 
                    std::tm  endtime ,
                    long     usercreated );
    
};

class SCreateOptions {
    std::string  m_schemename;
    std::string  m_optname; 
    soci::session& m_sql;
    soci::statement m_stCreateSchemeOptions;
public:
    SCreateOptions(soci::session& sqlsession);
    void createRow(const std::string& schemename,
                    const std::string&  optname);
    
};

class SCreateBet {
    std::string  m_schemename;
    std::string  m_optname; 
    long         m_userid;
    long         m_approvedby;
    long         m_points;
    std::tm      m_bettime; 
    
    soci::session& m_sql;
    soci::statement m_stCreateBet;
public:
    SCreateBet(soci::session& sqlsession);
    
    void createRow( const std::string& schemename,
                    const std::string& optname,
                    long        user,
                    long        approvedby,
                    long        points,
                    std::tm     bettime );
    
};

class SFinalizeScheme {
    std::string  m_schemename;
    std::string  m_optionwon;
    std::string  m_optionofuser;
    long         m_userid;
    long         m_pointsinvested;
    long         m_gain;
    std::tm      m_finalizetime;

    soci::session&  m_sql;
    soci::statement m_stFinalizeScheme;
public:
    SFinalizeScheme(soci::session& sqlsession);
    
    void createRow( const std::string&  schemename,
                    const std::string&  optionwon,
                    const std::string&  optionofuser,
                    long          user,
                    long          pointsinvested,
                    long          gain,
                    std::tm       finalizetime);
    
};


class SUser {
    long         m_userid;
    std::string  m_username;
    std::string  m_pass;
    long         m_points;
    long         m_gain;
    std::tm      m_jointime;
    std::tm      m_lastlogintime;

    soci::session&  m_sql;
    soci::statement m_stSUser;
public:
    SUser(soci::session& sqlsession);
    
void    createRow( const long      userid,
                    const std::string  username,
                    const std::string  address,
                    const std::string  pass,
                    const long         points,
                    const long         gain,
                    const std::tm      jointime,
                    const std::tm      lastlogintime
                    );
};


class pgdbcommon
{
    boost::shared_ptr<soci::session> m_sqlptr;
    SCreateScheme m_SCreateScheme;
    SCreateOptions m_SCreateOptions;
    SCreateBet m_SCreateBet;
    SFinalizeScheme m_SFinalizeScheme;
    SUser  m_SUser;
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
                    long     permission,
                    std::tm  createtime, 
                    std::tm  endtime ,
                    long     usercreated );

    void createSchemeOptions(const std::string& schemename,
                    const std::string&  optname);

    void createBet( const std::string& schemename,
                    const std::string& optname,
                    long        user,
                    long        approvedby,
                    long        points,
                    std::tm     bettime );


    void finalizeBet( const std::string&  schemename,
                    const std::string&  optionwon,
                    const std::string&  optionofuser,
                    long          user,
                    long          pointsinvested,
                    long          gain,
                    std::tm       finalizetime);

    void    createuser( const long   userid,
                    const std::string  username,
                    const std::string  address,
                    const std::string  pass,
                    const long         points,
                    const long         gain,
                    const std::tm      jointime,
                    const std::tm      lastlogintime
                    );


};

class testpgdbcommon {
    public:
void testCreateScheme();
};


#endif // PGDBCOMMON_H
