#ifndef CONFIGLOCAL_H
#define CONFIGLOCAL_H
#include "json/json.h"

class ConfigLocal
{
    Json::Value m_confJson;
    static ConfigLocal* ms_instance;
private:
    ConfigLocal(const ConfigLocal& rhs);
    ConfigLocal& operator=(const ConfigLocal& rhs);
    
public:
    int m_joinBonus;
    int m_logBonus;
    void readConfigFile();
    inline const Json::Value& getVal() const {return m_confJson;}
    static ConfigLocal* Instance();
    static void Release();

private:
    ConfigLocal();
    ~ConfigLocal();

};

#endif // CONFIGLOCAL_H
