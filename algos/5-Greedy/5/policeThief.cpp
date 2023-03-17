// System headers
#include <vector>
#include <stdexcept>
#include <cmath>
#include <algorithm>

// Local includes
#include "policeThief.h"

// Using declarations
using std::vector;
using std::domain_error;
using std::abs;
using std::sort;

// Statics, typedefs, globals
typedef vector<int>::size_type vecSzT;

inline bool
isPoliceman(char c) {
    return c == 'P';
}

inline bool
isThief(char c) {
    return c == 'T';
}

inline void
updatePolicemanCaughtThief(
    vector<int>& ptCaughtStatus, vecSzT p, vecSzT t) {
    ptCaughtStatus[p] = 1;
    ptCaughtStatus[t] = 1;
}

inline bool
thiefCaught(vector<int>& ptCaughtStatus, vecSzT t) {
    return ptCaughtStatus[t] == 1;
}

inline bool
policemanCaught(vector<int>& ptCaughtStatus, vecSzT p) {
    return ptCaughtStatus[p] == 1;
}

int
maxThievesWhoCanBeCaughtByPoliceBruteForce(
    const vector<char>& ptLocVec, int maxDist) {
    if (ptLocVec.empty()) {
        throw domain_error("Error! Empty police theif location vec!");
    }
    if (maxDist <= 0) {
        throw domain_error("Error! Invalid max distance between P & T!");
    }

    // Num of police + thieves
    vecSzT n = ptLocVec.size();
    // Indicates which police & thief are done/out of commission
    // i.e. if a policeman catches a thief, corresponding index
    // location in below marked as true/1, otherwise false/0
    vector<int> ptStatus(ptLocVec.size(), 0);

    // Iterate over entire police thief vector, halting to examine each
    // policeman who is yet to catch a thief
    int nThievesCaught = 0;
    for (vecSzT p = 0; p != n; ++p) {

        // Skip thieves or a policeman who has already caught a thief
        if (!isPoliceman(ptLocVec[p]) || policemanCaught(ptStatus, p)) {
            continue;
        }

        // Check if a uncaught thief is found within 'maxDist'
        // of current policeman

        // Check for uncaught thief 'maxDist' indices backward in vector
        if (0 != p) {
            // Search from left to right (to catch any thief farthest
            // from current policeman)
            vecSzT t = (p > maxDist) ? p - maxDist : 0;
            for (; t <= p - 1; ++t) {
                if (!isThief(ptLocVec[t]) || thiefCaught(ptStatus, t)) {
                    continue;
                }
                // Found a thief within distance 'maxDist' who is yet to
                // be caught.
                updatePolicemanCaughtThief(ptStatus, p, t);
                ++nThievesCaught;
                break;
            }
        }

        // Skip check for uncaught thieves in forward direction if
        // the policeman has already caught a thief
        if (policemanCaught(ptStatus, p)) {
            continue;
        }

        // Check for uncaught thief 'maxDist' indices forward in vector
        for (vecSzT t = p + 1; t <= p + maxDist && t < n; ++t) {
            if (!isThief(ptLocVec[t]) || thiefCaught(ptStatus, t)) {
                continue;
            }
            // Found a thief within distance 'maxDist' who is yet to
            // be caught.
            updatePolicemanCaughtThief(ptStatus, p, t);
            ++nThievesCaught;
            break;
        }
    }

    return nThievesCaught;
}

int
maxThievesWhoCanBeCaughtByPoliceGreedy(
    const vector<char>& ptLocVec, int maxDist) {
    if (ptLocVec.empty()) {
        throw domain_error("Error! Empty police theif location vec!");
    }
    if (maxDist <= 0) {
        throw domain_error("Error! Invalid max distance between P & T!");
    }

    typedef vector<char>::size_type vecSzT;
    // Store the location indices of available policemen and thieves
    vector<vecSzT> policeLoc;
    vector<vecSzT> thiefLoc;
    for (vecSzT i = 0; i != ptLocVec.size(); ++i) {
        if (isPoliceman(ptLocVec[i])) {
            policeLoc.push_back(i);
        } else if (isThief(ptLocVec[i])) {
            thiefLoc.push_back(i);
        } else {
            throw domain_error("Error! Invalid PT location vector!");
        }
    }

    // Sort the location indices vector in ascending order
    sort(policeLoc.begin(), policeLoc.end());
    sort(thiefLoc.begin(), thiefLoc.end());

    int nThievesCaught = 0;

    // Now examine the location indices vector of policemen and thieves
    // in ascending order, greedily assigning the first available
    // policeman to the first available thief as per maxDist
    // constraint (like in mergesort)
    typedef vector<vecSzT>::size_type vecVecSzT;
    vecVecSzT p = 0;
    vecVecSzT t = 0;
    while (p != policeLoc.size() && t != thiefLoc.size()) {
        if (abs((int)policeLoc[p] - (int)thiefLoc[t]) <= maxDist) {
            // Able to assign policeman to catch thief
            ++nThievesCaught;
            ++p;
            ++t;
        } else if (policeLoc[p] < thiefLoc[t]) {
            // First available policeman located prior to first uncaught thief
            // Unable to assign policeman to catch first uncaught thief
            // due to distance constraint. Advance to next policeman.
            ++p;
        } else {
            // First uncaught thief located prior to first available policeman
            // Unable to assign policeman to catch first uncaught thief
            // due to distance constraint. Advance to next thief.
            ++t;
        }
    }

    return nThievesCaught;
}
