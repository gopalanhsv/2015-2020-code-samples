#ifndef _PERMUTATIONS_H_
#define _PERMUTATIONS_H_

// System headers
#include <vector>

// Local includes
// Using declarations
// Statics, typedefs, globals

class Numbers {
public:
    static std::vector<std::vector<int> >
        generateAllPermutations(const std::vector<int>& v);

    static std::vector<std::vector<int> >
        generateAllPermutationsRecursive(const std::vector<int>& v);

private:
    static void
    generateAllPermutationsRecursive(const std::vector<int>& v,
        std::vector<int>::size_type inputNumVecIdx,
        std::vector<int>& prevPermutation,
        std::vector<std::vector<int> >& finalPermutationsV);
};

#endif /* _PERMUTATIONS_H_ */
