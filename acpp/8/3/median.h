#ifndef _MEDIAN_H_
#define _MEDIAN_H_

// System headers
#include <algorithm>
#include <iterator>

template<typename RanIterT>
typename std::iterator_traits<RanIterT>::value_type
median(RanIterT beg, RanIterT end) {
    if (beg == end) {
        throw std::domain_error("Error! Median of empty vector! Exiting...!");
    }
    unsigned long size = end - beg;
    std::sort(beg, end);
    RanIterT mid = beg + size / 2;
    return (0 == size % 2) ? (*(mid - 1) + *mid) / 2: *mid;
}

#endif /* _MEDIAN_H_ */
