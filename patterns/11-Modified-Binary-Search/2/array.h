#ifndef _ARRAY_H_
#define _ARRAY_H_

// System headers
#include <vector>

// Local includes
// Using declarations
// Statics, typedefs, globals

class Array {
public:
    static int
    ceiling(const std::vector<int>& v, int k);
    static int
    floor(const std::vector<int>& v, int k);
private:
};

#endif /* _ARRAY_H_ */
