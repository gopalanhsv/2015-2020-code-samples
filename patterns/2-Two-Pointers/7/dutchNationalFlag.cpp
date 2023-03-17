// System headers
#include <vector>
#include <stdexcept>
#include <algorithm>

// Local includes
#include "dutchNationalFlag.h"

// Using declarations
using std::vector;
using std::domain_error;
using std::swap;

// Statics, typedefs, globals

void
DutchNationalFlag::sort(vector<int>& v) {
    if (v.empty()) {
        throw domain_error("Error! Empty input vector!");
    }

    typedef vector<int>::size_type vecSzT;
    vecSzT l = 0, h = v.size() - 1;
    // Iterate over all elements of the vector sequentially
    // Arrange the elements pointed to by indices l, h, i such that
    // 0's are located in [0, l), 2's in range (h, ..) and 
    // 1's in range [l, i)
    for (vecSzT i = 0; i <= h;) {
        if (v[i] == 2) {
            // Current value is 2, move to location indicated by ptr h
            // Reduce 'h' but dont change 'i' as 'i' may now have 0/1/2
            swap(v[h--], v[i]);
        } else if (v[i] == 0) {
            // Current value is 0, move to location indicated by ptr l
            // Increment 'l' & 'i' as 'i' may be 0/1
            swap(v[l++], v[i++]);
        } else if (v[i] == 1) {
            ++i;
        } else {
            throw domain_error("Error! Array has elemets other than 0/1/2!");
        }
    }
}
