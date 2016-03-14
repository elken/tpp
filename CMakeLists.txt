cmake_minimum_required(VERSION 2.8)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
include_directories(src)
add_subdirectory(tests)
set(CMAKE_BUILD_TYPE Release)

set(EXPRESSION_FILES
    src/expression/include.hpp)

set(SOURCE_FILES
    ${EXPRESSION_FILES}
    src/globals.hpp)

add_custom_target(check COMMAND cd tests && ${CMAKE_CTEST_COMMAND} DEPENDS TestRunner)