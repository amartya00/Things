cmake_minimum_required(VERSION 3.0)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
include_directories(${HEADERS})

# Tests for DS: stack
add_executable(teststack "ds/teststack.cc")
target_link_libraries(teststack pthread)
add_test(stack teststack)

# Tests for graph
add_executable(testgraph "ds/testgraph.cc")
target_link_libraries(testgraph pthread)
add_test(graph testgraph)

# Tests for algos: sorts
add_executable(testsorts "algos/testsorts.cc")
add_test(sorts testsorts)

