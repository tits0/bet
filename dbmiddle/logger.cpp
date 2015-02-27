#include "logger.h"

logger* logger::ms_instance = 0;

INITIALIZE_EASYLOGGINGPP


int logger::Init()
{
    el::Configurations c("log.conf", false, nullptr);
    m_conf.setFromBase(&c);
    // Values are always std::string

    // default logger uses default configurations
    el::Loggers::reconfigureLogger("default", m_conf);
    LOG(INFO) << "Log using default file";
    el::Loggers::reconfigureLogger("default", m_conf);
    return 0;
}

int logger::Dump()
{
    m_conf.setFromBase(&c);
    // Values are always std::string

    LOG(INFO) << "Log using default file";
    return 0;
}


logger::logger()
{
    
}

logger::~logger()
{
}

logger* logger::Instance()
{
    if (ms_instance == 0) {
        ms_instance = new logger();
        ms_instance->Init();
    }
    return ms_instance;
}

void logger::Release()
{
    if (ms_instance) {
        delete ms_instance;
    }
    ms_instance = 0;
}

