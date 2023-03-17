#ifndef _TRIPLETS_SUM_TO_ZERO_H_
#define _TRIPLETS_SUM_TO_ZERO_H_

// System headers
#include <vector>

// Statics, globals, typedefs
typedef std::vector<int>::size_type vecSzT;

class TripletsSumToZero {
public:
    static std::vector<std::vector<int> >
        searchTriplets(std::vector<int>& v);
private:
    static void searchPairWithTargetSum(
        const std::vector<int>& v, int tSum, vecSzT startIdx,
        std::vector<std::vector<int> >& tripletsV);
};

#endif /* _TRIPLETS_SUM_TO_ZERO_H_ */
