#ifndef _MERGE_INTERVALS_H_
#define _MERGE_INTERVALS_H_

// System headers
#include <vector>

// Local includes

// Using declarations

// Typedefs, Statics, globals

class Interval {
private:
    Interval();

public:
    // Constructors
    Interval(long s, long e) {
        _start = s;
        _end = e;
    }

    long _start;
    long _end;
};

class MergeIntervals {
public:
    static std::vector<Interval>
    merge(std::vector<Interval> intervals);
};

#endif /* _MERGE_INTERVALS_H_ */
