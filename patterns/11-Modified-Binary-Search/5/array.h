#ifndef _ARRAY_H_
#define _ARRAY_H_

// System headers
#include <vector>
#include <limits>
#include <cstdlib>

// Local includes
// Using declarations
// Statics, typedefs, globals

class BigArrayReader {
public:
    // Constructor
    BigArrayReader(const std::vector<int>& v) : _v(v) {}
    // Accessors
    inline int get(size_t idx) const {
        if (idx >= _v.size()) {
            return std::numeric_limits<int>::max();
        }
        return _v[idx];
    }
private:
    BigArrayReader();

    // Data members
    std::vector<int> _v;
};

class InfiniteArray {
public:
    static long search(BigArrayReader *arrRdr, int key);
private:
};

#endif /* _ARRAY_H_ */
