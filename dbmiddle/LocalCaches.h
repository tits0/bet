#ifndef LOCALCACHES_H
#define LOCALCACHES_H

#include  <unordered_map>
#include  <map>

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

class LocalCaches
{
    typedef std::unordered_map<int64_t, cOptions> SCHEME_OPTIONS;
    static LocalCaches* ms_instance;

private:
    LocalCaches(const LocalCaches& rhs);
    LocalCaches& operator=(const LocalCaches& rhs);

public:
    static LocalCaches* Instance();
    static void Release();
    
    inline bool getScheme(int64_t scheme_id,  cOptions*& opts ) {
       SCHEME_OPTIONS::iterator it = m_SchemeOptions.find(scheme_id);
       if (it==m_SchemeOptions.end())
           return false;
        opts=&it->second;
        return true;
    }
private:
    SCHEME_OPTIONS m_SchemeOptions;
    LocalCaches();
    ~LocalCaches();

};

#endif // LOCALCACHES_H
