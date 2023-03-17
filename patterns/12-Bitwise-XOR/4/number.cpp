// System headers
#include <vector>
#include <cmath>

// Local includes
#include "number.h"

// Using declarations
using std::vector;
using std::pow;

// Statics, typedefs, globals

unsigned int
Number::computeBitwiseComplement(unsigned int n) {
    // Compute min number of bits required to represent the number
    unsigned int nBits = 0;
    unsigned int num = n;
    while (num) {
        num = num >> 1;
        ++nBits;
    }

    // Compute the number which has all bits set for the min 
    // number of bits which can represent the number
    unsigned int allBitsSet = pow(2, nBits) - 1;


    // Given number is 'n'
    // n XORed with its complement 'nc' would be allBitsSet
    // n XOR nc = allBitsSet
    // => n XOR ( n XOR nc ) = n XOR allBitsSet
    // => (n XOR n) XOR nc = n XOR allBitsSet
    // => (0) XOR nc = n XOR allBitsSet
    // => nc = n XOR allBitsSet = complement of n

    return n ^ allBitsSet;
}
