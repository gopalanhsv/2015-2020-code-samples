// System headers
#include <vector>
#include <stdexcept>
#include <algorithm>

// Local includes
#include "minHeap.h"

// Using declarations
using std::vector;
using std::domain_error;
using std::swap;

// Statics, typedefs, globals

// Constructor
template <typename T>
MinHeap<T>::MinHeap() {
    _heap.resize(0);
}

// Returns the minimum element stored the heap
template <typename T>
T
MinHeap<T>::min() {
    if (_heap.empty()) {
        throw domain_error("Error! min() on empty heap!");
    }
    return _heap[0];
}

// Removes the minimum element from the heap
template <typename T>
void
MinHeap<T>::removeMin() {
    if (_heap.empty()) {
        throw domain_error("Error! removeMin() on empty heap!");
    }

    // Swap the min element (index 0/root) with element at heap end
    swap(_heap[0], _heap[size() - 1]);
    // Remove min element from heap
    _heap.pop_back();
    // Now reorganize the heap from root to leaf element
    heapify(0);
}

// Inserts the given element into the heap
template <typename T>
void
MinHeap<T>::insert(const T& e) {
    // Add the new element at end of heap/as rightmost leaf node
    _heap.push_back(e);
    // Move the new element up as required to maintain heap property
    // post insertion of new element
    percolateUp(size() - 1);
}

// Min heapify the heap elements commencing from parent index i down
// to leaf. Usually called after removal of min element from heap top
template <typename T>
void
MinHeap<T>::heapify(MinHeap::size_type i) {
    if (_heap.empty()) {
        throw domain_error("Error! heapify() on empty heap!");
    }

    if (i >= size()) {
        throw domain_error("Error! heapify() internal implemention error!");
    }

    // Explore all elements from i down the heap to leaf/last element
    // moving element from parent node down to child node in order to
    // maintain min heap property
    while (i < size()) {
        size_type rc = rChildIdx(i);
        size_type lc = lChildIdx(i);
        size_type minElemIdx = i;

        // Determine the index (either right/left child) which has min value
        if (rc < size() && _heap[minElemIdx] > _heap[rc]) {
            minElemIdx = rc;
        }
        if (lc < size() && _heap[minElemIdx] > _heap[lc]) {
            minElemIdx = lc;
        }

        // Swap the element at i with its right/left child if they have higher
        // values, else exit
        if (i != minElemIdx) {
            swap(_heap[minElemIdx], _heap[i]);
            i = minElemIdx;
        } else {
            break;
        }
    }
}

// Moves the element at index i up the heap to maintain heap property
// Usually invoked after insertion of element into heap
template <typename T>
void
MinHeap<T>::percolateUp(MinHeap::size_type i) {
    if (_heap.empty()) {
        throw domain_error("Error! heapify() on empty heap!");
    }

    if (i >= size()) {
        throw domain_error("Error! heapify() internal implemention error!");
    }

    // Examine elements from given index upto root
    while (i != parentIdx(i)) {
        size_type p = parentIdx(i);
        if (_heap[p] > _heap[i]) {
            // Node and its parent violate heap property, exchange them
            swap(_heap[p], _heap[i]);
            i = p;
        } else {
            // Heap property maintained on from this point, exit
            break;
        }
    }
}
