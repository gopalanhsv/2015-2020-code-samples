// System headers
#include <iostream>
#include <stdexcept>

// Local includes
#include "fibonacci.h"

// Using declarations
using std::cin;
using std::cout;
using std::endl;
using std::domain_error;

// Statics, typedefs, globals

void
testFn() {
    int x;
    cout << "Enter number : ";
    while (cin >> x) {
#if 0
        try {
            long long fib = fibRecursive(x);
            cout << endl;
            cout << "Fib(" << x << ") recursive = " << fib;
        } catch (domain_error& e) {
            throw e;
        }
#endif

        try {
            long long fib = fibRecursiveDPMemoization(x);
            cout << endl;
            cout << "Fib(" << x << ") recursive (dp memoization) = " << fib;
        } catch (domain_error& e) {
            throw e;
        }

        try {
            long long fib = fibDPTablulation(x);
            cout << endl;
            cout << "Fib(" << x << ") recursive (dp tabulation) = " << fib;
        } catch (domain_error& e) {
            throw e;
        }

        try {
            long long fib = fibDPOptimized(x);
            cout << endl;
            cout << "Fib(" << x << ") recursive (dp space optimized) = " << fib;
        } catch (domain_error& e) {
            throw e;
        }

        cout << endl << "Enter number : ";
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
