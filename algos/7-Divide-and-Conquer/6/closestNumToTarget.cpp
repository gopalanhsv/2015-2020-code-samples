// System headers
#include <vector>
#include <stdexcept>

// Local includes
#include "closestNumToTarget.h"

// Using declarations
using std::vector;
using std::domain_error;

// Statics, globals, typedefs

// Returns closest element of (a, b) to 't' where a < b
// and a < t < b
int
closestToTarget(int a, int b, int t) {
    if (t - a > b - t) {
        return b;
    }
    return a;
}

int
closestNumberToTarget(const vector<int>& v, int tgt) {
    if (v.empty()) {
        throw domain_error("Error! Empty input vec!");
    }

    // Single element array
    if (1 == v.size()) {
        return v[0];
    }

    // Corner cases : Target lesser than 1st element
    // or greater that last element
    if (tgt <= v[0]) {
        return v[0];
    }
    if (tgt >= v[v.size() - 1]) {
        return v[v.size() - 1];
    }

    typedef vector<int>::size_type vecSzT;

    // Modified binary search to find num in the array
    vecSzT l = 0;
    vecSzT r = v.size() - 1;
    vecSzT m;
    while (l <= r) {
        // Find the midpoint index
        vecSzT m = l + (r - l) / 2;

        // Midpoint has target element, will be closest number -> exit
        if (v[m] == tgt) {
            return tgt;
        }

        if (v[m] > tgt) {
            // Midpoint element is greater than target
            if (0 != m) {
                // Target element lies between mid point and preceeding element
                if (v[m] > tgt && v[m - 1] <= tgt) {
                    // Return closest element of mid point &
                    // preceding element to target
                    return closestToTarget(v[m - 1], v[m], tgt);
                } else {
                    // Closest element would be to the left of midpoint
                    r = m - 1;
                }
            } else {
                // m = 0, end of range reached
                break;
            }
        } else {
            // Midpoint element is lesser than target
            if (r != m) {
                // Target element lies between mid point and succeeding element
                if (v[m] < tgt && v[m + 1] >= tgt) {
                    // Return closest element of mid point &
                    // succeeding element to target
                    return closestToTarget(v[m], v[m + 1], tgt);
                } else {
                    // Closest element would be to the right of midpoint
                    l = m + 1;
                }
            } else {
                // m = r, end of range reached
                break;
            }
        }
    }

    return v[m];
}
