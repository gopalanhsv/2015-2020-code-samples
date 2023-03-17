#ifndef _POLICE_THIEF_H_
#define _POLICE_THIEF_H_

// System headers
#include <vector>

// Local includes

// Using declarations

int
maxThievesWhoCanBeCaughtByPoliceBruteForce(
    const std::vector<char>& ptLocVec, int maxDist);

int
maxThievesWhoCanBeCaughtByPoliceGreedy(
    const std::vector<char>& ptLocVec, int maxDist);

#endif /* _POLICE_THIEF_H_ */
