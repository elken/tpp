project(TestRunner)
include_directories(.)
enable_testing()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
set(TEST_FILES
    expression_test.cpp
    include.hpp)

add_executable(${PROJECT_NAME} ${TEST_FILES})
add_test(${PROJECT_NAME} ${PROJECT_NAME})