// System headers
#include <vector>
#include <stdexcept>

// Local includes
#include "coinChange.h"

// Using declarations
using std::vector;
using std::domain_error;

// Statics, declarations and typedefs
typedef vector<int>::size_type vecSzT;
typedef vector<vector<int> >::size_type vecVecSzT;

long
numWaysToChangeCoinsBruteForceRecursive(
    const vector<int>& coinDenom, vecSzT denomIdx, long amount) {
    // Base case, amount 0 implies 1 way to change coins 
    // (by using no coins at all)
    if (0 == amount) {
        return 1;
    }
    // Base case (all coin denominations examined except the first
    // one) implies either single (if coin denomination can completely
    // be used to change amount) or no way to change coins 
    if (0 == denomIdx) {
        return (amount % coinDenom[denomIdx] == 0) ? 1 : 0;
    }

    // Number of ways to get specified amount changed considering the
    // 1st denomIdx coin denominations in coinDenom, is the
    // sum of the following 2 counts
    // 1. Num ways including the coin at denomIdx (using appropriately
    //    reduced amount with all coins in [0, denomIdx] )
    long nWays = 0;
    int currCoinDenom = coinDenom[denomIdx];
    if (amount >= currCoinDenom) {
        nWays = numWaysToChangeCoinsBruteForceRecursive(
            coinDenom, denomIdx, amount - currCoinDenom);
    }
    // 2. Num ways excluding the coin at denomIdx (using the same amount
    //    with earlier coins in [0, denomIdx) )
    if (denomIdx > 0) {
        nWays += numWaysToChangeCoinsBruteForceRecursive(
            coinDenom, denomIdx - 1, amount);
    }

    return nWays;
}

long
numWaysToChangeCoinsBruteForce(const vector<int>& coinDenom, long amount) {
    if (coinDenom.empty() || amount < 0) {
        throw domain_error("Error! Invalid input vec or invalid amount!");
    }

    return numWaysToChangeCoinsBruteForceRecursive(
        coinDenom, coinDenom.size() - 1, amount);
}

long
numWaysToChangeCoinsDPMemoizationRecursive(const vector<int>& coinDenom,
    vecSzT denomIdx, vector<vector<int> >& lookupTbl, long amount) {

    // Base case, amount 0 implies 1 way to change coins 
    // (by using no coins at all)
    if (0 == amount) {
        return 1;
    }
    // Base case (all coin denominations examined except the first
    // one) implies either single (if coin denomination can completely
    // be used to change amount) or no way to change coins 
    if (0 == denomIdx) {
        return (amount % coinDenom[denomIdx] == 0) ? 1 : 0;
    }

    // Check the lookup table for a valid entry
    if (lookupTbl[denomIdx][amount] != -1) {
        return lookupTbl[denomIdx][amount];
    }

    // Number of ways to get specified amount changed considering the
    // 1st denomIdx coin denominations in coinDenom, is the
    // sum of the following 2 counts
    // 1. Num ways including the coin at denomIdx (using appropriately
    //    reduced amount with all coins in [0, denomIdx] )
    int nWays = 0;
    int currCoinDenom = coinDenom[denomIdx];
    if (amount >= currCoinDenom) {
        nWays = numWaysToChangeCoinsDPMemoizationRecursive(
            coinDenom, denomIdx, lookupTbl, amount - currCoinDenom);
    }
    // 2. Num ways excluding the coin at denomIdx (using the same amount
    //    with earlier coins in [0, denomIdx) )
    if (denomIdx > 0) {
        nWays += numWaysToChangeCoinsDPMemoizationRecursive(
            coinDenom, denomIdx - 1, lookupTbl, amount);
    }

    // Update the lookup table
    lookupTbl[denomIdx][amount] = nWays;

    return nWays;
}

