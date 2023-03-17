// System headers
#include <vector>
#include <algorithm>
#include <stdexcept>

// Local includes
#include "maxWaterVol.h"

// Using declarations
using std::vector;
using std::domain_error;
using std::max;

// Statics, typedefs, globals
typedef vector<int>::size_type vecSzT;

unsigned long
MaxWaterVolume::compute(const vector<int>& heightsV) {

    if (heightsV.size() < 2) {
        throw domain_error("Error! Invalid input vector!");
    }

    // Start with two pointers at the ends of the building vector
    // Determine volume of water which can be stored between the
    // current buildings indexed by pointers. Update the max volume
    // if current calculated volume is more. Advance the pointer which
    // points to lower building 1 step ahead (in order to see if
    // higher building implying more water volume storage can be found)
    unsigned long maxVol = 0;
    vecSzT lo = 0, hi = heightsV.size() - 1;
    // Till the tow pointers dont cross over
    while (lo < hi) {
        // Init current vol to distance between the buildings indicated
        // by the two pointers. Find smaller building and use its height
        // to compute the volume of water which can be stored between
        // the two buildings (lower height determines volume)
        unsigned long currentVol = hi - lo;
        if (heightsV[lo] < heightsV[hi]) {
            currentVol *= heightsV[lo];
            ++lo;
        } else {
            currentVol *= heightsV[hi];
            --hi;
        }

        // Update max volume
        maxVol = max(maxVol, currentVol);
    }

    return maxVol;
}
