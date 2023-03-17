// System headers
#include <vector>
#include <stdexcept>
#include <algorithm>

// Local includes
#include "array.h"

// Using declarations
using std::vector;
using std::domain_error;
using std::make_heap;
using std::pop_heap;
using std::push_heap;
using std::greater;

// Typedefs, statics, globals

vector<int>
Array::kLargestNumbers(const std::vector<int>& v, unsigned long k) {
    if (v.empty()) {
        throw domain_error("Error! Empty input vector!");
    }
    if (0 == k || k > v.size()) {
        throw domain_error("Error! Invalid value of k!");
    }

    // Process input vector elements one by one; and use them to
    // populate a heap which stores 'k' largest numbers seen so far
    // at each step of processing

    // Add the first 'k' elements of input vector to heap
    // Then min-heapify 
    vector<int> minHeapV(v.begin(), v.begin() + k);
    make_heap(minHeapV.begin(), minHeapV.end(), greater<int>());

    // Iterate over the remaining elements of input vector sequentially
    // Add the element to heap only if it is more than the minimum
    // value element in the heap; by replacing minimum value element in heap
    // with the new element. Implies that heap should be a min-heap
    for (vector<int>::size_type i = k; i != v.size(); ++i) {
        // Min value element in heap
        int topElem = minHeapV.front();
        if (v[i] > topElem) {
            // Current input element exceeds min element in heap.
            // Replace min element in heap with current element
            // to ensure that heap always has 'k' largest elements
            pop_heap(minHeapV.begin(), minHeapV.end(), greater<int>());
            minHeapV.pop_back();
            minHeapV.push_back(v[i]);
            push_heap(minHeapV.begin(), minHeapV.end(), greater<int>());
        }
    }

    // K largest elements
    return minHeapV;
}
