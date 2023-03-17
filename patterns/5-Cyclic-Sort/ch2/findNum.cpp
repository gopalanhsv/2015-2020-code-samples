// System headers
#include <vector>
#include <stdexcept>
#include <algorithm>

// Local includes
#include "findNum.h"

// Using declarations
using std::vector;
using std::domain_error;
using std::swap;

// Statics, typedefs, globals

int
FindNum::findFirstMissingPositive(const vector<int>& iv){
    if (iv.empty()) {
        throw domain_error("Error! Empty input vec!");
    }

    // Do a cyclic sort of input vector elements with
    // a local copy
    vector<int> v(iv.begin(), iv.end());

    typedef vector<int>::size_type vecSzT;
    // Examine all elements of input vector and cyclic sort all +ve
    // numbers to their sorted/appropriate indices. Input array
    // should contain only +ve elements in range [1, v.size()]
    vecSzT i = 0;
    while (i != v.size()) {
        if (v[i] <= 0 || v[i] > v.size()) {
            // Skip out of +ve range numbers
            ++i;
        } else {
            // Determine correct sorted location of element v[i]
            vecSzT correctIdx = v[i] - 1;
            // Check if element v[i] is at its correct sorted location
            if (v[correctIdx] != v[i]) {
                // Element v[i] is not at its correct sorted location, so
                // move it to its correct sorted location via an exchange
                swap(v[i], v[correctIdx]);
            } else {
                // Element v[i] is at its correct sorted location, move
                // to next element
                ++i;
            }
        }
    }

    // Examine all elements of sorted input vector, and find
    // the first missing +ve element [1, v.size()]
    for (vecSzT i = 0; i != v.size(); ++i) {
        if (v[i] != i + 1) {
            return i + 1;
        }
    }

    // No missing +ve element, so element is one beyond the vector size
    return v.size() + 1;
}
