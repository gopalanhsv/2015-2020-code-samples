// System headers
#include <vector>
#include <stdexcept>
#include <algorithm>

// Local includes
#include "insertInterval.h"

// Using declarations
using std::vector;
using std::sort;
using std::max;
using std::min;
using std::domain_error;

// Typedefs, Statics, globals

std::vector<Interval>
InsertInterval::insert(vector<Interval>& intervals,
    const Interval& newInterval) {

    vector<Interval> newList;

    // Base case - input intervals are empty
    if (intervals.empty()) {
        newList.push_back(newInterval);
        return newList;
    }

    typedef vector<Interval>::size_type vecSzT;
    vecSzT i = 0;
    // Skip all intervals in list ending prior to new interval being inserted
    while (i != intervals.size() &&
        intervals[i].endTime() < newInterval.startTime()) {
        newList.push_back(intervals[i++]);
    }

    // Insert new interval to the list after merging it with all
    // intervals overlapping with it
    Interval merged = newInterval;
    while (i != intervals.size() &&
        intervals[i].startTime() <= newInterval.endTime()) {
        merged.setStartTime(min(merged.startTime(), intervals[i].startTime()));
        merged.setEndTime(max(merged.endTime(), intervals[i].endTime()));
        ++i;
    }
    newList.push_back(merged);

    // Add all remaining intervals commencing after the interval being inserted
    // to the list
    while (i != intervals.size()) {
        newList.push_back(intervals[i++]);
    }

    return newList;
}
