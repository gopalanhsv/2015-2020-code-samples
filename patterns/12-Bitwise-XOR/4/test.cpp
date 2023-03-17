// System headers
#include <iostream>
#include <vector>

// Local includes
#include "number.h"

// Using declarations
using std::vector;
using std::cin;
using std::cout;
using std::endl;

// Statics, typedefs, globals

void
testFn() {
    cout << "Enter number : ";
    unsigned int n;
    while (!(cin >> n));
    unsigned int bc = Number::computeBitwiseComplement(n);
    cout << "Bitwise complement of " << n << " is " << bc << endl;
}

int
main() {
    testFn();
    return 0;
}
