// System headers
#include <algorithm>
#include <stdexcept>
#include <vector>

// Local includes
#include "median.h"

// Using declarations
using std::vector;
using std::sort;
using std::domain_error;

// Typedefs
typedef vector<double>::size_type vecSzT;

double
median(vector<double> v) {
    if (0 == v.size())
        throw domain_error("Median of empty vector");

    sort(v.begin(), v.end());

    vecSzT mid = v.size() / 2;

    return ((0 == v.size() % 2) ? (v[mid-1] + v[mid]) / 2 : v[mid]);
}
