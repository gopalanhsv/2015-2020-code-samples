#ifndef _ACTIVITY_SCHEDULING_H_
#define _ACTIVITY_SCHEDULING_H_

// System headers
#include <vector>

// Local includes

// Using declarations

// Statics, typedefs, globals
typedef struct _ActivityInfoT {
    int id;
    long start;
    long end;
} ActivityInfoT;

// Returns the set of ids of max number of activities which can
// be done by a single individual given a set of activity data
std::vector<int>
determineMaxActivitiesBruteForce(
    const std::vector<ActivityInfoT>& activityInfoV);

// Returns the set of ids of max number of activities which can
// be done by a single individual given a set of activity data
std::vector<int>
determineMaxActivitiesGreedy(std::vector<ActivityInfoT> activityInfoV);

#endif /* _ACTIVITY_SCHEDULING_H_ */
