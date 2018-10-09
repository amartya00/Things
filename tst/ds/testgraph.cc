#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include <stdexcept>
#include <vector>
#include <tuple>

#include "ds/graph.h"

SCENARIO ("Graph normal operations", "Graph") {
    GIVEN ("When I create a graph object") {
        SigAbrt::DataStructures::UndirectedGraph<std::string> myGraph;

        WHEN("I add some nodes to the graph.") {
            myGraph.addNeighbour("A", "B", 1);
            myGraph.addNeighbour("A", "C", 1);
            myGraph.addNeighbour("A", "D", 1);
            myGraph.addNeighbour("B", "D", 2);

            AND_WHEN ("I get the neighbours.") {
                auto neighboutsOfA = myGraph.getNeighbours("A");
                auto neighboutsOfB = myGraph.getNeighbours("B");
                auto neighboutsOfC = myGraph.getNeighbours("C");

                THEN ("They should be what I expect.") {
                    REQUIRE(std::vector<std::tuple<std::string, unsigned int>> {std::make_tuple("B", 1), std::make_tuple("C", 1), std::make_tuple("D", 1)} == neighboutsOfA);
                    REQUIRE(std::vector<std::tuple<std::string, unsigned int>> {std::make_tuple("A", 1), std::make_tuple("D", 2)} == neighboutsOfB);
                    REQUIRE(std::vector<std::tuple<std::string, unsigned int>> {std::make_tuple("A", 1)} == neighboutsOfC);
                }
            }
        }
    }
}
