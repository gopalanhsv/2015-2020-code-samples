// System headers
#include <vector>
#include <stdexcept>

// Local includes
#include "minHeap.h"
#include "minHeap.cpp"

// Using declarations
using std::vector;
using std::domain_error;

// Statics, typedefs, globals

vector<int>
kSmallestElements(const vector<int>& v, int k) {
    if (k <= 0 || v.empty() || k > v.size()) {
        throw domain_error("Error! Invalid k and/or empty input vector!");
    }

    // Create a min heap and all elements of the vector to it
    MinHeap<int> minHeap;
    for (vector<int>::size_type i = 0; i != v.size(); ++i) {
        minHeap.insert(v[i]);
    }

    // Extract the min element from heap, add to new vector. Repeat k times,
    // this would give k smallest elements from original vector
    vector<int> kSmallestVec;
    for (int i = 0; i != k ; ++i) {
        kSmallestVec.push_back(minHeap.min());
        minHeap.removeMin();
    }

    return kSmallestVec;
}
