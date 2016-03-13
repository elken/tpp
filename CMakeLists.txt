cmake_minimum_required(VERSION 3.2.3)
project(tpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
set(TEST_NAME ${PROJECT_NAME}_test)
include_directories(src)
include_directories(tests/lib/googletest tests/lib/googletest/include)
enable_testing()

set(EXPRESSION_FILES
    src/expression/include.hpp)

set(SOURCE_FILES
    ${EXPRESSION_FILES}
    main.cpp
    src/globals.hpp)

set(TEST_FILES
    tests/expression_test.cpp)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
add_executable(${TEST_NAME} ${TEST_FILES})
target_link_libraries(${PROJECT_NAME})
target_link_libraries(${TEST_NAME} gtest gtest_main)
add_test(${TEST_NAME} ${TEST_NAME})