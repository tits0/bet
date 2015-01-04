#ifndef RESTAPI_H
#define RESTAPI_H
#include "pgdbcommon.h"
#include "mongoose.h"

class RestAPI
{
private:

    struct mg_server *m_server;
    
    RestAPI(const RestAPI& rhs);
    RestAPI& operator=(const RestAPI& rhs);
    
    Json::Value testparseJSON(std::string spjson);
public:
    RestAPI();
    ~RestAPI();
    int RestServer(void);
    int handle_restful_call(struct mg_connection *conn, enum mg_event ev);
    ERROR_CODES_BACCT createScheme(Json::Value& root);
    ERROR_CODES_BACCT createBet(Json::Value& root);
    ERROR_CODES_BACCT getFullSchemeOptionNamesID(Json::Value& root);
    ERROR_CODES_BACCT getPoints(Json::Value& root);
    
};

#endif // RESTAPI_H
