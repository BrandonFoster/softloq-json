#ifndef SOFTLOQ_JSON_DEFINITIONS_HPP
#define SOFTLOQ_JSON_DEFINITIONS_HPP

#if _MSC_VER
    #define SOFTLOQ_JSON_EXPORT __declspec(dllexport)
    #define SOFTLOQ_JSON_IMPORT __declspec(dllimport)
#elif __GNUC__
    #define SOFTLOQ_JSON_EXPORT __attribute__((visibility("default")))
    #define SOFTLOQ_JSON_IMPORT
#endif

#ifdef SOFTLOQ_JSON_NO_API
    #define SOFTLOQ_JSON_API
#elif SOFTLOQ_JSON_BUILD_API
    #define SOFTLOQ_JSON_API SOFTLOQ_JSON_EXPORT
#elif SOFTLOQ_JSON_USE_API
    #define SOFTLOQ_JSON_API SOFTLOQ_JSON_IMPORT
#else
    #define SOFTLOQ_JSON_API
#endif

#endif