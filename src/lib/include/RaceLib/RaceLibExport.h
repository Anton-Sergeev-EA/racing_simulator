#pragma once

#ifdef _WIN32
    #ifdef RACE_LIB_EXPORTS
        #define RACELIB_API __declspec(dllexport)
    #else
        #define RACELIB_API __declspec(dllimport)
    #endif
#else
    #define RACELIB_API
#endif
