#pragma once

#if defined(__MINGW32__) || defined(__MINGW64__)
    #ifdef RACE_LIB_EXPORTS
        #define RACELIB_API __attribute__((visibility("default")))
    #else
        #define RACELIB_API
    #endif
#elif defined(_WIN32)
    #ifdef RACE_LIB_EXPORTS
        #define RACELIB_API __declspec(dllexport)
    #else
        #define RACELIB_API __declspec(dllimport)
    #endif
#else
    #define RACELIB_API
#endif
