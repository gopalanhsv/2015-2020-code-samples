// System includes
#include <vector>
#include <algorithm>
#include <stdexcept>

// Local includes
#include "median.h"

// Using declarations
using std::vector;
using std::sort;
using std::domain_error;

double
median(vector<double> v) {
    if (0 == v.size()) {
        throw domain_error("Error! Median of empty vector!");
    }
    // Sort the vector in non decreasing order
    sort(v.begin(), v.end());

    // Compute the median and return
    vector<double>::size_type mid = v.size() / 2;
    return (0 == v.size() % 2) ? 
                (v[mid - 1] + v[mid]) / 2 : v[mid]; 
}
