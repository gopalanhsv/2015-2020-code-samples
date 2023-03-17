// System headers
#include <stdexcept>
#include <vector>

// Local includes
#include "stairCase.h"

// Using declarations
using std::vector;
using std::domain_error;

// Statics, typedefs, globals

long long
waysToClimbRecursive(long n) {
    if (n < 0) {
        throw domain_error("Error! Negative number input!");
    }

    // Base case of 1 or 0 steps; only 1 way to climb
    if (0 == n || 1 == n) {
        return 1;
    }
    // Base case of 2 steps; only 2 ways to climb (1 + 1 step or 2 steps)
    if (2 == n) {
        return 2;
    }

    // If 1 step taken while climbing, n - 1 steps remain
    // If 2 steps taken while climbing, n - 2 steps remain
    // If 3 steps taken while climbing, n - 3 steps remain
    return waysToClimbRecursive(n - 1) + 
        waysToClimbRecursive(n - 2) + waysToClimbRecursive(n - 3);
}

long long
waysToClimbDPMemoization(long n, vector<long long>& waysToClimbTbl) {
    // If look up in the table fails, compute the entry recursively
    // and populate the table
    if (-1 == waysToClimbTbl[n]) {
        // If 1 step taken while climbing, n - 1 steps remain
        // If 2 steps taken while climbing, n - 2 steps remain
        // If 3 steps taken while climbing, n - 3 steps remain
        waysToClimbTbl[n] = waysToClimbDPMemoization(n - 3, waysToClimbTbl) + 
            waysToClimbDPMemoization(n - 2, waysToClimbTbl) +
            waysToClimbDPMemoization(n - 1, waysToClimbTbl);
    }

    return waysToClimbTbl[n];
}

long long
waysToClimbRecursiveDPMemoization(long n) {
    if (n < 0) {
        throw domain_error("Error! Negative number input!");
    }
    // Base case of 1 or 0 steps; only 1 way to climb
    if (0 == n || 1 == n) {
        return 1;
    }
    // Base case of 2 steps; only 2 ways to climb (1 + 1 step or 2 steps)
    if (2 == n) {
        return 2;
    }

    // Initialize the ways to climb lookup table
    vector<long long> waysToClimbTbl(n + 1, -1);
    // Base case of 1 or 0 steps; only 1 way to climb
    // Base case of 2 steps; only 2 ways to climb (1 + 1 step or 2 steps)
    waysToClimbTbl[0] = 1;
    waysToClimbTbl[1] = 1;
    waysToClimbTbl[2] = 2;

    // Recursive call for computation and lookup
    return waysToClimbDPMemoization(n, waysToClimbTbl);
}

long long
waysToClimbDPTablulation(long n) {
    if (n < 0) {
        throw domain_error("Error! Negative number input!");
    }
    // Base case of 1 or 0 steps; only 1 way to climb
    if (0 == n || 1 == n) {
        return 1;
    }
    // Base case of 2 steps; only 2 ways to climb (1 + 1 step or 2 steps)
    if (2 == n) {
        return 2;
    }

    // Initialize the ways to climb lookup table
    // Base case of 1 or 0 steps; only 1 way to climb
    // Base case of 2 steps; only 2 ways to climb (1 + 1 step or 2 steps)
    vector<long long> waysToClimbTbl(n + 1, -1);
    waysToClimbTbl[0] = 1;
    waysToClimbTbl[1] = 1;
    waysToClimbTbl[2] = 2;

    // Compute all the fibonacci lookup table entries iteratively
    for (long i = 3; i <= n; ++i) {
        // If 1 step taken while climbing, n - 1 steps remain
        // If 2 steps taken while climbing, n - 2 steps remain
        // If 3 steps taken while climbing, n - 3 steps remain
        waysToClimbTbl[i] = waysToClimbTbl[i - 1] + 
            waysToClimbTbl[i - 2] + waysToClimbTbl[i - 3];
    }

    return waysToClimbTbl[n];
}

long long
waysToClimbDPOptimized(long n) {
    if (n < 0) {
        throw domain_error("Error! Negative number input!");
    }
    // Base case of 1 or 0 steps; only 1 way to climb
    if (0 == n || 1 == n) {
        return 1;
    }
    // Base case of 2 steps; only 2 ways to climb (1 + 1 step or 2 steps)
    if (2 == n) {
        return 2;
    }

    // Initialize the last, second last & third last ways to climb
    // Base case of 1 or 0 steps; only 1 way to climb
    // Base case of 2 steps; only 2 ways to climb (1 + 1 step or 2 steps)
    long long waysToClimb_i_3 = 1; // W(0)
    long long waysToClimb_i_2 = 1; // W(1)
    long long waysToClimb_i_1 = 2; // W(2)
    long long waysToClimb_i; // W(i)

    // Compute ways to climb iteratively
    for (long i = 3; i <= n; ++i) {
        waysToClimb_i = waysToClimb_i_1 +
            waysToClimb_i_2 + waysToClimb_i_3;// W(i) = W(i-1) + W(i-2) + W(i-3)
        waysToClimb_i_3 = waysToClimb_i_2;// W(i-3) = W(i-2)
        waysToClimb_i_2 = waysToClimb_i_1;// W(i-2) = W(i-1)
        waysToClimb_i_1 = waysToClimb_i;// W(i-1) = W(i)
    }

    return waysToClimb_i;
}
