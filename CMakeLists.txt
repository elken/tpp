cmake_minimum_required(VERSION 3.2.3)
project(tpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
include_directories(src)

set(EXPRESSION_FILES
    src/expression/include.hpp)

set(SOURCE_FILES
    ${EXPRESSION_FILES}
    main.cpp
    src/globals.hpp)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME})