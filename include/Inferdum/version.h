#pragma once

#define INFERDUM_NAME    "Inferdum"
#define INFERDUM_VERSION "0.1"

#ifdef CMAKE_BUILD_TYPE
#define INFERDUM_BUILD_TYPE CMAKE_BUILD_TYPE
#else
#define INFERDUM_BUILD_TYPE "Unknown"
#endif

#if defined(_WIN32) || defined(_WIN64)
#define INFERDUM_WINDOWS    1
#define INFERDUM_API        __declspec(dllexport)
#define INFERDUM_API_IMPORT __declspec(dllimport)
#define INFERDUM_OS         "Windows"
#elif defined(__linux__) || defined(__unix__)
#define INFERDUM_UNIX 1
#define INFERDUM_API  __attribute__((visibility("default")))
#define INFERDUM_API_IMPORT
#define INFERDUM_OS "Unix"
#elif defined(__APPLE__)
#define INFERDUM_MACOS 1
#define INFERDUM_API   __attribute__((visibility("default")))
#define INFERDUM_API_IMPORT
#define INFERDUM_OS "MacOS"
#endif

#if defined(INFERDUM_UNIX) || defined(INFERDUM_MACOS)
#define INFERDUM_POSIX 1
#endif

#if !defined(INFERDUM_WINDOWS) && !defined(INFERDUM_UNIX)                      \
    && !defined(INFERDUM_MACOS)
#error "Unsupported platform"
#endif

#define INFERDUM_VERSION_FULL                                                  \
    INFERDUM_NAME " v" INFERDUM_VERSION " (" INFERDUM_BUILD_TYPE               \
                  ") " INFERDUM_OS
