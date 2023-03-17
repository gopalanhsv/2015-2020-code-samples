// System headers
#include <vector>
#include <numeric>

// Local includes
#include "average.h"

// Using declarations
using std::vector;
using std::accumulate;

// Typedefs

double
average(const vector<double>& v) {
    if (0 != v.size())
        return accumulate(v.begin(), v.end(), 0.0) / v.size();

    return 0.0;
}
