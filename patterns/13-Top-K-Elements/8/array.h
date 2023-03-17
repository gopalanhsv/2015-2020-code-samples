#ifndef _ARRAY_H_
#define _ARRAY_H_

// System headers
#include <vector>

// Local includes
// Using declarations
// Statics, typedefs, globals

class Array {
public:
    static std::vector<int>
    nClosestNumbersToKey(const std::vector<int>& v, int key, unsigned int n);

    static std::vector<int>
    nClosestNumbersToKeyTwoPointerMethod(
        const std::vector<int>& v, int key, unsigned int n);

private:
    static std::vector<int>::size_type
    findClosestNumToKey(const std::vector<int>& v, int key);
};

#endif /* _ARRAY_H_ */
