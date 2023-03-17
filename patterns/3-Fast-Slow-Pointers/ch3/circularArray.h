#ifndef _CIRCULAR_ARRAY_H_
#define _CIRCULAR_ARRAY_H_

// System headers
#include <vector>

// Static, typedefs, globals
typedef std::vector<int>::size_type vecSzT;

class CircularArray {
public:
    static bool hasCycle(const std::vector<int>& v);
private:
    static int
    findNextHopIdx(const std::vector<int>& v, vecSzT currElemIdx,
        bool forwardDir, bool& dirChangeOrHalt);
};

#endif /* _CIRCULAR_ARRAY_H_ */
