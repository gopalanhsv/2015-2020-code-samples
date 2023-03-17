#ifndef _FIND_PLATFORMS_H_
#define _FIND_PLATFORMS_H_

// System headers
#include <vector>

// Local includes

// Using declarations

// Typedefs, statics and globals

int
computePlatformsNeededUsingBruteForce(
    std::vector<int> arrival, std::vector<int> departure);

int
computePlatformsNeededUsingGreedyMethod1(
    std::vector<int> arrival, std::vector<int> departure);

int
computePlatformsNeededUsingGreedyMethod2(
    std::vector<int> arrival, std::vector<int> departure);

#endif /* _FIND_PLATFORMS_H_ */
