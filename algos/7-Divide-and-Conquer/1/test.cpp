// System headers
#include <iostream>
#include <stdexcept>

// Local includes
#include "gcd.h"

// Using declarations
using std::cin;
using std::cout;
using std::endl;
using std::domain_error;

// Statics, typedefs, globals

void
testFn() {
    while (true) {
        long x, y;
        cout << "Enter A : ";
        while (!(cin >> x));
        cout << endl << "Enter B : ";
        while (!(cin >> y));
        try {
            long g = gcdRecursive(x, y);
            cout << endl << "GCD(" << x << ", " << y
                << ") = " << g;
        } catch (domain_error& e) {
            throw e;
        }

        try {
            long g = gcdIterative(x, y);
            cout << endl << "GCD(" << x << ", " << y
                << ") = " << g;
        } catch (domain_error& e) {
            throw e;
        }
    }
}

int
main() {
    try {
        testFn();
    } catch (domain_error& e) {
        cout << e.what() << endl;
        return 1;
    }
    return 0;
}
