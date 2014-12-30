
#include "pgdbcommon.h"
#include "general_macros.h"

const char* sjson_0="{\"uid\":12345567, \"session\":\"7654321\" , \"scheme\":\"s1\", \"options\":[] }";
const char* sjson_1="{\"uid\":12345567, \"session\":\"7654321\" , \"scheme\":\"s2\", \"options\":[\"opt1\"] }";
const char* sjson_2="{\"uid\":12345567, \"session\":\"7654321\" , \"scheme\":\"s3\", \"options\":[\"opt1\", \"opt2\"] }";
const char* sjson_20="{\"uid\":12345567, \"session\":\"7654321\" , \"scheme\":\"s4\", \"options\":[\"opt1\", \"opt2\", \"opt3\", \"opt4\", \"opt5\", \
 \"opt6\", \"opt7\", \"opt8\", \"opt9\", \"opt10\", \"opt11\", \"opt12\", \"opt13\", \"opt14\", \"opt15\", \"opt16\", \"opt17\", \"opt18\", \"opt19\", \
 \"opt20\"] }";

const char* sjson_22="{\"uid\":12345567, \"session\":\"7654321\" , \"scheme\":\"s5\", \"options\":[\"opt1\", \"opt2\", \"opt3\", \"opt4\", \"opt5\", \
 \"opt6\", \"opt7\", \"opt8\", \"opt9\", \"opt10\", \"opt11\", \"opt12\", \"opt13\", \"opt14\", \"opt15\", \"opt16\", \"opt17\", \"opt18\", \"opt19\", \
 \"opt20\", \"opt21\", \"opt22\"] }";


const char* sjson_bet_100="{\"uid\":12345567, \"session\":\"7654321\" , \"schid\":1 , \"optid\":1, \"betpt\":100 }";

Json::Value testpgdbcommon::testparseJSON(std::string spjson) {
    Json::Reader reader;
    Json::Value root;
    bool parsingSuccessful = false;
    if (false == (parsingSuccessful = reader.parse (spjson, root)))
    {
        std::cerr<<"\nFailed to parse configuration:"
        <<reader.getFormatedErrorMessages ();
        return 0;
    }
    Json::Value uid = root.get (UID_TAG_BACCT,0);    
    Json::Value session = root.get (SESSION_TAG_BACCT,0);
    Json::Value scheme = root.get (SCHEME_TAG_BACCT,0);
    Json::Value options = root.get (OPTIONS_TAG_BACCT,0); 
    return root;
}

Json::Value testpgdbcommon::testBetparseJSON(std::string spjson) {
    Json::Reader reader;
    Json::Value root;
    bool parsingSuccessful = false;
    if (false == (parsingSuccessful = reader.parse (spjson, root)))
    {
        std::cerr<<"\nFailed to parse configuration:"
        <<reader.getFormatedErrorMessages ();
        return 0;
    }
    Json::Value uid = root.get (UID_TAG_BACCT,0);
    Json::Value session = root.get (SESSION_TAG_BACCT,0);
    Json::Value scheme = root.get (SCHEME_ID_TAG_BACCT,0);
    Json::Value options = root.get (OPTION_ID_TAG_BACCT,0); 
    Json::Value pts = root.get (BET_POINTS_TAG_BACCT,0); 
    return root;
}



//Test creating db scheme .

void testpgdbcommon::testCreateInitialScheme() {
    pgdbcommon* pPgdbcommon  =  pgdbcommon::GetInstance();
 
    boost::posix_time::ptime createdTime = boost::posix_time::second_clock::universal_time();
    std::cout << "createdTime:" << createdTime << std::endl;
    boost::posix_time::ptime endtimecal(createdTime);
    std::cout << "endtimecal date:" << endtimecal << std::endl;
    endtimecal = endtimecal +  boost::gregorian::days(0) + boost::posix_time::hours(1);
    std::cout << "endtimecal date+hour:" << endtimecal << std::endl;

    std::cout << "endtimecal:" << endtimecal << std::endl;
    
    pPgdbcommon->createInitialScheme();
}

