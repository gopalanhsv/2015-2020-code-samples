#ifndef _CPU_LOAD_H_
#define _CPU_LOAD_H_

// System headers
#include <vector>

// Statics, globals, typedefs

class Job {
public:
    // Constructor
    Job(int s, int e, int l) : _start(s), _end(e), _load(l) {}

    // Accessors
    inline int start() const { return _start; }
    inline int end() const { return _end; }
    inline int load() const { return _load; }

private:
    Job();

    int _start;
    int _end;
    int _load;
};

class Cpu {
public:
    static int
    computeMaxLoadForJobs(std::vector<Job> jobs);
};

#endif /* _CPU_LOAD_H_ */
