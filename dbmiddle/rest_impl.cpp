#include "RestAPI.h"


Json::Value RestAPI::testparseJSON(std::string spjson) {
    Json::Reader reader;
    Json::Value root;
    bool parsingSuccessful = false;
    if (false == (parsingSuccessful = reader.parse (spjson, root)))
    {
        std::cerr<<"\nFailed to parse configuration:"
        <<reader.getFormatedErrorMessages ();
        return 0;
    }
    return root;
}

ERROR_CODES_BACCT RestAPI::createScheme(const Json::Value& input, Json::Value& root)
{
    pgdbcommon* pPgdbcommon = pgdbcommon::GetInstance();
 
    boost::posix_time::ptime createdTime = boost::posix_time::second_clock::universal_time();
    std::cout << "createdTime:" << createdTime << std::endl;
    boost::posix_time::ptime endtimecal(createdTime);
    std::cout << "endtimecal date:" << endtimecal << std::endl;
    endtimecal = endtimecal +  boost::gregorian::days(0) + boost::posix_time::hours(1);
    std::cout << "endtimecal date+hour:" << endtimecal << std::endl;

    std::cout << "endtimecal:" << endtimecal << std::endl;
    
    Json::Value optdata ;
    Json::Value schemenameVal;
    std::string schemename;
    ERROR_CODES_BACCT ret = ERROR_OTHER;
    optdata = this->testparseJSON(input);
    schemenameVal = optdata[SCHEME_TAG_BACCT];
    schemename=schemenameVal.asString();
    int64_t sid;
    ret = pPgdbcommon->createScheme((std::string&)schemename, (long)1, 
    boost::posix_time::to_tm(createdTime), boost::posix_time::to_tm(endtimecal) , 1, optdata[OPTIONS_TAG_BACCT], sid);
    std::cout << map_error((ERROR_CODES_BACCT)ret) << std::endl;
    
    optdata = this->testparseJSON(sjson_1);
    schemenameVal = optdata[SCHEME_TAG_BACCT];
    schemename=schemenameVal.asString();
    ret = pPgdbcommon->createScheme((std::string&)schemename, (long)1, 
    boost::posix_time::to_tm(createdTime), boost::posix_time::to_tm(endtimecal) , 1, optdata[OPTIONS_TAG_BACCT], sid );
    std::cout << map_error((ERROR_CODES_BACCT)ret)  << std::endl;
    std::cout << "test.testCreateInitialScheme():" << schemename << ":" << map_error(ret) <<  std::endl;

    optdata = this->testparseJSON(sjson_2);
    schemenameVal = optdata[SCHEME_TAG_BACCT];
    schemename=schemenameVal.asString();
    ret = pPgdbcommon->createScheme((std::string&)schemename, (long)1, 
    boost::posix_time::to_tm(createdTime), boost::posix_time::to_tm(endtimecal) , 1, optdata[OPTIONS_TAG_BACCT], sid );
    std::cout << map_error((ERROR_CODES_BACCT)ret) << std::endl;
    std::cout << "test.testCreateInitialScheme():" << schemename << ":" << map_error(ret) <<  std::endl;
    
    return ERROR_CODES_BACCT::ERROR_OK;
}

ERROR_CODES_BACCT RestAPI::createBet(Json::Value& root)
{
    
    return ERROR_CODES_BACCT::ERROR_OK;
}

ERROR_CODES_BACCT RestAPI::getFullSchemeOptionNamesID(Json::Value& root)
{
    
    return ERROR_CODES_BACCT::ERROR_OK;
}

ERROR_CODES_BACCT RestAPI::getPoints(Json::Value& root)
{
    
    return ERROR_CODES_BACCT::ERROR_OK;
}
