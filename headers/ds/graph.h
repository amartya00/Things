#ifndef __DS_HEADERS_GRAPH__
#define __DS_HEADERS_GRAPH__

#include <unordered_map>
#include <tuple>
#include <vector>
#include <shared_mutex>

/**
 * @class Stack
 * @brief Graph class template.
 *
 * This class is a templatized Graph class. This uses an unordered map internally for storage.
 * The keys are of type T amd the value is a list of tuples (T, unsigned int).
 *
 * Given that T us used as a key and inside a tuple, type trait restrictions apply for T.
 * Please read the following links for details:
 * https://en.cppreference.com/w/cpp/container/unordered_map
 * https://en.cppreference.com/w/cpp/utility/tuple
 *
 * All write operations are serialized with mutexes.
 *
 * @author Amartya Datta Gupta
 * @version 0.1
 *
 */
namespace SigAbrt {
    namespace DataStructures {
        template <typename T> class Graph {
        protected:
            /**
             * @brief Function to add a neighbour.
             * @param v: The virtex node.
             * @param neighbour: The neighbour node.
             * @param weight: The edge weight between v and neighbour.
             */
            virtual void addNeighbour(const T& v, const T& neighbour, const unsigned int weight) noexcept = 0;

            /**
             * @brief Function to return neighbours of a virtex. This throws a std::out_of_range exception if node is absent.
             * @param v: We want v's neighbours.
             * @return List of vertives that are neighbours of v.
             */
            virtual const std::vector<std::tuple<T, unsigned int>>& getNeighbours(const T& v) const = 0;
        };

        // Undirected graph implementation
        template <typename T> class UndirectedGraph : public Graph<T> {
        private:
            std::unordered_map<T, std::vector<std::tuple<T, unsigned int>>> adjList;
            mutable std::shared_mutex lock;

        public:
            void addNeighbour(const T& v, const T& neighbour, const unsigned int weight) noexcept {
                std::lock_guard<std::shared_mutex> guard {lock};
                adjList[v].push_back(std::make_tuple(neighbour, weight));
                adjList[neighbour].push_back(std::make_tuple(v, weight));
            }

            const std::vector<std::tuple<T, unsigned int>>& getNeighbours(const T& v) const {
                std::shared_lock<std::shared_mutex> guard {lock};
                return adjList.at(v);
            }
        };
    }
}

#endif
