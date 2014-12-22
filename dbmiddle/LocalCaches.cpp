#include "LocalCaches.h"

LocalCaches* LocalCaches::ms_instance = 0;

LocalCaches::LocalCaches()
{
}

LocalCaches::~LocalCaches()
{
}

LocalCaches* LocalCaches::Instance()
{
    if (ms_instance == 0) {
        ms_instance = new LocalCaches();
    }
    return ms_instance;
}

void LocalCaches::Release()
{
    if (ms_instance) {
        delete ms_instance;
    }
    ms_instance = 0;
}

