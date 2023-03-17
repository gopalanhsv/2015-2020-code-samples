#ifndef _INSERT_INTERVAL_H_
#define _INSERT_INTERVAL_H_

// System headers
#include <vector>

// Local includes

// Using declarations

// Typedefs, Statics, globals

class Interval {
public:
    // Constructors
    Interval(long s, long e) {
        _start = s;
        _end = e;
    }

    inline long startTime() const { return _start; }
    inline long endTime() const { return _end; }
    inline long setStartTime(long s) { _start = s; }
    inline long setEndTime(long e) { _end = e; }

private:
    Interval();

    long _start;
    long _end;
};

inline bool
cmpStartTimes(const Interval& i1, const Interval& i2) {
    return i1.startTime() < i2.startTime();
}

class InsertInterval {
public:
    static std::vector<Interval>
    insert(std::vector<Interval>& intervals, const Interval& newInterval);
};

#endif /* _INSERT_INTERVAL_H_ */
