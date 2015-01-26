#include "RestAPI.h"


Json::Value RestAPI::testparseJSON(const char* spjson) {
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

ERROR_CODES_BACCT RestAPI::createScheme(const char* input, Json::Value& root)
{
    pgdbcommon* pPgdbcommon = pgdbcommon::GetInstance();
 
    boost::posix_time::ptime createdTime = boost::posix_time::second_clock::universal_time();
    std::cout << "createdTime:" << createdTime << std::endl;
    boost::posix_time::ptime endtimecal(createdTime);

    std::cout << "endtimecal:" << endtimecal << std::endl;
    
    Json::Value optdata ;
    Json::Value schemenameVal;
    std::string schemename;
    ERROR_CODES_BACCT ret = ERROR_OTHER;
    optdata = this->testparseJSON(input);
    schemenameVal = optdata[SCHEME_TAG_BACCT];
    int idays = optdata[SCHEME_DAYS_BACCT].asInt();
    int hrs = optdata[SCHEME_HRS_BACCT].asInt();
    
    endtimecal = endtimecal +  boost::gregorian::days(idays) + boost::posix_time::hours(hrs);
    std::cout << "endtimecal date+hour:" << endtimecal << std::endl;

    schemename=schemenameVal.asString();
    int64_t sid;
    ret = pPgdbcommon->createScheme((std::string&)schemename, (long)0/*permission*/, 
    boost::posix_time::to_tm(createdTime), boost::posix_time::to_tm(endtimecal), 0/*approver*/, optdata[OPTIONS_TAG_BACCT], sid);
    std::cout << map_error((ERROR_CODES_BACCT)ret) << std::endl;
    
    return ERROR_CODES_BACCT::ERROR_OK;
}

ERROR_CODES_BACCT RestAPI::createBet(const char* input, Json::Value& root)
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
    ERROR_CODES_BACCT ret = ERROR_OTHER;
    optdata = this->testparseJSON(input);

    Json::Value schemeIdVal = optdata[SCHEME_ID_TAG_BACCT];
    Json::Value optidVal = optdata[OPTION_ID_TAG_BACCT]; 
    Json::Value userVal = optdata[UID_TAG_BACCT]; 
    Json::Value  pointsVal = optdata[BET_POINTS_TAG_BACCT]; 
    
    int64_t scheme_id=schemeIdVal.asInt64();
    int64_t opt_id =optidVal.asInt64();
    int64_t user = userVal.asInt64();
    int64_t approvedby = 0;
    long   points = pointsVal.asInt64();
    std::tm bettime = boost::posix_time::to_tm(endtimecal);
    ret = pPgdbcommon->createBet( 
     scheme_id,
    opt_id,
    user,
    approvedby,
    points,
    bettime );
    
    return ERROR_CODES_BACCT::ERROR_OK;
}

ERROR_CODES_BACCT RestAPI::getFullSchemeOptionNamesID(const char* input, Json::Value& root)
{
    pgdbcommon* pPgdbcommon = pgdbcommon::GetInstance();
 
    boost::posix_time::ptime createdTime = boost::posix_time::second_clock::universal_time();
    std::cout << "createdTime:" << createdTime << std::endl;
    boost::posix_time::ptime endtimecal(createdTime);
    std::cout << "endtimecal date:" << endtimecal << std::endl;
    endtimecal = endtimecal +  boost::gregorian::days(0) + boost::posix_time::hours(1);
    std::cout << "endtimecal date+hour:" << endtimecal << std::endl;

    std::cout << "endtimecal:" << endtimecal << std::endl;
    
    ERROR_CODES_BACCT ret = ERROR_OTHER;
    ret = pPgdbcommon->getFullSchemeOptionNamesID(root);

    std::cout << " Full scheme:options" << root  << std::endl;
    
    return ret ;
    
}

ERROR_CODES_BACCT RestAPI::getPoints(const char* input, Json::Value& root)
{
    return ERROR_CODES_BACCT::ERROR_OK;
}


ERROR_CODES_BACCT RestAPI::createUser(const char* input, Json::Value& root)
{
    return ERROR_CODES_BACCT::ERROR_OK;
}

//ERROR_CODES_BACCT RestAPI::x(const char* input, Json::Value& root)
//{
//    return ERROR_CODES_BACCT::ERROR_OK;
//}

