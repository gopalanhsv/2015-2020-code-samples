// System headers
#include <vector>
#include <map>
#include <algorithm>
#include <stdexcept>

// Local includes
#include "findPlatforms.h"

// Using declarations
using std::vector;
using std::multimap;
using std::make_pair;
using std::domain_error;
using std::sort;

// Typedefs, statics and globals

int
computePlatformsNeededUsingBruteForce(
    vector<int> arrival, vector<int> departure) {

    if (arrival.empty() || departure.empty()) {
        throw domain_error("Error! Empty input vec! Exiting...!");
    }
    if (arrival.size() != departure.size()) {
        throw domain_error("Error! Size mismatch between arrival and"
            " departure vec! Exiting...!");
    }

    typedef vector<int>::size_type vecSzT;
    // Compute the number of plaforms required by finding the
    // overlapping [arrival, departure] time intervals by considering
    // a train being stationary at a platform; and determining the other
    // trains which arrive at the station while the train is there
    int minPlatformsReqd = 1;
    for (vecSzT trnAtStn = 0; trnAtStn != arrival.size(); ++trnAtStn) {
        int platformsReqd = 1;
        // Determine other trains which arrive with train "trnAtStn"
        for (vecSzT otherTrn = 0; otherTrn != arrival.size(); ++otherTrn) {
            if (trnAtStn != otherTrn) {
                if (arrival[otherTrn] >= departure[trnAtStn] ||
                    departure[otherTrn] <= arrival[trnAtStn]) {
                    // Skip trains departing earlier/arriving later
                    // than train at station
                    continue;
                } 
                ++platformsReqd;
                if (platformsReqd > minPlatformsReqd) {
                    minPlatformsReqd = platformsReqd;
                }
            }
        }
    }
    return minPlatformsReqd;
}

int
computePlatformsNeededUsingGreedyMethod1(
    vector<int> arrival, vector<int> departure) {

    if (arrival.empty() || departure.empty()) {
        throw domain_error("Error! Empty input vec! Exiting...!");
    }
    if (arrival.size() != departure.size()) {
        throw domain_error("Error! Size mismatch between arrival and"
            " departure vec! Exiting...!");
    }

    // Sort the arrival and departure time vectors in order of
    // increasing time
    sort(arrival.begin(), arrival.end());
    sort(departure.begin(), departure.end());

    typedef vector<int>::size_type vecSzT;
    vecSzT i = 0, j = 0;
    int nPlatforms = 0;
    int minPlatforms = 0;
    // Examine the arrival and departure events in the order of increasing
    // time magnitudes together
    while (i != arrival.size() && j != departure.size()) {
        if (arrival[i] <= departure[j]) {
            // Arrival prior to a departure, requires one more platform
            ++nPlatforms;
            // Update minimum platforms required
            if (nPlatforms > minPlatforms) {
                minPlatforms = nPlatforms;
            }
            ++i;
        } else {
            // Departure prior to an arrival, requires one less platform
            --nPlatforms;
            ++j;
        }
    }

    return minPlatforms;
}

int
computePlatformsNeededUsingGreedyMethod2(
    vector<int> arrival, vector<int> departure) {

    if (arrival.empty() || departure.empty()) {
        throw domain_error("Error! Empty input vec! Exiting...!");
    }
    if (arrival.size() != departure.size()) {
        throw domain_error("Error! Size mismatch between arrival and"
            " departure vec! Exiting...!");
    }

    typedef enum _eventT {
        ArrivalT,
        DepartureT
    } EventT;
    // Ordered/sorted table mapping arrival/departure times to the
    // respective event types
    multimap<int, EventT> timesToEventTbl;
    // Populate the table of times to events
    typedef vector<int>::size_type vecSzT;
    for (vecSzT i = 0; i != arrival.size(); ++i) {
        timesToEventTbl.insert(make_pair(arrival[i], ArrivalT));
        timesToEventTbl.insert(make_pair(departure[i], DepartureT));
    }

    // Examine the arrival and departure events in the order of increasing
    // time magnitudes together by iterating over the table
    // mapping event times to event type (table is automatically sorted)
    int minPlatforms = 0;
    int nPlatforms = 0;
    multimap<int, EventT>::iterator it = timesToEventTbl.begin();
    multimap<int, EventT>::iterator endIt = timesToEventTbl.end();
    for (; it != endIt; ++it) {
        if (it->second == ArrivalT) {
            // Arrival prior to a departure, requires one more platform
            ++nPlatforms;
            // Update minimum platforms required
            if (nPlatforms > minPlatforms) {
                minPlatforms = nPlatforms;
            }
        } else {
            // Departure prior to an arrival, requires one less platform
            --nPlatforms;
        }
    }

    return minPlatforms;
}
