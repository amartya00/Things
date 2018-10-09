cmake_minimum_required(VERSION 3.0)

include_directories(${THIRD_PARTY_HEADERS})

add_custom_target(headers SOURCES
    "ds/stack.h"
    "ds/graph.h"
    "algos/sorts.h")
