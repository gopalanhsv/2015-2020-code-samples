#ifndef _ARRAY_H_
#define _ARRAY_H_

// System headers
#include <vector>

class Array {
public:
    static std::vector<double> avgOfContiguousSubArraysBruteForce(
        const std::vector<int>& v, std::vector<int>::size_type subArrSz);

    static std::vector<double> avgOfContiguousSubArraysSlidingWindow(
        const std::vector<int>& v, std::vector<int>::size_type subArrSz);
private:
};

#endif /* _ARRAY_H_ */
