#ifndef ERROR_CODES_H
#define ERROR_CODES_H

enum ERROR_CODES_BACCT {
    ERROR_OK=0,
    ERROR_OTHER=-1,
    ERROR_MIN_OPTS=-2,
    ERROR_BET_FAILED=-3
};

extern const char **ERROR_NAMES_BACCT;
const char* map_error(ERROR_CODES_BACCT err);

#endif // ERROR_CODES_H
