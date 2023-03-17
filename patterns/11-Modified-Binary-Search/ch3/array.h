#ifndef _ARRAY_H_
#define _ARRAY_H_

// System headers
#include <vector>

// Local includes
// Using declarations

// Statics, typedefs, globals
typedef std::vector<int>::size_type vecSzT;

class RotatedArray {
public:
    static vecSzT numRotations(const std::vector<int>& v);
    static vecSzT numRotationsWithArrDuplicates(const std::vector<int>& v);
private:
};

#endif /* _ARRAY_H_ */
