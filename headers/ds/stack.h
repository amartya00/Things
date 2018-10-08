#ifndef __DS_HEADERS_STACK__
#define __DS_HEADERS_STACK__

#include <vector>
#include <stdexcept>
#include <iostream>

/**
 * @defgroup DS
 * @class Stack
 * @ingroup DS
 * @brief Stack class template.
 *
 * This class is a templatized stack data structure. This is implemented to store
 * an arbitrary number of elements. It only has underflow exception.
 *
 * @author Amartya Datta Gupta
 * @version 0.1
 *
 */

namespace SigAbrt {
    namespace DataStructures {
        template <typename T> class Stack {
        private:
            std::vector<T> storage;
        public:
            /**
             * @brief Function to push an element into the stack
             * @param elem: The element to push
             */
            void push(const T& elem) {
                storage.push_back(elem);
            }

            /**
             * @brief Function to pop an element and return
             * @return The popped element
             */
            T pop() {
                std::cout << "\tPopping\n";
                if (storage.size() == 0) {
                    throw std::underflow_error("Stack is empty");
                }
                T temp = std::move(storage.back());
                storage.pop_back();
                return temp;
            }

            /**
             * @brief Function to peek at the top of the stack without modifying it
             * @return The top element
             */
            const T& peek() const {
                if (storage.size() == 0) {
                    throw std::underflow_error("Stack is empty");
                }
                return storage.back();
            }
        };
    }
}

#endif
