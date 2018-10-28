cmake_minimum_required(VERSION 3.0)

include_directories(${GTEST_INCLUDE_DIRS})
include_directories(${HEADERS})

add_library(utils SHARED "stringutils.cc")
