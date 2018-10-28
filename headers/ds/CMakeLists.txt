cmake_minimum_required(VERSION 3.0)

include_directories(${THIRD_PARTY_HEADERS})
include_directories(${HEADERS})

add_custom_target(dsheaders SOURCES
    "graph.h"
    "stack.h")
