#ifndef _MAX_SUBARRAY_SUM_H_
#define _MAX_SUBARRAY_SUM_H_

// System headers
#include <vector>

// Local includes

// Using declarations

// Statics, typedefs, globals
typedef std::vector<int>::size_type vecSzT;

int
maxSumOfSubArraysBruteForce(const std::vector<int>& v);

int
maxSumOfSubArraysDivAndConquer(const std::vector<int>& v);

int
maxSumOfSubArraysDP(const std::vector<int>& v);

#endif /* _MAX_SUBARRAY_SUM_H_ */
