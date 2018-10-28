#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include <stdexcept>
#include <vector>
#include <tuple>
#include <unordered_map>

#include "ds/graph.h"
#include "algos/graphsearch.h"

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

SCENARIO ("Graph search", "Bfs") {
    GIVEN ("When I create a graph object.") {
        SigAbrt::DataStructures::UndirectedGraph<std::string> myGraph;

        WHEN("I add some nodes to the graph.") {
            myGraph.addNeighbour("A", "B", 1);
            myGraph.addNeighbour("A", "C", 1);
            myGraph.addNeighbour("A", "D", 1);
            myGraph.addNeighbour("B", "D", 2);

            AND_WHEN("I do a bfs on it") {
                std::unordered_map<std::string, unsigned int> levels = SigAbrt::Algos::bfs(myGraph, std::string("A"));

                THEN("The the levels should be correct.") {
                    for (auto v : levels) {
                        std::cout << std::get<0>(v) << "\n";
                    }
                    REQUIRE(levels.size() == 4);
                    REQUIRE(levels.at("A") == 0);
                }
            }
        }
    }
}
