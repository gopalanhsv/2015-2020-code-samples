#ifndef _SCHEDULE_ALL_TASKS_H_
#define _SCHEDULE_ALL_TASKS_H_

// System includes
#include <vector>
#include <utility>

// Local includes
// Using declarations
// Statics, typedefs, globals

class TaskScheduler {
public:
    static std::vector<std::vector<unsigned> > scheduleAllTasks(
        unsigned nTasks,
        const std::vector<std::pair<unsigned, unsigned> >& prerequisitesV);
private:
};

#endif /* _SCHEDULE_ALL_TASKS_H_ */
