#ifndef _COIN_CHANGE_H_
#define _COIN_CHANGE_H_

// System headers
#include <vector>

// Local includes

// Using declarations

// Statics, declarations and typedefs

long
numWaysToChangeCoinsBruteForce(
    const std::vector<int>& coinDenom, long amount);

long
numWaysToChangeCoinsDPMemoization(
    const std::vector<int>& coinDenom, long amount);

long
numWaysToChangeCoinsDPTabulation(
    const std::vector<int>& coinDenom, long amount);

long
numWaysToChangeCoinsDPTabulationOptimized(
    const std::vector<int>& coinDenom, long amount);

#endif /* _COIN_CHANGE_H_ */

