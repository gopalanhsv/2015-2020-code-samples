#ifndef _ARRAY_H_
#define _ARRAY_H_

// System headers
#include <vector>

// Local includes
// Using declarations
// Statics, typedefs, globals
typedef std::vector<int>::size_type vecSzT;

class BitonicArray {
public:
    static long search(const std::vector<int>& v, int k);

private:
    static vecSzT maximumLocation(const std::vector<int>& v);

    static long
    orderAgnosticBinSearch(const std::vector<int>& v, int key,
        vecSzT startIdx, vecSzT endIdx);
};

#endif /* _ARRAY_H_ */
