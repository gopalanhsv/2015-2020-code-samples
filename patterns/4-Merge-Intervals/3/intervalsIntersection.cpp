// System headers
#include <vector>
#include <stdexcept>
#include <algorithm>

// Local includes
#include "intervalsIntersection.h"

// Using declarations
using std::vector;
using std::domain_error;
using std::max;
using std::min;

// Statics, locals, globals

Interval::Interval(long s, long e) : _start(s), _end(e) {
}

vector<Interval>
Intervals::findIntersectionSet(const vector<Interval>& intervals1,
    const vector<Interval>& intervals2) {

    if (intervals1.empty() && intervals2.empty()) {
        throw domain_error("Error! Both input intervals sets are empty!");
    }

    if (intervals1.empty()) {
        return intervals2;
    }

    if (intervals2.empty()) {
        return intervals1;
    }

    vector<Interval> intersection;
    // Examine both the lists of intervals sequentially
    typedef vector<Interval>::size_type vecSzT;
    vecSzT i = 0, j = 0;
    while (i != intervals1.size() && j != intervals2.size()) {
        // Check for overlap between the intervals indicated by i & j
        const Interval& a = intervals1[i];
        const Interval& b = intervals2[j];
        // Overlap when either of intervals start time is within others' range
        if ((b.start() >= a.start() && b.start() <= a.end()) ||
            (a.start() >= b.start() && a.start() <= b.end())) {
            // Overlap between a & b, add the overlapped
            // portion to intersection list
            Interval merged(max(a.start(), b.start()), min(a.end(), b.end()));
            intersection.push_back(merged);
        }

        // Move to the next entry in the particular interval list
        // where the current interval ends earlier
        if (a.end() < b.end()) {
            ++i;
        } else {
            ++j;
        }
    }

    return intersection;
}
