// System headers
#include <vector>
#include <queue>
#include <stdexcept>
#include <algorithm>

// Local includes
#include "cpuLoad.h"

// Using declarations
using std::vector;
using std::priority_queue;
using std::domain_error;
using std::sort;
using std::max;

// Statics, globals, typedefs

bool
cmpJobsStart(const Job& x, const Job& y) {
    return x.start() < y.start();
}

struct CmpJobEnd {
    bool operator() (const Job& x, const Job& y) {
        return x.end() > y.end();
    }
};

int
Cpu::computeMaxLoadForJobs(vector<Job> jobs) {
    if (jobs.empty()) {
        throw domain_error("Error! Empty input vector!");
    }

    // Sort the jobs in ascending order of start times
    sort(jobs.begin(), jobs.end(), cmpJobsStart);

    int maxCpuLoad = 0, currCpuLoad = 0;
    // All the currently active jobs are maintained in a priority
    // queue ordered by ascending job end times; such that the Q top
    // always has the job which ends earlier amongst all Q elements
    priority_queue<Job, vector<Job>, CmpJobEnd> activeJobsQ;

    // Add jobs to pQ sequentially in ascending order of start times
    for (auto currJob : jobs) {
        // Prior to inserting the new job to PQ of active jobs, remove
        // all the jobs which end prior to commencement of new job
        // Adjust CPU load accordingly
        while (!activeJobsQ.empty() &&
            (activeJobsQ.top().end() <= currJob.start())) {
            const Job& j = activeJobsQ.top();
            currCpuLoad -= j.load();
            activeJobsQ.pop();
        }

        // Add the new job to PQ
        activeJobsQ.push(currJob);
        currCpuLoad += currJob.load();

        // Update max cpu load
        maxCpuLoad = max(maxCpuLoad, currCpuLoad);
    }

    return maxCpuLoad;
}
