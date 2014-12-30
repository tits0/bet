#include "LocalCaches.h"
#include "json/json.h"
#include "general_macros.h"

#include "boost/date_time/posix_time/posix_time.hpp" ///include all types plus i/o

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

void cSchemeOptions::getOptList( Json::Value& jopts) {
    
    OPTIONS_ID_PTS::iterator it = m_options.begin();
    Json::Value topts;
   
    for(;it != m_options.end(); it++) {
        topts[OPTION_PTS_BACCT]=(Json::Int64)it->second.optPoints;
        topts[OPTION_ID_TAG_BACCT]= (Json::Int64)it->second.optId;
        jopts[it->first]=topts;
    }
    return ;
}

void LocalCaches::getFullSchemeOptionNamesID(Json::Value& root) {
   SSCHEME_OPTIONS::iterator it = m_Scheme2IDAndOptions2ID.begin();
   root.clear();
   Json::Value tid;
   Json::Value toptsList;
    for(;it != m_Scheme2IDAndOptions2ID.end(); it++) {
        it->second.getOptList(toptsList);
        tid[OPTION_LIST_BACCT]=toptsList;
        tid[SCHEME_ID_TAG_BACCT]=(Json::Int64)it->second.getSchemeID();
        tid[SCHEME_TOTAL_TAG_BACCT]=(Json::Int64)it->second.getTotal();
        boost::posix_time::ptime pt = boost::posix_time::ptime_from_tm(it->second.getcreateTime());
        tid[SCHEME_START_TAG_BACCT]=boost::posix_time::to_iso_extended_string(pt);
        pt = boost::posix_time::ptime_from_tm(it->second.getendtime());
        tid[SCHEME_END_TAG_BACCT]=boost::posix_time::to_iso_extended_string(pt);
        root[it->first]=tid;
    }
}

void LocalCaches::setFullSchemeOptionNamesID(std::string& schemename, int64_t sid, cSchemeOptions::OPTIONS_ID_PTS& opts) {
    cSchemeOptions t;
    t.setSchemeID(sid);
    t.setOptList(opts);
    m_Scheme2IDAndOptions2ID[schemename]=t;
}


void LocalCaches::setFullSchemeOptionNamesIDMap(SSCHEME_OPTIONS& scheme2IDAndOptions2ID) {
    m_Scheme2IDAndOptions2ID.insert(scheme2IDAndOptions2ID.begin(), scheme2IDAndOptions2ID.end());
}
