// System headers
#include <vector>
#include <queue>
#include <algorithm>
#include <stdexcept>

// Local includes
#include "meetingRoom.h"

// Using declarations
using std::vector;
using std::priority_queue;
using std::domain_error;
using std::sort;
using std::max;

// Statics, typedefs, globals

inline bool
meetingStartCmp(const Meeting& x, const Meeting& y) {
    return x.start() < y.start();
}

struct meetingEndCmp {
    bool
    operator() (const Meeting& x, const Meeting& y) {
        return x.end() > y.end();
    }
};

int
MeetingRooms::findMinimumRequired(vector<Meeting>& meetings) {
    if (meetings.empty()) {
        throw domain_error("Error! Empty input vector!");
    }

    if (1 == meetings.size()) {
        return 1;
    }

    // Sort the meetings in the ascending order of start times
    sort(meetings.begin(), meetings.end(), meetingStartCmp);

    // Use a priority queue to store all currently active meetings
    // ordered in the ascending order of meeting end times; i.e 
    // min heap of meetings ordered on end times
    priority_queue<Meeting, vector<Meeting>, meetingEndCmp> activeMeetings;
    typedef priority_queue<Meeting, vector<Meeting>, meetingEndCmp>::size_type
        qSzT;
    qSzT maxActiveMeetings = 0;

    // Iterate over all meetings and add them to the min heap of
    // active meetings
    for (auto currMeeting : meetings) {

        // Remove all meetings which end prior to commencement of 
        // current meeting from the min heap of active meetings
        while (!activeMeetings.empty() &&
            activeMeetings.top().end() <= currMeeting.start()) {
            activeMeetings.pop();
        }

        // Add current meeting to min heap of active meetings
        activeMeetings.push(currMeeting);

        // Update the max number of currently active meetings
        maxActiveMeetings = max(activeMeetings.size(), maxActiveMeetings);
    }

    return maxActiveMeetings;
}
