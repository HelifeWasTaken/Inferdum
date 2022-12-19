project(kat)
cmake_minimum_required(VERSION 3.15)
include(FetchContent)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 20)

add_compile_definitions(_WIN32_WINT=0x0601)

if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    add_compile_options(-fconcepts)
endif()

file(
    GLOB_RECURSE SRC
    src/*.cpp
    include/*.hpp
    include/*.h
    src/*.c
)

include_directories(include)

add_library(${PROJECT_NAME} STATIC ${SRC})

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR})
