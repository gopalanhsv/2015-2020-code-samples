// System headers
#include <algorithm>
#include <stdexcept>

// Local includes
#include "gcd.h"

// Using declarations
using std::domain_error;

// Statics, typedefs, globals

long
gcdRecursive(long a, long b) {
    if (0 == a && 0 == b) {
        throw domain_error("Error! Both nos are 0!");
    }
    // Base case, remainder has become 0, other number would be the gcd
    if (0 == a) {
        return b;
    }

    // Ensure that a is always greater than b
    if (a < b) {
        std::swap(a, b);
    }

    // Divide larger number by smaller and invoke the
    // function recursively with the remainder and quotient 
    return gcdRecursive(a % b, b);
}

long
gcdIterative(long a, long b) {
    if (0 == a && 0 == b) {
        throw domain_error("Error! Both nos are 0!");
    }

    while (a) {
        if (a < b) {
            // Ensure that a is always greater than b
            std::swap(a, b);
            a = a % b;
        }
        // Divide larger number by smaller till remainder is
        // 0. The other number would be gcd.
        a = a % b;
    }

    return b;
}