//Test creating scheme with options
void testpgdbcommon::testCreateScheme() {
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
    int64_t ret = ERROR_OTHER;
    optdata = this->testparseJSON(sjson_0);
    schemenameVal = optdata[SCHEME_TAG_BACCT];
    schemename=schemenameVal.asString();
    ret = pPgdbcommon->createScheme((std::string&)schemename, (long)1, 
    boost::posix_time::to_tm(createdTime), boost::posix_time::to_tm(endtimecal) , 1, optdata[OPTIONS_TAG_BACCT] );
    std::cout << map_error((ERROR_CODES_BACCT)ret) << std::endl;
    
    optdata = this->testparseJSON(sjson_1);
    schemenameVal = optdata[SCHEME_TAG_BACCT];
    schemename=schemenameVal.asString();
    ret = pPgdbcommon->createScheme((std::string&)schemename, (long)1, 
    boost::posix_time::to_tm(createdTime), boost::posix_time::to_tm(endtimecal) , 1, optdata[OPTIONS_TAG_BACCT] );
    std::cout << map_error((ERROR_CODES_BACCT)ret)  << std::endl;

    optdata = this->testparseJSON(sjson_2);
    schemenameVal = optdata[SCHEME_TAG_BACCT];
    schemename=schemenameVal.asString();
    ret = pPgdbcommon->createScheme((std::string&)schemename, (long)1, 
    boost::posix_time::to_tm(createdTime), boost::posix_time::to_tm(endtimecal) , 1, optdata[OPTIONS_TAG_BACCT] );
    std::cout << map_error((ERROR_CODES_BACCT)ret) << std::endl;

    optdata = this->testparseJSON(sjson_20);
    schemenameVal = optdata[SCHEME_TAG_BACCT];
    schemename=schemenameVal.asString();
    ret = pPgdbcommon->createScheme((std::string&)schemename, (long)1, 
    boost::posix_time::to_tm(createdTime), boost::posix_time::to_tm(endtimecal) , 1, optdata[OPTIONS_TAG_BACCT] );
    std::cout << map_error((ERROR_CODES_BACCT)ret)  << std::endl;

    optdata = this->testparseJSON(sjson_22);
    schemenameVal = optdata[SCHEME_TAG_BACCT];
    schemename=schemenameVal.asString();
    ret = pPgdbcommon->createScheme((std::string&)schemename, (long)1, 
    boost::posix_time::to_tm(createdTime), boost::posix_time::to_tm(endtimecal) , 1, optdata[OPTIONS_TAG_BACCT] );
    std::cout << map_error((ERROR_CODES_BACCT)ret)  << std::endl;
}


//Test creating bet 
void testpgdbcommon::testCreateBet() {
    pgdbcommon* pPgdbcommon = pgdbcommon::GetInstance();
 
    boost::posix_time::ptime createdTime = boost::posix_time::second_clock::universal_time();
    std::cout << "createdTime:" << createdTime << std::endl;
    boost::posix_time::ptime endtimecal(createdTime);
    std::cout << "endtimecal date:" << endtimecal << std::endl;
    endtimecal = endtimecal +  boost::gregorian::days(0) + boost::posix_time::hours(1);
    std::cout << "endtimecal date+hour:" << endtimecal << std::endl;

    std::cout << "endtimecal:" << endtimecal << std::endl;
    
    Json::Value optdata ;
    int64_t ret = ERROR_OTHER;
    optdata = this->testBetparseJSON(sjson_bet_100);

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
    
    std::cout << map_error((ERROR_CODES_BACCT)ret) << std::endl;


}


//Test get scheme & option list 
void testpgdbcommon::testGetSchemeOptList() {
    pgdbcommon* pPgdbcommon = pgdbcommon::GetInstance();
 
    boost::posix_time::ptime createdTime = boost::posix_time::second_clock::universal_time();
    std::cout << "createdTime:" << createdTime << std::endl;
    boost::posix_time::ptime endtimecal(createdTime);
    std::cout << "endtimecal date:" << endtimecal << std::endl;
    endtimecal = endtimecal +  boost::gregorian::days(0) + boost::posix_time::hours(1);
    std::cout << "endtimecal date+hour:" << endtimecal << std::endl;

    std::cout << "endtimecal:" << endtimecal << std::endl;
    
    Json::Value optdata ;
    int64_t ret = ERROR_OTHER;
    optdata = this->testBetparseJSON(sjson_bet_100);

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
    
    Json::Value root;
    ret = pPgdbcommon->getFullSchemeOptionNamesID(root);

    std::cout << " Full scheme:options" << root  << std::endl;
    
    std::cout << map_error((ERROR_CODES_BACCT)ret) << std::endl;

}

