// System headers
#include <vector>
#include <stdexcept>
#include <algorithm>

// Local includes
#include "removeDuplicates.h"

// Static, globals, typedefs

// Using declarations
using std::vector;
using std::sort;
using std::domain_error;

std::vector<int>
RemoveDuplicates::remove(std::vector<int>& v) {
    if (v.empty()) {
        throw domain_error("Error! Empty input vector!");
    }

    // Sort the vector so that duplicates sit next to each other
    sort(v.begin(), v.end());

    typedef vector<int>::size_type vecSzT;
    vecSzT writePtr = 1;
    // Iterate over all the elements of the vector. Maintain a
    // write ptr for non writing non-duplicate elements; and a
    // read ptr for examing every vector element
    for (vecSzT readPtr = 1; readPtr != v.size(); ++readPtr) {
        // If currently read element in a new element and not
        // a duplicate of previously written non-dup element,
        // write it as non duplicate and advance write ptr
        if (v[readPtr] != v[writePtr - 1]) {
            v[writePtr++] = v[readPtr];
        }
    }

    // Erase all duplicated unnecessary elements at end of vector
    v.erase(v.begin() + writePtr, v.end());
    return v;
}
