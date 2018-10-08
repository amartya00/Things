#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include <stdexcept>

#include "ds/stack.h"

SCENARIO ("Stack operations", "StackTest") {
    GIVEN ("I have an integer type stack.") {
        SigAbrt::DataStructures::Stack<int> testStack;

        WHEN ("I Push some elemento on the stack") {
            testStack.push(10);
            testStack.push(11);
            testStack.push(12);

            AND_WHEN ("I do some pop operations") {
                auto e1 = testStack.pop();
                auto e2 = testStack.pop();
                auto e3 = testStack.pop();

                THEN ("I should get the elements back in reverse order") {
                    REQUIRE(e1 == 12);
                    REQUIRE(e2 == 11);
                    REQUIRE(e3 == 10);
                }
            }
        }
    }
}

SCENARIO ("Stack underflow test", "StackTest") {
    GIVEN ("I have an integer type stack.") {
        SigAbrt::DataStructures::Stack<int> testStack;

        WHEN ("I do a pop") {
            THEN ("I should get a stack underfloe wxception") {
                REQUIRE_THROWS_AS (testStack.pop(), std::underflow_error);
            }
        }
    }
}
