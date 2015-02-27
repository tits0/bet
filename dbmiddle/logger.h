#ifndef LOGGER_H
#define LOGGER_H

#include "easylogging++.h"

using namespace el;
using namespace el::base;
using namespace el::base::utils;

class logger
{
    static logger* ms_instance;
    el::Configurations m_conf;
    
private:
    logger(const logger& rhs);
    logger& operator=(const logger& rhs);
    int Init();
    void Dump();
public:
    static logger* Instance();
    static void Release();
    
private:
    logger();
    ~logger();

};

#endif // LOGGER_H
