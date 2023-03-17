#ifndef _MIN_HEAP_H_
#define _MIN_HEAP_H_

// System headers
#include <vector>

// Local includes

// Using declarations

// Statics, typedefs, globals

template <typename T>
class MinHeap {
public:
    // Public interface
    typedef typename std::vector<T>::size_type size_type;

    // Constructor
    MinHeap();

    // Returns the size/num elements stored in the heap
    inline size_type size() { return _heap.size(); }
    // Returns true if heap is empty, false otherwise
    inline bool empty() { return _heap.empty(); }
    // Returns the minimum element stored the heap
    T min();
    // Removes the minimum element from the heap
    void removeMin();
    // Inserts the given element into the heap
    void insert(const T& e);

private:
    // Private Member fns

    // Return index of the right/left respectively child in the heap given
    // the parent index
    inline size_type rChildIdx(size_type p) { return p * 2 + 2; }
    inline size_type lChildIdx(size_type p) { return p * 2 + 1; }
    // Return index of parent given the child index
    inline size_type parentIdx(size_type i) { return (i > 0) ? (i - 1) / 2 : 0;}

    // Min heapify the heap elements commencing from parent index i down
    // to leaf. Usually called after removal of min element from heap top
    void heapify(size_type i);
    // Moves the element at index i up the heap to maintain heap property
    // Usually invoked after insertion of element into heap
    void percolateUp(size_type i);

    // Data member
    // Vector/array which stores heap elements
    std::vector<T> _heap;
};

#endif /* _MIN_HEAP_H_ */
