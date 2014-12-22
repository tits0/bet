#include "error_codes.h"

const char*  map_error(ERROR_CODES_BACCT err) 
{
   switch (err)
   {
      case ERROR_OK:   return "OK";
      case ERROR_OTHER:   return "unknown error";
      case ERROR_MIN_OPTS:   return "error minimum options needs to be two";
      default:
         break;
   }

   return "UNKNOWN";
}

