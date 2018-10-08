#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include <stdexcept>
#include <random>
#include <algorithm>
#include <functional>
#include <iostream>

#include "algos/sorts.h"

SCENARIO ("Testing insertion sort", "InsertionSort") {
    GIVEN ("I have a vector of integers") {
        // First create an instance of an engine.
        std::random_device rnd_device;
        // Specify the engine and distribution.
        std::mt19937 mersenneEngine {rnd_device()};  // Generates random integers
        std::uniform_int_distribution<int> dist {1, 1000};
        auto gen = [&dist, &mersenneEngine](){return dist(mersenneEngine);};

        std::vector<int> testVector(100);
        std::generate(testVector.begin(), testVector.end(), gen);

        // Copy and sort
        std::vector<int> expectedVector {testVector};
        std::sort(expectedVector.begin(), expectedVector.end());

        WHEN ("I run insertion sort on the test vector") {
            SigAbrt::Algos::insertionSort(testVector);

            THEN ("The vector should be sorted.") {
                REQUIRE( testVector == expectedVector);
            }
        }
    }
}

SCENARIO ("Testing merge sort", "MergeSort") {
    GIVEN ("I have a vector of integers") {
        // First create an instance of an engine.
        std::random_device rnd_device;
        // Specify the engine and distribution.
        std::mt19937 mersenneEngine {rnd_device()};  // Generates random integers
        std::uniform_int_distribution<int> dist {1, 1000};
        auto gen = [&dist, &mersenneEngine](){return dist(mersenneEngine);};

        std::vector<int> testVector(100);
        std::generate(testVector.begin(), testVector.end(), gen);

        // Copy and sort
        std::vector<int> expectedVector {testVector};
        std::sort(expectedVector.begin(), expectedVector.end());

        WHEN ("I run merge sort on the test vector") {
            SigAbrt::Algos::mergeSort(testVector);

            THEN ("The vector should be sorted.") {
                REQUIRE( expectedVector == testVector );
            }
        }
    }
}
