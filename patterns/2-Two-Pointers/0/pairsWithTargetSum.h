#ifndef _PAIRS_WITH_TARGET_SUM_H_
#define _PAIRS_WITH_TARGET_SUM_H_

// System headers
#include <vector>
#include <utility>

// Local includes

// Using declarations

// Statics, typedefs, globals

class PairsWithTargetSum {
public:
    static std::pair<int, int>
    findPairsTwoPtrs(std::vector<int> v, int tSum);
    static std::pair<int, int>
    findPairsHashing(const std::vector<int>& v, int tSum);
private:
};

#endif /* _PAIRS_WITH_TARGET_SUM_H_ */
