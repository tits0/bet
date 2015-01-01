#include "ConfigLocal.h"

#include <iostream>
#include <fstream>
ConfigLocal* ConfigLocal::ms_instance = 0;

ConfigLocal::ConfigLocal()
{
    m_joinBonus=1000;
    m_logBonus=50;
}

ConfigLocal::~ConfigLocal()
{
}

ConfigLocal* ConfigLocal::Instance()
{
    if (ms_instance == 0) {
        ms_instance = new ConfigLocal();
    }
    return ms_instance;
}

void ConfigLocal::Release()
{
    if (ms_instance) {
        delete ms_instance;
    }
    ms_instance = 0;
}

void ConfigLocal::readConfigFile()
{
    const char* filename="config.txt";
    // jsonJson::Reader  
    Json::Reader reader;  
    // Json::Value??int, string, object, array...  

    std::ifstream is;
    is.open (filename, std::ios::binary );
    if (reader.parse(is, this->m_confJson))  {
        // ?Return the member named key if it exist, defaultValue otherwise.  
        m_joinBonus = this->m_confJson.get("join_bonus", 1000).asInt();
        m_logBonus  = this->m_confJson.get("log_bonus", 50).asInt();
    }
    is.close();  
    return ;  
}
