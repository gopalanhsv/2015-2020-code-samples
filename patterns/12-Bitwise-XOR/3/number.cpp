// System headers
#include <vector>
#include <stdexcept>

// Local includes
#include "number.h"

// Using declarations
using std::vector;
using std::domain_error;
using std::pair;
using std::make_pair;

// Statics, typedefs, globals

pair<unsigned int, unsigned int>
Number::findTwoUniqueNumbers(const vector<unsigned int>& v) {
    if (v.empty()) {
        throw domain_error("Error! Empty input vector!");
    }

    // XOR all the elements in the vector. All duplicates elements
    // will cancel each other out during XOR. The final value of
    // XOR would be the XOR of non-duplicate/unique element(s)
    unsigned int allXor = 0;
    typedef vector<unsigned int>::size_type vecSzT;
    for (auto n : v) {
        allXor ^= n;
    }

    // Rightmost set bit in 'allXor' would be the rightmost bit in
    // which two unique numbers differ (all bits where the two unique
    // numbers dont differ would be set to 0)
    unsigned int rightMostSetBit = 1;
    while (!(allXor & rightMostSetBit)) {
        rightMostSetBit = (rightMostSetBit << 1);
    }

    // Partition all vector elements into two sets. Those
    // 1. with 'rightMostSetBit' set 
    // 2. with 'rightMostSetBit' cleared
    // Each of two unique numbers will get partitioned into different sets
    // XOR all numbers in the two partitioned sets independently
    // Since all other elements are duplicated, this would yield the
    // two unique numbers
    int missing1 = 0, missing2 = 0;
    for (auto n : v) {
        if (rightMostSetBit & n) {
            missing1 = missing1 ^ n;
        } else {
            missing2 = missing2 ^ n;
        }
    } 

    return make_pair(missing1, missing2);
}
