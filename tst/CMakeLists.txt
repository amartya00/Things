cmake_minimum_required(VERSION 3.0)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
include_directories(${HEADERS})

# Tests for DS: stack
add_executable(teststack "ds/teststack.cc")
add_test(stack teststack)

# Tests for algos: sorts
add_executable(testsorts "algos/testsorts.cc")
add_test(sorts testsorts)

