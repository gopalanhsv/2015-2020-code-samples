// System headers
#include <vector>
#include <stdexcept>
#include <algorithm>

// Local includes
#include "activityScheduling.h"

// Using declarations
using std::vector;
using std::domain_error;
using std::sort;
using std::next_permutation;

// Statics, typedefs, globals

// Returns the set of ids of max number of activities which can
// be done by a single individual given a set of activity data
vector<int>
determineMaxActivitiesBruteForce(
    const vector<ActivityInfoT>& activityInfoV) {

    if (activityInfoV.empty()) {
        throw domain_error("Error! Empty input vector!");
    }

    // Base case of single activity
    if (1 == activityInfoV.size()) {
        vector<int> maxActVec;
        maxActVec.push_back(activityInfoV[0].id);
        return maxActVec;
    }

    // Create a vector of activity info indexes, which will be used to
    // generate all combination or activity info orderings
    typedef vector<ActivityInfoT>::size_type vecActInfoSzT;
    vector<vecActInfoSzT> activityCombinations;
    for (vecActInfoSzT i = 0; i != activityInfoV.size(); ++i) {
        activityCombinations.push_back(i);
    }

    vector<int> maxActVec;
    // Generate and iterate over all possible combinations of activity info.
    // Skip the combinations which are not feasible and for those which
    // are feasible, keep track of the combination of activity info which had
    // the max possible number of activities
    do {
        vecActInfoSzT prevIdx = activityCombinations[0];

        // Commence from the first activity in the combination
        vector<int> currActCombinationVec;
        currActCombinationVec.push_back(activityInfoV[prevIdx].id);

        // Iterate over the current combination of activities to determine
        // to determine which actities to drop and which to retain
        // (Retain activities which commence after previous ends)
        for (vector<vecActInfoSzT>::size_type i = 1;
            i != activityCombinations.size(); ++i) {
            vecActInfoSzT currIdx = activityCombinations[i];
            if (activityInfoV[currIdx].start >= activityInfoV[prevIdx].end) {
                // In current combination, current activity commences post
                // previous activity end, which is feasible
                // So store current activity id
                currActCombinationVec.push_back(activityInfoV[currIdx].id);
                prevIdx = currIdx;
            }
        }

        // If current activity combination has max activities, then update
        // max activities
        if (currActCombinationVec.size() > maxActVec.size()) {
            maxActVec = currActCombinationVec;
        }

    } while (next_permutation(
        activityCombinations.begin(), activityCombinations.end()));

    return maxActVec;
}

bool
compareActivities(const ActivityInfoT& ai1, const ActivityInfoT& ai2) {
    return ai1.end < ai2.end;
}

// Returns the set of ids of max number of activities which can
// be done by a single individual given a set of activity data
vector<int>
determineMaxActivitiesGreedy(vector<ActivityInfoT> activityInfoV) {
    if (activityInfoV.empty()) {
        throw domain_error("Error! Empty input vector!");
    }

    // Base case of single activity
    if (1 == activityInfoV.size()) {
        vector<int> maxActVec;
        maxActVec.push_back(activityInfoV[0].id);
        return maxActVec;
    }

    // Sort the activities in the ascending order of end/finish times
    sort(activityInfoV.begin(), activityInfoV.end(), compareActivities);

    // Add the activity which finished earliest to list of activities
    // which stores the max number of activities which can be executed
    // in sequence
    typedef vector<ActivityInfoT>::size_type vecActInfoSzT;
    vector<int> maxActVec;
    maxActVec.push_back(activityInfoV[0].id);
    vecActInfoSzT prevIdx = 0;

    // Iterate through the remaining activities in the increase order
    // of finish/end times. Adopt greedy approach of selecting an
    // activitiy which commences post the ending/finish of activity
    // select earlier and stored. The activities selected in this manner
    // will form the set of maximum number of activities which can 
    // be executed by a single user
    for (vector<ActivityInfoT>::size_type i = 1;
        i != activityInfoV.size(); ++i) {

        const ActivityInfoT& currActivity = activityInfoV[i];
        const ActivityInfoT& prevActivity = activityInfoV[prevIdx];
        // Current activity commences post previously selected activity
        if (currActivity.start >= prevActivity.end) {
            maxActVec.push_back(currActivity.id);
            prevIdx = i;
        }
    }

    return maxActVec;
}
