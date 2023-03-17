// System headers
#include <vector>
#include <stdexcept>

// Local includes
#include "squareSortedVec.h"

// Statics, typedefs, globals

// Using declarations
using std::vector;
using std::domain_error;

vector<int>
SquareSortedVec::squareVec(const vector<int>& v) {
    if (v.empty()) {
        throw domain_error("Error! Empty input vector!");
    }

    vector<int> sqrsV(v.size(), 0);;
    typedef vector<int>::size_type vecSzT;

    // Since the vector is sorted, start with two ptrs indexing elements at
    // ends of vector. Find the squares of the elements indicated by the two
    // indices and have greater of the squares written prior to the last
    // written element in the squares vector. Advance the index of the element
    // whose square was greater to left/right by one position as that element
    // is processed
    vecSzT lPtr = 0, rPtr = v.size() - 1, writePtr = sqrsV.size() - 1;
    // Till all elements are processed
    while (lPtr < rPtr) {
        int sqrsLeft = v[lPtr] * v[lPtr];
        int sqrsRight = v[rPtr] * v[rPtr];
        if (sqrsLeft > sqrsRight) {
            sqrsV[writePtr--] = sqrsLeft;
            ++lPtr;
        } else {
            sqrsV[writePtr--] = sqrsRight;
            --rPtr;
        }
    }

    return sqrsV;
}
