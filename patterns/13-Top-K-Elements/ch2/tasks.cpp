// System headers
#include <vector>
#include <queue>
#include <unordered_map>
#include <utility>
#include <stdexcept>

// Local includes
#include "tasks.h"

// Using declarations
using std::vector;
using std::queue;
using std::priority_queue;
using std::unordered_map;
using std::pair;
using std::domain_error;

// Statics, typedefs, globals

vector<char>
TaskScheduler::schedule(vector<char>& tasksV, unsigned long minDist) {
    if (tasksV.empty()) {
        throw domain_error("Error! Empty task vector input!");
    }

    // Base case : min distance between same tasks 0, implies no
    // special scheduling process reqd
    if (0 == minDist) {
        return tasksV;
    }

    // Task frequency table mapping task id to its frequency/occurrence count
    unordered_map<char, unsigned long> taskFrequencyTbl;
    for (auto t : tasksV) {
        taskFrequencyTbl[t]++;
    }

    // Max heap of [task id, frequency] count tuples such that most frequent
    // tasks are at top of heat, and least frequent are at bottom of heap
    typedef pair<char, unsigned long> taskFreqCntPairT;
    struct taskFreqCntPairCmp {
        bool operator() (
            const taskFreqCntPairT& p1, const taskFreqCntPairT& p2) {
            return p1.second < p2.second;
        }
    };
    priority_queue<taskFreqCntPairT,
        vector<taskFreqCntPairT>, taskFreqCntPairCmp> maxHeap;
    // Insert all tasks/frequency count tuples from task frequency
    // table to max heap ordering tasks as per frequency
    for (auto tfe : taskFrequencyTbl) {
        maxHeap.push(tfe);
    }

    // Wait Q which holds task/frequency count tuples in the order of
    // execution; to ensure that tasks with same ids are executed after
    // a gap of 'k' intervals
    queue<taskFreqCntPairT> waitQ;
    vector<char> scheduledTasksV;
    while (!maxHeap.empty()) {
        // For each task, we need to execute for 1 + minDist intervals,
        // 1 for task at heap top, and remaining minDist task successively
        // from heap top followed by idle cycles/intervals
        for (unsigned long i = 0; i != 1 + minDist; ++i) {
            if (maxHeap.empty()) {
                // Idle cycle if wait Q has some tasks
                if (!waitQ.empty()) {
                    scheduledTasksV.push_back('!');
                }
            } else {
                // Pop off most frequent task from heap top
                auto tfe = maxHeap.top();
                maxHeap.pop();
                // Add task to scheduled tasks
                scheduledTasksV.push_back(tfe.first);
                // Adjust task frequency count and add it to wait Q if feasible
                if (tfe.second > 1) {
                    tfe.second--;
                    waitQ.push(tfe);
                }
            }
        }

        // Move tasks sitting in wait Q to heap for scheduling
        while (!waitQ.empty()) {
            auto tfe = waitQ.front();
            waitQ.pop();
            maxHeap.push(tfe);
        }
    }

    return scheduledTasksV;
}
