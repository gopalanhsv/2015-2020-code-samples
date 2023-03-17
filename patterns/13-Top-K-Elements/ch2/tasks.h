#ifndef _TASKS_H_
#define _TASKS_H_

// System headers
#include <vector>

// Local includes
// Using declarations
// Statics, typedefs, globals

class TaskScheduler {
public:
    static std::vector<char>
    schedule(std::vector<char>& tasksV, unsigned long minDist);
private:
};

#endif /* _TASKS_H_ */
