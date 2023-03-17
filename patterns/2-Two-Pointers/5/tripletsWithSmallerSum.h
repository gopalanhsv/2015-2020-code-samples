#ifndef _TRIPLETS_WITH_SMALLER_SUM_H_
#define _TRIPLETS_WITH_SMALLER_SUM_H_

// System headers
#include <vector>

// Statics, globals, typedefs
typedef std::vector<int>::size_type vecSzT;

class TripletsWithLesserSum {
public:
    static std::vector<std::vector<int> >
        searchTriplets(std::vector<int> v, int tSum);
private:
    static void searchPairs(
        const std::vector<int>& v, int tSum, vecSzT firstElemIdx,
        std::vector<std::vector<int> >& tripletsV);
};

#endif /* _TRIPLETS_WITH_SMALLER_SUM_H_ */
