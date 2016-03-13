cmake_minimum_required(VERSION 3.2.3)
project(tpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
include_directories(src)

if (WITH_TESTS)
    add_subdirectory(tests)
endif()

set(EXPRESSION_FILES
    src/expression/include.hpp)

set(SOURCE_FILES
    ${EXPRESSION_FILES}
    main.cpp
    src/globals.hpp)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})