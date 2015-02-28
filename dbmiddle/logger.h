#ifndef LOGGER_H
#define LOGGER_H

#include "easylogging++.h"

/*
INFO (LOG_INFO)
DEBUG (LOG_DEBUG)
WARNING (LOG_WARNING)
ERROR (LOG_ERR)
FATAL (LOG_EMERG)
*/

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
public:
    static logger* Instance();
    static void Release();
    int Dump();
    
private:
    logger();
    ~logger();

};

#endif // LOGGER_H
