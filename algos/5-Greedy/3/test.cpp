// System headers
#include <iostream>
#include <stdexcept>

// Local includes
#include "computeEgyptianFraction.h"

// Using declarations
using std::cin;
using std::cout;
using std::endl;
using std::domain_error;

// Statics, typedefs, globals

void
testFn() {
    int n, d;
    cout << "Enter numerator : ";
    cin >> n;
    cout << "Enter denominator : ";
    cin >> d;
    try {
        computeEgyptianFraction(n, d);
    } catch (domain_error& e) {
        throw e;
    }
}

int
main() {
    while (1) {
        try {
            testFn();
        } catch (domain_error& e) {
            cout << e.what() << endl;
            return 1;
        }
        if (!cin) {
            break;
        }
    }
    return 0;
}
