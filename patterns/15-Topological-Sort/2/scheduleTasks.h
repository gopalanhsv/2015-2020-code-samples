#ifndef _SCHEDULE_TASKS_H_
#define _SCHEDULE_TASKS_H_

// System headers
#include <vector>
#include <utility>

// Local includes

// Using declarations
// Statics, typedefs, globals

class TaskScheduler {
public:
    static bool schedulingPossible(unsigned nTasks,
        const std::vector<std::pair<unsigned, unsigned> >& prerequisites);
private:
};

#endif /* _SCHEDULE_TASKS_H_ */
