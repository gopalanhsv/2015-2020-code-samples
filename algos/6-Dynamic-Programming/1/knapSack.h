#ifndef _KNAPSACK_H_
#define _KNAPSACK_H_

// System headers
#include <vector>

// Local includes

// Using declarations

// Statics, typedefs, globals
typedef std::vector<int>::size_type vecSzT;
typedef std::vector<std::vector<int> >::size_type vecVecSzT;

int
maxValueOfknapsackRecursive(const std::vector<int>& itemCosts,
    const std::vector<int>& itemWts, int capacity);

int
maxValueOfknapsackRecursiveDPMemoization(const std::vector<int>& itemCosts,
    const std::vector<int>& itemWts, int capacity);

int
maxValueOfknapsackDPTabulation(const std::vector<int>& itemCosts,
    const std::vector<int>& itemWts, int capacity);

#endif /* _KNAPSACK_H_ */
