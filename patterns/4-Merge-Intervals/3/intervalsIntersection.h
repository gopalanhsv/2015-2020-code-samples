#ifndef _INTERVALS_INTERSECTION_H_
#define _INTERVALS_INTERSECTION_H_

// System headers
#include <vector>

class Interval {
public:
    Interval(long s, long e);

    inline long start() const { return _start; }
    inline long end() const { return _end; }
    inline void setStart(long s) { _start = s; }
    inline void setEnd(long e) { _end = e; }

private:
    Interval();

    long _start;
    long _end;
};

inline bool
cmpIntervals(const Interval& i1, const Interval& i2) {
    return i1.start() < i2.start();
}

class Intervals {
public:
    static std::vector<Interval>
    findIntersectionSet(const std::vector<Interval>& intervals1,
        const std::vector<Interval>& intervals2);
};

#endif /* _INTERVALS_INTERSECTION_H_ */
