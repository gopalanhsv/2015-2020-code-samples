// System headers
#include <vector>
#include <stdexcept>
#include <algorithm>

// Local includes
#include "apptConflict.h"

// Using declarations
using std::vector;
using std::domain_error;
using std::sort;

// Statics, locals, globals

Interval::Interval(long s, long e) : _start(s), _end(e) {
}

bool
Appointments::nonConflicting(vector<Interval> appts) {

    if (appts.empty()) {
        throw domain_error("Error! Input appointments are empty!");
    }

    // Base case of single appointment
    if (1 == appts.size()) {
        return true;
    }

    // Sort appointment intervals in ascending order of start times
    sort(appts.begin(), appts.end(), cmpIntervals);

    // Iterate over the sorted list of appointments. Any overlap
    // indicates conflicts
    vector<Interval>::size_type i = 1;
    while (i != appts.size()) {
        // Check for current appointment overlapping with previous
        if (appts[i].start() < appts[i - 1].end()) {
            return false;
        }
        ++i;
    }

    return true;
}
