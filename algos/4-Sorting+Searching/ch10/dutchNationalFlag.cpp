// System headers
#include <vector>
#include <stdexcept>
#include <algorithm>

// Local includes

// Using declarations
using std::vector;
using std::domain_error;
using std::runtime_error;
using std::swap;

// Statics, typedefs, globals

void
dutchNationalFlag(vector<int>& v) {
    if (v.empty()) {
        throw domain_error("Error! Empty input vector!");
    }

    typedef vector<int>::size_type vecSzT;
    // Have three indexes
    // write index ptr0 which points where next 0 is to be written
    // write index ptr2 which points where next 2 is to be written
    // read index at mid in between ptr0 & ptr2 used to read values
    // of either 0 or 2 in between ptr2 & ptr0 and swap them to appropriate
    // write locations
    vecSzT ptr0 = 0;
    vecSzT mid = 0;
    vecSzT ptr2 = v.size() - 1;

    while (mid <= ptr2) {
        if (v[mid] == 2) {
            swap(v[mid], v[ptr2]);
            if (ptr2 == 0) {
                break;
            } else {
                --ptr2;
            }
        } else if (v[mid] == 0) {
            swap(v[mid], v[ptr0]);
            ++ptr0;
            ++mid;
        } else if (v[mid] == 1) {
            ++mid;
        } else {
            throw runtime_error("Error! Encountered element which is neither 0/1/2");
        }
    }
}
