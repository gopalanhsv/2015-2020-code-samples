#ifndef _ARRAYS_H_
#define _ARRAYS_H_

// System headers
#include <utility>
#include <vector>

// Local includes
// Using declarations
// Statics, typedefs, globals

class Array {
public:
    // Return 2 numbers forming smallest range encompassing
    // at least one element from each array
    static std::pair<int, int>
        smallestRange(const std::vector<std::vector<int> >& arrayV);
};

#endif /* _ARRAYS_H_ */
