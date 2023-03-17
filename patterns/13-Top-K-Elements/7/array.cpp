// System headers
#include <vector>
#include <queue>
#include <functional>

// Local includes
#include "array.h"

// Using declarations
using std::vector;

// Statics, typedefs, globals

// Constructor
KthLargestElement::KthLargestElement(
    const vector<int>& v, unsigned int k) : _maxAllowedHeapElems(k) {
    // Populate heap with K largest elements of vector
    for (auto e : v) {
        addElement(e);
    }
}

int
KthLargestElement::addElement(int e) {
    // Add element to heap if its value is amongst the K large
    // values seen so far (i.e. its value is more than least
    // value element in heap if heap has K elements)
    if (_minHeap.size() >= _maxAllowedHeapElems) {
        if (e > _minHeap.top()) {
            _minHeap.pop();
            _minHeap.push(e);
        }
    } else {
        _minHeap.push(e);
    }
    // Return the Kth largest element seen so far
    return _minHeap.top();
}
