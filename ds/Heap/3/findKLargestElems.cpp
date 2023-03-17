// System headers
#include <vector>
#include <stdexcept>

// Local includes
#include "maxHeap.h"
#include "maxHeap.cpp"

// Using declarations
using std::vector;
using std::domain_error;

// Statics, typedefs, globals

vector<int>
kLargestElements(const vector<int>& v, int k) {
    if (k <= 0 || v.empty() || k > v.size()) {
        throw domain_error("Error! Invalid k and/or empty input vector!");
    }

    // Create a max heap and all elements of the vector to it
    MaxHeap<int> maxHeap;
    for (vector<int>::size_type i = 0; i != v.size(); ++i) {
        maxHeap.insert(v[i]);
    }

    // Extract the max element from heap, add to new vector. Repeat k times,
    // this would give k largest elements from original vector
    vector<int> kLargestVec;
    for (int i = 0; i != k ; ++i) {
        kLargestVec.push_back(maxHeap.max());
        maxHeap.removeMax();
    }

    return kLargestVec;
}
