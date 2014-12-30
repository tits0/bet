#ifndef LOCALCACHES_H
#define LOCALCACHES_H

#include  <unordered_map>
#include  <map>
#include  <ctime>
#include "json/json.h"

class cOptions {
  typedef std::map<int,bool> OPTIONS;
  std::map<int,bool>  m_options;
  public:
  inline bool getOpt(int i) {
      OPTIONS::iterator it=m_options.find(i);
      if(it==m_options.end()) {
          return false;
      }
      return true;
    }
  inline void setOpt(int i) {
      m_options[i]=true;
    }
    
};

struct optDetails{
  int64_t  optId;
  int64_t  optPoints;
};

/// /class cSchemeOptions .
///
/// This class maintains a map between options str -> optionid int
/// for a given scheme.Italso holds the scheme id
///
class cSchemeOptions {
public:
  typedef std::map<std::string, optDetails> OPTIONS_ID_PTS;
protected:
    OPTIONS_ID_PTS m_options;
    int64_t  m_schemeid;
    int64_t  m_total;
    std::tm  m_createtime; 
    std::tm  m_endtime ;
  
public:
  inline int64_t getSchemeID() {return m_schemeid;} 
  inline void setSchemeID(int64_t id) {m_schemeid=id;} 
  inline void setTotal(int64_t total) {m_total=total;} 
  inline int64_t getTotal() { return m_total;} 

  inline void setcreateTime(std::tm t) {m_createtime=t;} 
  inline std::tm getcreateTime() { return m_createtime;} 

  inline void setendtime(std::tm t) {m_endtime=t;} 
  inline std::tm getendtime() { return m_endtime;} 
  
  /// This method returns list of options in Json::Value format 
  /// Json::Value is an out parameter
  /// 
  void getOptList(Json::Value& jopts);
  inline optDetails* getOpt(std::string& s) {
      OPTIONS_ID_PTS::iterator it=m_options.find(s);
      if(it==m_options.end()) {
          return nullptr;
      }
      return &it->second;
    }
  inline void setOpt(std::string& s, optDetails p) {
      m_options[s]=p;
    }
  inline void setOptList(OPTIONS_ID_PTS& p) {
      m_options.insert(p.begin(), p.end()) ;
    }
    
};


class LocalCaches
{
public:
    typedef std::unordered_map<int64_t, cOptions> SCHEME_OPTIONS;
    typedef std::unordered_map<std::string, cSchemeOptions> SSCHEME_OPTIONS;
    static LocalCaches* ms_instance;

protected:
    LocalCaches(const LocalCaches& rhs);
    LocalCaches& operator=(const LocalCaches& rhs);

public:
    static LocalCaches* Instance();
    static void Release();
    
    ///
    /// This is a helper function
    /// Get the option list for a schme id INT
    /// Note:otion list is in inte too
    ///
    inline cOptions* getSchemeIDOptionIDList(int64_t scheme_id ) {
       SCHEME_OPTIONS::iterator it = m_SchemeOptions.find(scheme_id);
       if (it==m_SchemeOptions.end())
           return nullptr;
       return &it->second;
    }

    ///
    /// check if integer  scheme id and integer option id are valid
    /// @returns True if they are still availaible or false
    ///
    inline bool VeryfySchemeIDOptionID(int64_t scheme_id, int64_t opt_id) {
        cOptions* popt = getSchemeIDOptionIDList(scheme_id);
        if(popt==nullptr) {
            return false;
        }
        return popt->getOpt(opt_id);
    }


    ///
    /// given schemename returns pointer to object cSchemeOptions
    /// cSchemeOptions contains the names of options and id
    /// @returns pointer to object cSchemeOptions
    ///
    inline cSchemeOptions* getSchemeDetails(std::string& schemename) {
       SSCHEME_OPTIONS::iterator it = m_Scheme2IDAndOptions2ID.find(schemename);
       if (it==m_Scheme2IDAndOptions2ID.end())
           return nullptr;
       return &it->second;
    }

    ///
    /// @returns json of schmes , options and thier ids 
    ///
    void getFullSchemeOptionNamesID(Json::Value& root);

    ///
    /// set all of schmes , options and thier ids 
    ///
    void setFullSchemeOptionNamesID(std::string& schemename, int64_t sid, cSchemeOptions::OPTIONS_ID_PTS& opts);
    void setFullSchemeOptionNamesIDMap(SSCHEME_OPTIONS& scheme2IDAndOptions2ID);
private:
    SCHEME_OPTIONS m_SchemeOptions; ///schame id int, option list [integer id ]
    SSCHEME_OPTIONS m_Scheme2IDAndOptions2ID; ///schame name str , cSchemeOptions[id , options]
    LocalCaches();
    ~LocalCaches();

};

#endif // LOCALCACHES_H
