#ifndef _ARRAYS_H_
#define _ARRAYS_H_

// System headers
#include <vector>
#include <utility>

// Local includes
// Using namespaces
// Statics, typedefs, globals

class Arrays {
public:
    static std::vector<std::pair<int, int> >
    findPairsWithLargestSum(const std::vector<int>& v1,
        const std::vector<int>& v2, unsigned int nPairs);
private:
};

#endif /* _ARRAYS_H_ */
