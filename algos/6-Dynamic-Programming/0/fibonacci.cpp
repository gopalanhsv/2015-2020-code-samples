// System headers
#include <stdexcept>
#include <vector>

// Local includes
#include "fibonacci.h"

// Using declarations
using std::vector;
using std::domain_error;

// Statics, typedefs, globals

long long
fibRecursive(long n) {
    if (n < 0) {
        throw domain_error("Error! Negative number input!");
    }

    // Fib(n) = n, for n < 2 & n >= 0
    if (n < 2) {
        return n;
    }

    return fibRecursive(n - 1) + fibRecursive(n - 2);
}

long long
fibRecursiveDPMemoization(long n, vector<long long>& fibLookupTbl) {
    // If look up in the fibonacci tbl fails, compute the entry recursively
    // and populate the table
    if (-1 == fibLookupTbl[n]) {
        fibLookupTbl[n] = fibRecursiveDPMemoization(n - 2, fibLookupTbl) + 
            fibRecursiveDPMemoization(n - 1, fibLookupTbl);
    }

    return fibLookupTbl[n];
}

long long
fibRecursiveDPMemoization(long n) {
    if (n < 0) {
        throw domain_error("Error! Negative number input!");
    }

    // Trivial case Fib(n) = n, for n < 2 & n >= 0
    if (n < 2) {
        return n;
    }

    // Initialize the fibonacci lookup table
    vector<long long> fibLookupTbl(n + 1, -1);
    fibLookupTbl[0] = 0;
    fibLookupTbl[1] = 1;
    fibLookupTbl[2] = 1;

    // Recursive call for computation and lookup
    return fibRecursiveDPMemoization(n, fibLookupTbl);
}

long long
fibDPTablulation(long n) {
    if (n < 0) {
        throw domain_error("Error! Negative number input!");
    }

    // Trivial case Fib(n) = n, for n < 2 & n >= 0
    if (n < 2) {
        return n;
    }

    // Initialize the fibonacci lookup table
    vector<long long> fibLookupTbl(n + 1);
    fibLookupTbl[0] = 0;
    fibLookupTbl[1] = 1;
    // Compute all the fibonacci lookup table entries iteratively
    for (long i = 2; i <= n; ++i) {
        fibLookupTbl[i] = fibLookupTbl[i - 1] + fibLookupTbl[i - 2];
    }

    return fibLookupTbl[n];
}

long long
fibDPOptimized(long n) {
    if (n < 0) {
        throw domain_error("Error! Negative number input!");
    }

    // Trivial case Fib(n) = n, for n < 2 & n >= 0
    if (n < 2) {
        return n;
    }

    // Initialize the last and second last fibonacci numbers
    long long fib_i_2 = 0; // Fib(i - 2)
    long long fib_i_1 = 1; // Fib(i - 1)
    long long fib_i; // Fib(i)

    // Compute fibonacci number iteratively
    for (long i = 2; i <= n; ++i) {
        fib_i = fib_i_1 + fib_i_2; // Fib(i) = Fib(i-1) + Fib(i-2)
        fib_i_2 = fib_i_1; // Fib(i-2) = Fib(i-1)
        fib_i_1 = fib_i; // Fib(i-1) = Fib(i)
    }

    return fib_i;
}
