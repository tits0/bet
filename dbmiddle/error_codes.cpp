#include "error_codes.h"

const char*  map_error(ERROR_CODES_BACCT err) 
{
   switch (err)
   {
      case ERROR_OK:   return "OK";
      case ERROR_OTHER:   return "unknown error";
      case ERROR_MIN_OPTS:   return "error minimum options needs to be two";
      case ERROR_OPT_NOT_FOUND:   return "error option not found";
      case ERROR_SCHEME_NOT_FOUND:   return "error scheme not found";
      case ERROR_UNDEFINED:   return "undefined error ";
      case ERROR_NOT_ENOUGH_POINTS:   return "user dont have enough points";
      case ERROR_QUERY_FAILED:   return "query failed ";
      case ERROR_USER_NOT_FOUND:   return "user not found";
      case ERROR_USER_POINTS_NULL:   return "query returns null instead of user points";
      case ERROR_SCHEME_CREATION_FAILED:   return "scheme creation failed";
      case ERROR_MIN_OPTS_FOR_SCHEME:   return "insufficient options for scheme min is two";
      case ERROR_USER_CREATION_FAILED:   return "insufficient options for scheme min is two";
      case ERROR_FINALIZE_FAILED:   return "finalize failed";
      default:
         break;
   }

   return "UNKNOWN";
}

