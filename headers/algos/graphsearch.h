#ifndef __ALGOS_HEADERS_GRAPHSEARCH__
#define __ALGOS_HEADERS_GRAPHSEARCH__

#include <memory>
#include <vector>
#include <tuple>
#include <unordered_map>

#include "ds/graph.h"

/**
 * @defgroup ALGOS
 * @ingroup ALGOS
 * @brief Collection of sort functions.
 *
 * This is a collection of templatized sort functions.
 *
 * @author Amartya Datta Gupta
 * @version 0.1
 *
 */
namespace SigAbrt {
    namespace Algos {
        template <typename T> std::unordered_map<T, unsigned int> bfs(const SigAbrt::DataStructures::UndirectedGraph<T>& input, const T& start) {
            std::unordered_map<T, unsigned int> retval {};
            retval[start] = 0;
            unsigned int level = 0;

            std::vector<T> frontier {};
            std::vector<T> nextFrontier {};
            // Start with the "start"
            nextFrontier.push_back(start);

            while (nextFrontier.size() > 0) {
                level++;
                // Copy everything fron next frontier to frontier and clear out next fronmtier
                std::swap(frontier, nextFrontier);
                nextFrontier.clear();

                for (auto u : frontier) {
                    for (auto vw : input.getNeighbours(u)) {
                        T v = std::get<0>(vw);
                        if (retval.find(v) == retval.end()) {
                            retval[v] = level;
                            nextFrontier.push_back(v);
                        }
                    }
                }
            }
            return retval;
        }
    }
}

#endif