long
numWaysToChangeCoinsDPMemoization(const vector<int>& coinDenom, long amount) {
    if (coinDenom.empty() || amount < 0) {
        throw domain_error("Error! Invalid input vec or invalid amount!");
    }

    // Lookup table giving the number of ways a particular amount can be
    // changed using the coins specified in the coin denomination table
    // The column index represent the amount to be changed and row index 'r'
    // specifies that the 1st r denominations can be used for coin changing.
    // So value of the lookup table at a particular [r, c] implies the number
    // of ways amount 'c' can be changed using the 1st 'r' coin denominations 
    vector<vector<int> > lookupTbl(
        coinDenom.size(), vector<int>(amount + 1, -1));

    return numWaysToChangeCoinsDPMemoizationRecursive(
        coinDenom, coinDenom.size() - 1, lookupTbl, amount);
}

long
numWaysToChangeCoinsDPTabulation(const vector<int>& coinDenom, long amount) {
    if (coinDenom.empty() || amount < 0) {
        throw domain_error("Error! Invalid input vec or invalid amount!");
    }

    // Base case, amount 0 implies 1 way to change coins 
    // (by using no coins at all)
    if (0 == amount) {
        return 1;
    }

    // Lookup table giving the number of ways a particular amount can be
    // changed using the coins specified in the coin denomination table
    // The column index represent the amount to be changed and row index 'r'
    // specifies that the 1st r denominations can be used for coin changing.
    // So value of the lookup table at a particular [r, c] implies the number
    // of ways amount 'c' can be changed using the 1st 'r' coin denominations 
    vector<vector<int> > dpTbl(
        coinDenom.size(), vector<int>(amount + 1, -1));

    // Num ways to change coins for 0 amount is 1 for all types of coin
    // (by using no coins)
    for (vecVecSzT cdi = 0; cdi != coinDenom.size(); ++cdi) {
        dpTbl[cdi][0] = 1;
    }

    // Iterate over all possible coin denominations and for all
    // amounts upto specified amount to be changed
    for (vecVecSzT cdi = 0; cdi != coinDenom.size(); ++cdi) {
        for (vecSzT amt = 1; amt != amount + 1; ++amt) {
            // Number of ways to get an amount changed considering the
            // 1st cdi coin denominations in coinDenom, is the
            // sum of the following 2 counts
            // 1. Num ways including the coin at cdi (using appropriately
            //    reduced amount with all coins in [0, cdi] )
            int nWaysInc =
                (amt >= coinDenom[cdi]) ? dpTbl[cdi][amt - coinDenom[cdi]] : 0;

            // 2. Num ways excluding the coin at cdi (using the same amount
            //    with earlier coins in [0, cdi) )
            int nWaysExc = (cdi > 0) ? dpTbl[cdi - 1][amt] : 0;

            dpTbl[cdi][amt] = nWaysInc + nWaysExc;
        }
    }

    return dpTbl[coinDenom.size() - 1][amount];
}

long
numWaysToChangeCoinsDPTabulationOptimized(
    const vector<int>& coinDenom, long amount) {
    if (coinDenom.empty() || amount < 0) {
        throw domain_error("Error! Invalid input vec or invalid amount!");
    }

    // Base case, amount 0 implies 1 way to change coins 
    // (by using no coins at all)
    if (0 == amount) {
        return 1;
    }

    // Lookup table giving the number of ways a particular amount can be
    // changed using given coin denominations
    // Value of lookup table at a row 'r' represent the num of ways the 
    // amount 'r' can be changed using given coin denominations
    vector<int> dpTbl(amount + 1, 0);

    // Num ways to change coins for 0 amount is 1 for all types of coin
    // (by using no coins)
    dpTbl[0] = 1;

    // Iterate over all possible coin denominations and for all
    // amounts upto specified amount to be changed
    for (vecSzT cdi = 0; cdi != coinDenom.size(); ++cdi) {
        int currCoinDenom = coinDenom[cdi];
        // Iterate over all possible amounts which can be changed
        // using using the current coin denomination (the amounts
        // which can have the current denomination as a part)
        for (vecSzT amt = currCoinDenom; amt <= amount; ++amt) {
            // Number of ways an amount can include only the current coin
            // denomination is equivalent to the number of ways in which
            // the remainder amount after excluding the current coin can
            // include the various coin denominations


            // So total num ways for a given amount with all possible
            // coin denominations has to add above to its current value
            dpTbl[amt] = dpTbl[amt] + dpTbl[amt - currCoinDenom];
        }
    }

    return dpTbl[amount];
}
