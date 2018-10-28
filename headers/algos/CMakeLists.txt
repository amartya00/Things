cmake_minimum_required(VERSION 3.0)

include_directories(${THIRD_PARTY_HEADERS})
include_directories(${HEADERS})

add_custom_target(algosheaders SOURCES
    "sorts.h"
    "graphsearch.h")
