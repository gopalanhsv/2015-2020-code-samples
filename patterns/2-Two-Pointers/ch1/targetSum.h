#ifndef _TARGET_SUM_H_
#define _TARGET_SUM_H_

// System headers
#include <vector>

// Typedefs, statics, globals
typedef std::vector<int>::size_type vecSzT;

class QuadrapletsAddingUptoTarget {
public:
    static std::vector<std::vector<int> > find(std::vector<int> v, int target);
private:
    static void searchPairs(const std::vector<int>& v, int target,
        vecSzT firstIdx, vecSzT secondIdx,
        std::vector<std::vector<int> >& quadV);
};

#endif /* _TARGET_SUM_H_ */
