#ifndef __ALGOS_HEADERS_SORTS__
#define __ALGOS_HEADERS_SORTS__

#include <vector>
#include <memory>

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
        /**
         * @brief This is a bubble sort function.
         * @param arr: This is the list to be sorted.
         */
        template <typename T> void insertionSort(std::vector<T>& arr) {
            for (typename std::vector<T>::size_type i = 1; i < arr.size(); i++) {
                for (auto j = i; j > 0; j--) {
                    if (arr[j] < arr[j-1]) {
                        std::swap(arr[j], arr[j-1]);
                    } else {
                        break;
                    }
                }
            }
        }

        /**
         * @brief This is a merge function. It merges 2 halves of an input arr between [start, mid) and [mid, end).
         * @param arr: The input array.
         * @param start: Start of the first half.
         * @param mid: Start of the second half.
         * @param end: End of the second hald + 1.
         */
        template <typename T> void merge(std::vector<T>& arr,
                                         const typename std::vector<T>::size_type start,
                                         const typename std::vector<T>::size_type middle,
                                         const typename std::vector<T>::size_type end) {
            auto tempArr = std::make_unique<T[]>(end-start);
            auto first = start;
            auto second = middle;
            typename std::vector<T>::size_type tempArrIdx = 0;
            while (first < middle && second < end) {
                // Move by 2 pointer method
                if (arr[first] > arr[second]) {
                    tempArr[tempArrIdx] = std::move(arr[second]);
                    tempArrIdx++;
                    second++;
                } else {
                    tempArr[tempArrIdx] = std::move(arr[first]);
                    tempArrIdx++;
                    first++;
                }
            }
            // Move remains of first half
            for (; first < middle; first++, tempArrIdx++) {
                tempArr[tempArrIdx] = std::move(arr[first]);
            }
            // Move remains of second half
            for (; second < end; second++, tempArrIdx++) {
                tempArr[tempArrIdx] = std::move(arr[second]);
            }
            // Ovewrite original array with temp
            for (auto i = start; i < end; i++) {
                arr[i] = tempArr[i-start];
            }
        }

        /**
         * @brief This is a merge sort function.
         * @param arr: This is the list to be sorted.
         */
        template <typename T> void mergeSortCallback(std::vector<T>& arr,
                                                const typename std::vector<T>::size_type start,
                                                const typename std::vector<T>::size_type end) {
            if (end-start <= 1) {
                return;
            }
            auto middle = (start+end)/2;
            mergeSortCallback(arr, start, middle);
            mergeSortCallback(arr, middle, end);
            merge(arr, start, middle, end);
        }

        template <typename T> void mergeSort(std::vector<T>& arr) {
            mergeSortCallback(arr, 0, arr.size());
        }
    }
}

#endif
