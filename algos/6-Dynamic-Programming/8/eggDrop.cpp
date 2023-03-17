// System headers
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <limits>

// Local includes
#include "eggDrop.h"

// Using declarations
using std::vector;
using std::max;
using std::min;
using std::domain_error;
using std::numeric_limits;

// Statics, typedefs, globals

// Compute the minimum number of trials required to determine
// the (critical) floor from a dropped egg breaks, given the
// building height and max eggs available
int
minTrialsForEggDropBruteForce(int nEggs, int nFloors) {
    if (nFloors < 0 || nEggs < 0) {
        throw domain_error("Error! Invalid num eggs/floors!");
    }

    // No eggs or no floors implies no trials
    if (0 == nEggs || 0 == nFloors) {
        return 0;
    }
    // 1 egg implies that egg has to be dropped from each floor from 
    // lower to higher till to determine the critical floor
    // 1 floor implies only a single drop trial
    if (1 == nEggs || 1 == nFloors) {
        return nFloors;
    }

    // If a single egg drop trial is done from say the 'k' th floor, 2
    // possibilities remain - (after 1 trial is done)
    // 1. Egg breaks, need to compute the min trials required with
    //    remaining eggs for (k - 1) floors below kth floor
    // 2. Egg doesn't break, need to compute the min trials required with
    //    all eggs for (nFloors - k) floors above kth floor
    // Max of 1 & 2 above will give trails required for kth floor,
    // min of value computed over all floors from [1, nFloors] will
    // give the min trials required after the first drop
    int nTrialsAfterFirstDrop = numeric_limits<int>::max();
    for (int k = 1; k <= nFloors; ++k) {
        int nTrailsForKthFloor =
            max(minTrialsForEggDropBruteForce(nEggs - 1, k - 1),
                minTrialsForEggDropBruteForce(nEggs, nFloors - k));
        nTrialsAfterFirstDrop =
            min(nTrialsAfterFirstDrop, nTrailsForKthFloor); 
    }

    return 1 + nTrialsAfterFirstDrop;
}

// Compute the minimum number of trials required to determine
// the (critical) floor from a dropped egg breaks, given the
// building height and max eggs available
int
minTrialsForEggDropDPMemoizationRec(int nEggs, int nFloors,
    vector<vector<int> >& lookupTbl) {
    if (nFloors < 0 || nEggs < 0) {
        throw domain_error("Error! Invalid num eggs/floors!");
    }

    // No eggs or no floors implies no trials
    if (0 == nEggs || 0 == nFloors) {
        return 0;
    }
    // 1 egg implies that egg has to be dropped from each floor from 
    // lower to higher till to determine the critical floor
    // 1 floor implies only a single drop trial
    if (1 == nEggs || 1 == nFloors) {
        return nFloors;
    }

    // Subproblem result is already precomputed and
    // populated in the lookup table
    if (-1 != lookupTbl[nEggs - 1][nFloors - 1]) {
        return lookupTbl[nEggs - 1][nFloors - 1];
    }

    // If a single egg drop trial is done from say the 'k' th floor, 2
    // possibilities remain - (after 1 trial is done)
    // 1. Egg breaks, need to compute the min trials required with
    //    remaining eggs for (k - 1) floors below kth floor
    // 2. Egg doesn't break, need to compute the min trials required with
    //    all eggs for (nFloors - k) floors above kth floor
    // Max of 1 & 2 above will give trails required for kth floor,
    // min of value computed over all floors from [1, nFloors] will
    // give the min trials required after the first drop
    int nTrialsAfterFirstDrop = numeric_limits<int>::max();
    for (int k = 1; k <= nFloors; ++k) {
        int minTrailsForKthFloor = max(
            minTrialsForEggDropDPMemoizationRec(
                nEggs - 1, k - 1, lookupTbl),
            minTrialsForEggDropDPMemoizationRec(
                nEggs, nFloors - k, lookupTbl));
        nTrialsAfterFirstDrop =
            min(nTrialsAfterFirstDrop, minTrailsForKthFloor); 
    }

    // Populate the lookup table
    lookupTbl[nEggs - 1][nFloors - 1] = 1 + nTrialsAfterFirstDrop;

    return lookupTbl[nEggs - 1][nFloors - 1];
}

// Compute the minimum number of trials required to determine
// the (critical) floor from a dropped egg breaks, given the
// building height and max eggs available
int
minTrialsForEggDropDPMemoization(int nEggs, int nFloors) {
    if (nFloors < 0 || nEggs < 0) {
        throw domain_error("Error! Invalid num eggs/floors!");
    }

    // Lookup table which gives the minimum number of trials required to
    // determine the floor from which an egg can be dropped safely, given
    // the number of eggs and building height in floors. Each entry at [r, c]
    // in the lookup table gives the min number of trials for
    // r+1 eggs, c + 1 floors
    vector<vector<int> >
        lookupTbl(nEggs, std::vector<int>(nFloors, -1));

    return minTrialsForEggDropDPMemoizationRec(nEggs, nFloors, lookupTbl);
}

// Compute the minimum number of trials required to determine
// the (critical) floor from a dropped egg breaks, given the
// building height and max eggs available
int
minTrialsForEggDropDPTabulation(int nEggs, int nFloors) {
    if (nFloors < 0 || nEggs < 0) {
        throw domain_error("Error! Invalid num eggs/floors!");
    }

    // Base case
    // No eggs or no floors imply 0 trials
    if (0 == nEggs || 0 == nFloors) {
        return 0;
    }

    // Lookup table which gives the minimum number of trials required to
    // determine the floor from which an egg can be dropped safely, given
    // the number of eggs and building height in floors. Each entry at [r, c]
    // in the lookup table gives the min number of trials for
    // r eggs, c floors
    vector<vector<int> >
        lookupTbl(nEggs + 1, std::vector<int>(nFloors + 1, 0));

    // 1 egg implies that the min number of trials would be the number
    // of floors since the egg drop trial has to done from 1st to floor id
    typedef vector<int>::size_type vecSzT;
    for (vecSzT f = 1; f != nFloors + 1; ++f) {
        lookupTbl[1][f] = f;
    } 
    // 1 floor implies that the min number of trials would be 1
    typedef vector<vector<int> >::size_type vecVecSzT;
    for (vecVecSzT e = 1; e != nEggs + 1; ++e) {
        lookupTbl[e][1] = 1;
    } 

    // Iterate over all possible number of eggs and floors
    for (vecVecSzT e = 2; e != nEggs + 1; ++e) {
        for (vecSzT f = 2; f != nFloors + 1; ++f) {
            lookupTbl[e][f] = numeric_limits<int>::max();
            // If a single egg drop trial is done from say the 'k'th floor, 2
            // possibilities remain - (after 1 trial is done)
            // 1. Egg breaks, compute the min trials required with
            //    remaining eggs for (k - 1) floors below kth floor
            // 2. Egg doesn't break, need to compute the min trials required
            //    with all eggs for (f - k) floors above kth floor
            // Max of 1 & 2 above will give trails required for kth floor,
            // min of value computed over all floors from [1, nFloors] will
            // give the min trials required after the first drop
            for (int k = 1; k <= f; ++k) {
                lookupTbl[e][f] = min(
                    lookupTbl[e][f],
                    1 + max(lookupTbl[e - 1][k - 1], lookupTbl[e][f - k]));
            }
        }
    }

    return lookupTbl[nEggs][nFloors];
}
