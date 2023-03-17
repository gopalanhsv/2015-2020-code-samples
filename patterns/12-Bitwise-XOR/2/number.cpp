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
Number::findSingleUniqueNumber(const vector<unsigned int>& v) {
    if (v.empty()) {
        throw domain_error("Error! Empty input vector!");
    }

    // XOR all the elements in the vector. All duplicates elements
    // will cancel each other out during XOR. The final value of
    // XOR would be the XOR of non-duplicate/unqiue element(s)
    // Since there is a single unique element in the given vector,
    // final value would the unique element
    unsigned int allXor = 0;
    for (auto n : v) {
        allXor ^= n;
    }

    return allXor;
}
