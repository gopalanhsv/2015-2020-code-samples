#ifndef _RECONSTRUCT_SEQUENCE_H_
#define _RECONSTRUCT_SEQUENCE_H_

// System headers
#include <vector>

// Local includes
// Using declarations
// Statics, typedefs, locals

class Sequence {
public:
    static bool isSoleSequenceOfSubsequences(
        const std::vector<int>& sequence,
        const std::vector<std::vector<int> >& subsequenceV);
private:
};

#endif /* _RECONSTRUCT_SEQUENCE_H_ */
