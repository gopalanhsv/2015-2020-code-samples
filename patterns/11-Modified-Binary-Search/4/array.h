#ifndef _ARRAY_H_
#define _ARRAY_H_

// System headers
#include <vector>
#include <utility>

// Local includes
// Using declarations
// Statics, typedefs, globals

class Array {
public:
    static std::pair<long, long>
    keyRange(const std::vector<int>& v, int key);
private:
};

#endif /* _ARRAY_H_ */
