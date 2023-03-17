// System headers
#include <vector>
#include <algorithm>
#include <stdexcept>

// Local includes

// Using declarations
using std::vector;
using std::domain_error;
using std::swap;

// Statics, typedefs, globals
typedef vector<int>::size_type vecSzT;

vecSzT
findMinIdx(const vector<int>& v, vecSzT lo, vecSzT hi) {
    vecSzT minIdx = lo;
    for (vecSzT i = lo + 1; i != hi + 1; ++i) {
        if (v[i] < v[minIdx]) {
            minIdx = i;
        }
    }
    return minIdx;
}

void
selectionSort(vector<int>& v) {
    if (v.empty()) {
        throw domain_error("Error! Empty input vector!");
    }

    // Iterate over the entire vector to be sorted
    for (vecSzT i = 0; i != v.size(); ++i) {
        // Serach for the minimum element in the range [i, v.size())
        // Bring min element to beginning of search range so
        // that the vector gets sorted in [0, i] range
        // at each iteration
        vecSzT minIdx = findMinIdx(v, i, v.size() - 1);
        swap(v[minIdx], v[i]);
    }
}

void
bubbleSort(vector<int>& v) {
    if (v.empty()) {
        throw domain_error("Error! Empty input vector!");
    }

    // Iterate over the entire vector to be sorted
    for (vecSzT i = 0; i != v.size(); ++i) {
        // Bubble up the the max element in range [0, v.size() - i)
        // to the end of range by swapping adjacent elements
        // This will ensure that elements in [v.size - i, v.size())
        // will be the ones in sorted order. (i.e move the
        // max element in unsorted range to end, reduce the
        // unsorted range by 1 element. repeat)
        for (vecSzT j = 0; j != v.size() - i - 1; ++j) {
            if (v[j] > v[j + 1]) {
                swap(v[j], v[j + 1]);
            }    
        }
    }
}

void
insertionSort(vector<int>& v) {
    if (v.empty()) {
        throw domain_error("Error! Empty input vector!");
    }

    // Iterate over the entire vector to be sorted
    for (vecSzT i = 1; i != v.size(); ++i) {
        int e = v[i];
        // Now insert element e at correct location in the range [0, i + 1),
        // by shifting elements in [0, i) greater than e to the right.
        // This would ensure that after the insertion, all elements in
        // the range [0, i + 1) are sorted
        vecSzT j = i - 1;
        while (j >= 0) {

            if (v[j] > e) {
                // Shift element to right
                v[j + 1] = v[j];
            } else {
                // Insert element 'e' at appropriate location
                v[j + 1] = e;
                break;
            }

            if (j == 0) {
                // Insert element 'e' at appropriate location
                v[j] = e;
                break;
            }
            --j;
        };
    }
}
