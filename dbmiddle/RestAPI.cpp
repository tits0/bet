#include "RestAPI.h"
#include <iostream>
#include <stdlib.h>
#include "mongoose.h"
#include <stdio.h>
#include <string.h>
const char *s_no_cache_header =  "Cache-Control: max-age=0, post-check=0, "
  "pre-check=0, no-store, no-cache, must-revalidate\r\n";

RestAPI::RestAPI()
{
}

RestAPI::~RestAPI()
{
}

int RestAPI::handle_restful_call(struct mg_connection *conn, enum mg_event ev) {
  char cjsondata[4024] ;
  int readSize=0;
  Json::Value root;
  switch (ev) {
    case MG_AUTH: return MG_TRUE;
    case MG_REQUEST:
        std::cout << "calling uri:" << conn->uri << std::endl;
        // Read POST data
        int post_data_len;
        mg_get_var(conn, "req", cjsondata, sizeof(cjsondata));
        
          if (!strcmp(conn->uri, CREATEBET)) {
              this->createBet(cjsondata, root);
              return MG_TRUE;
          } else if (!strcmp(conn->uri, CREATESCHEME)) {
              this->createScheme(cjsondata, root);
              return MG_TRUE;
          } else if (!strcmp(conn->uri, GETFULLSCHEMEOPTIONNAMESID)) {
              this->getFullSchemeOptionNamesID(cjsondata, root);
              return MG_TRUE;
          } else if (!strcmp(conn->uri, GETPOINTS)) {
              this->getPoints(cjsondata, root);
              return MG_TRUE;
          } else if (!strcmp(conn->uri, NEWUSER)) {
              this->getPoints(cjsondata, root);
              return MG_TRUE;
          }
          
      mg_send_file(conn, "index.html", s_no_cache_header);
      return MG_MORE;
    default: return MG_FALSE;
  }

  mg_printf_data(conn, "{ \"result\": %s }",  root.asCString() );
}


static int ev_handler(struct mg_connection *conn, enum mg_event ev) {
  RestAPI *server = (RestAPI *)conn->server_param;
  
  return server->handle_restful_call(conn, ev);
    
}

int RestAPI::RestServer(void) {

  // Create and configure the server
  m_server = mg_create_server(this, ev_handler);
  mg_set_option(m_server, "listening_port", "8000");

  // Serve request. Hit Ctrl-C to terminate the program
  std::cout << "Starting on port " << mg_get_option(m_server, "listening_port") << std::endl;
  for (;;) {
    mg_poll_server(m_server, 1000);
  }

  // Cleanup, and free server instance
  mg_destroy_server(&m_server);

  return 0;
}