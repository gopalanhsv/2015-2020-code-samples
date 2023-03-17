// System headers
#include <vector>
#include <stdexcept>
#include <algorithm>

// Local includes
#include "missingNumbers.h"

// Using declarations
using std::vector;
using std::domain_error;
using std::swap;

// Statics, globals, typedefs

// Vector has elements in range [1, v.size() + 1], but only
// several element duplicated (several numbers missing)
vector<int>
MultiMissingNumbers::findAllMissingNums(vector<int> v) {
    if (v.empty()) {
        throw domain_error("Error! Empty input vec!");
    }

    typedef vector<int>::size_type vecSzT;

    // Iterate over all indices/elements of given vector
    // and sort them to correct location using cyclic sort
    vecSzT i = 0;
    while (i != v.size()) {
        // Element value[i] - 1 gives sorted location
        // since storing [1, v.size()]
        vecSzT correctIdx = v[i] - 1;
        // If the element at i is not at its correct sorted location
        // (Check for correctIdx is done as n len vec may be holding
        // which should ideally contain 1 to n may end up holding
        // value n 
        if (v[i] != v[correctIdx]) {
            // If the current element at i is not at its correct sorted location,
            // move the element to its correct sorted location by swapping
            // the elements at index i with correctIdx
            swap(v[i], v[correctIdx]);
        } else {
            // Element at index 'i' is at its correct sorted
            // location. Move to next element
            ++i;
        }
    }

    // Scan vector and find all elements which are not in their
    // sorted locations. Those would would be missing numbers
    vector<int> missing;
    for (vecSzT i = 0; i != v.size(); ++i) {
        if (i + 1 != v[i]) { // Due to [1, v.size()] range
            missing.push_back(i + 1);
        }
    }
    return missing;
}
