#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include <string>

#include "utils/stringutils.h"

constexpr unsigned long RANDOM_STR_SIZE_1 = 8;
constexpr unsigned long RANDOM_STR_SIZE_2 = 16;
constexpr unsigned long RANDOM_STR_SIZE_3 = 32;

SCENARIO ("String utils tests", "StringUtils") {
    WHEN ("I call the randonString function with a length of " + std::to_string(RANDOM_STR_SIZE_1)) {
        std::string retval {SigAbrt::Utils::randomString(RANDOM_STR_SIZE_1)};

        THEN ("The generated string should metch the length i provided as input") {
            REQUIRE(retval.size() == RANDOM_STR_SIZE_1);
        }
    }

    WHEN ("I call the randonString function with a length of " + std::to_string(RANDOM_STR_SIZE_2)) {
        std::string retval {SigAbrt::Utils::randomString(RANDOM_STR_SIZE_2)};

        THEN ("The generated string should metch the length i provided as input") {
            REQUIRE(retval.size() == RANDOM_STR_SIZE_2);
        }
    }

    WHEN ("I call the randonString function with a length of " + std::to_string(RANDOM_STR_SIZE_3)) {
        std::string retval {SigAbrt::Utils::randomString(RANDOM_STR_SIZE_3)};

        THEN ("The generated string should metch the length i provided as input") {
            REQUIRE(retval.size() == RANDOM_STR_SIZE_3);
        }
    }
}
