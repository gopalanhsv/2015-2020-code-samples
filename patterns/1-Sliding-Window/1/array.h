#ifndef _ARRAY_H_
#define _ARRAY_H_

// System headers
#include <vector>

class Array {
public:
    static unsigned maxSumOfContiguousSubarrays(
        const std::vector<int>& v,
        std::vector<int>::size_type subArrSz);
};

#endif /* _ARRAY_H_ */
