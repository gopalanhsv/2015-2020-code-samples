// System headers
#include <vector>
#include <stdexcept>
#include <algorithm>

// Local includes
#include "mergeIntervals.h"

// Using declarations
using std::vector;
using std::sort;
using std::max;
using std::domain_error;

// Typedefs, Statics, globals

bool
cmpStartTimes(const Interval& i1, const Interval& i2) {
    return i1._start < i2._start;
}

std::vector<Interval>
MergeIntervals::merge(vector<Interval> intervals) {
    if (intervals.empty()) {
        throw domain_error("Error! Empty input vec!");
    }

    // Base case single element vector
    if (1 == intervals.size()) {
        return intervals;
    }

    // Sort all the intervals in ascending order of start times
    sort(intervals.begin(), intervals.end(), cmpStartTimes);

    vector<Interval> merged;
    long prevStart = intervals[0]._start;
    long prevEnd = intervals[0]._end;
    // Examine all intervals in the order of ascending start times
    for (vector<Interval>::size_type i = 1; i != intervals.size(); ++i) {
        long currStart = intervals[i]._start;
        long currEnd = intervals[i]._end;
        if (currStart >= prevEnd) {
            // Non-overlapping current interval
            // Add previous interval to merged list
            merged.push_back({prevStart, prevEnd});
            // Adjust previous interval start time
            prevStart = currStart;
            prevEnd = currEnd;
        } else {
            // Overlapping current interval, start time unchanged
            // Adjust previous interval end time to max
            prevEnd = max(currEnd, prevEnd);
        }
    }

    // Add last remaining interval to merged list
    merged.push_back({prevStart, prevEnd});

    return merged;
}
