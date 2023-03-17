#ifndef _PARTITION_INTEGER_SET_H_
#define _PARTITION_INTEGER_SET_H_

// System headers
#include <vector>

// Local includes

// Using declarations

// Statics, globals, typedefs
typedef std::vector<int>::size_type vecSzT;
typedef std::vector<std::vector<int> >::size_type vecVecSzT;

bool twoEqualSumSubsetRecursive(const std::vector<int>& v);

bool twoEqualSumSubsetsUsingDPMemoization(const std::vector<int>& v);

bool twoEqualSumSubsetsUsingDPTabulation(const std::vector<int>& v);

#endif /* _PARTITION_INTEGER_SET_H_ */
