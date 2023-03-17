// System includes
#include <vector>
#include <stdexcept>

// Local includes
#include "average.h"

// Using declarations
using std::vector;
using std::domain_error;

double
average(vector<double> v) {
    if (0 == v.size()) {
        throw domain_error("Error! Average of empty vector!");
    }

    // Compute the average and return
    double sum = 0.0;
    for (vector<double>::size_type i = 0; i != v.size(); ++i)
        sum += v[i];
    return sum / v.size();
}
