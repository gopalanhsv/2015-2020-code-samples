// System headers
#include <vector>
#include <stdexcept>

// Local includes
#include "number.h"

// Using declarations
using std::vector;
using std::domain_error;

// Statics, typedefs, globals

unsigned int
Number::findMissingNumber(const vector<unsigned int>& v) {
    if (v.empty()) {
        throw domain_error("Error! Empty input vector!");
    }

    typedef vector<unsigned int>::size_type vecSzT;
    vecSzT n = v.size();

    // Ideally the vector should contain 'n + 1' elements from
    // 1 to n + 1. Instead it has only 'n' elements

    // XOR all the elements in range [1, n]
    unsigned int allXor = 0;
    for (vecSzT i = 1; i <= n + 1; ++i) {
        allXor ^= i;
    }

    // XOR all the elements of the vector
    unsigned int vecElemXor = 0;
    for (vecSzT i = 0; i != v.size(); ++i) {
        vecElemXor ^= v[i];
    }

    // XOR of allXor and vecElemXor will give the XOR of the elements
    // belonging to the set difference between them, in this case this
    // would be the missing element in vector
    return allXor ^ vecElemXor;
}
