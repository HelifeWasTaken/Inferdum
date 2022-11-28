project(inferdum)
cmake_minimum_required(VERSION 3.15)
include(FetchContent)

set(CMAKE_CXX_STANDARD 20)

add_compile_definitions(_WIN32_WINT=0x0601)

if (NOT box2d_FOUND)
    message("Declaring box2d...")
    FetchContent_Declare(
        box2d
        GIT_REPOSITORY "https://github.com/erincatto/box2d"
        GIT_TAG v2.4.1
    )
    message("Getting box2d properties...")
    FetchContent_GetProperties(box2d)
    if (NOT box2d_POPULATED)
        message("Populating Box2d...")

        set(BOX2D_BUILD_UNIT_TESTS OFF CACHE BOOL "" FORCE)
        set(BOX2D_BUILD_TESTBED OFF CACHE BOOL "" FORCE)
        set(BOX2D_USER_SETTINGS OFF CACHE BOOL "" FORCE)

        FetchContent_Populate(box2d)

        add_subdirectory(${box2d_SOURCE_DIR} ${box2d_BINARY_DIR})
        set(box2d_FOUND TRUE)
    endif()
endif()

message("Fetching box2d")

FetchContent_MakeAvailable(box2d)

if (NOT spdlog_FOUND)
    message("Declaring spdlog...")
    FetchContent_Declare(
        spdlog
        GIT_REPOSITORY "https://github.com/gabime/spdlog.git"
        GIT_TAG v1.11.0
    )
    message("Getting spdlog properties...")
    FetchContent_GetProperties(spdlog)
    if (NOT spdlog_POPULATED)
        message("Populating spdlog...")
        FetchContent_Populate(spdlog)
        add_subdirectory(${spdlog_SOURCE_DIR} ${spdlog_BINARY_DIR})
        set(spdlog_FOUND TRUE)
    endif()
endif()

message("Fetching spdlog...")
FetchContent_MakeAvailable(spdlog)

if (NOT lua_FOUND)
    message("Declaring lua...")
    FetchContent_Declare(
        lua
        GIT_REPOSITORY "https://github.com/HelifeWasTaken/lua"
        GIT_TAG 1.0
    )
    message("Getting lua properties...")
    FetchContent_GetProperties(lua)
    if (NOT lua_POPULATED)
        message("Populating lua...")
        FetchContent_Populate(lua)
        add_subdirectory(${lua_SOURCE_DIR} ${lua_BINARY_DIR})
        set(lua_FOUND TRUE)
    endif()
endif()

FetchContent_MakeAvailable(lua)

if (NOT sol2_FOUND)
    message("Declaring sol2...")
    FetchContent_Declare(
        sol2
        GIT_REPOSITORY "https://github.com/ThePhD/sol2"
        GIT_TAG v3.3.0
    )
    message("Getting sol2 properties...")
    FetchContent_GetProperties(sol2)
    if (NOT sol2_POPULATED)
        message("Populating sol2...")
        FetchContent_Populate(sol2)
        add_subdirectory(${sol2_SOURCE_DIR} ${sol2_BINARY_DIR})
        set(sol2_FOUND TRUE)
    endif()
endif()

message("Fetching sol2")
FetchContent_MakeAvailable(sol2)

if (NOT entt_FOUND)
    message("Declaring entt...")
    FetchContent_Declare(
        entt
        GIT_REPOSITORY "https://github.com/skypjack/entt"
        GIT_TAG v3.11.0
    )
    message("Getting entt properties...")
    FetchContent_GetProperties(entt)
    if (NOT entt_POPULATED)
        message("Populating entt...")
        FetchContent_Populate(entt)
        add_subdirectory(${entt_SOURCE_DIR} ${entt_BINARY_DIR})
        set(entt_FOUND TRUE)
    endif()
endif()

FetchContent_MakeAvailable(entt)

include_directories(

    ${box2d_SOURCE_DIR}/include
    ${box2d_SOURCE_DIR}/src

    ${spdlog_SOURCE_DIR}/include

    ${lua_SOURCE_DIR}/include
    ${sol2_SOURCE_DIR}/include

    ${CMAKE_SOURCE_DIR}/include

)

file(
    GLOB_RECURSE SRC
    src/*.cpp
    include/*.hpp
    include/*.h
    src/*.c
)

add_library(${PROJECT_NAME} STATIC ${SRC})

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR})