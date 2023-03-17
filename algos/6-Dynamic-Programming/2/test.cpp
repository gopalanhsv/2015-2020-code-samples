// System headers
#include <iostream>
#include <stdexcept>

// Local includes
#include "stairCase.h"

// Using declarations
using std::cin;
using std::cout;
using std::endl;
using std::domain_error;

// Statics, typedefs, globals

void
testFn() {
    int x;
    cout << "Enter num steps : ";
    while (cin >> x) {
#if 1
        try {
            long long wtc = waysToClimbRecursive(x);
            cout << endl;
            cout << "WaysToClimb(" << x << ") recursive = " << wtc;
        } catch (domain_error& e) {
            throw e;
        }
#endif

        try {
            long long wtc = waysToClimbRecursiveDPMemoization(x);
            cout << endl;
            cout << "WaysToClimb(" << x << ") recursive (dp memoization) = " << wtc;
        } catch (domain_error& e) {
            throw e;
        }

        try {
            long long wtc = waysToClimbDPTablulation(x);
            cout << endl;
            cout << "WaysToClimb(" << x << ") (dp tabulation) = " << wtc;
        } catch (domain_error& e) {
            throw e;
        }

        try {
            long long wtc = waysToClimbDPOptimized(x);
            cout << endl;
            cout << "WaysToClimb(" << x << ") (dp space optimized) = " << wtc;
        } catch (domain_error& e) {
            throw e;
        }

        cout << endl << "Enter num steps : ";
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
