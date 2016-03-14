cmake_minimum_required(VERSION 2.8)
project(tpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
include_directories(src)
add_subdirectory(tests)

set(EXPRESSION_FILES
    src/expression/include.hpp)

set(SOURCE_FILES
    ${EXPRESSION_FILES}
    main.cpp
    src/globals.hpp)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
