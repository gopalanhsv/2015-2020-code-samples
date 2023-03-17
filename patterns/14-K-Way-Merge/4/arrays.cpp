// System headers
#include <utility>
#include <vector>
#include <queue>
#include <stdexcept>
#include <algorithm>

// Local includes
#include "arrays.h"

// Using declarations
using std::pair;
using std::make_pair;
using std::vector;
using std::priority_queue;
using std::domain_error;
using std::max;

// Statics, typedefs, globals
typedef vector<int>::size_type arrIdxT;
typedef vector<vector<int> >::size_type arrNumT;

class ArrayElemT {
public:
    // Constructor
    ArrayElemT(int v, arrNumT an, arrIdxT ai) :
        _v(v), _aNum(an), _aIdx(ai) {}

    // Accessors
    inline int val() const { return _v; }
    inline arrNumT arrayNum() const { return _aNum; }
    inline arrIdxT arrayIdx() const { return _aIdx; }

private:
    // Data members
    // Tracks array element value
    int _v;
    // Tracks array element array id
    arrNumT _aNum;
    // Tracks array element location within array
    arrIdxT _aIdx;
};

// Return 2 numbers forming smallest range encompassing
// at least one element from each array
pair<int, int>
Array::smallestRange(const std::vector<std::vector<int> >& arrayV) {
    if (arrayV.empty()) {
        throw domain_error("Error! Empty input array of arrays!");
    }

    // Iterate over all the numbers in arranged in ascending order
    // sequentially using a flexible sized sliding window to demarcate
    // the range extremeties such that at least one number from each
    // array gets included in the window.
    // Update range extremeties on sliding the window to include next
    // number in an array if range is smaller such that when all numbers
    // in at least one array are examined, the range extremeties will be
    // smallest range

    // Sliding window would be formed by a min-heap/PQ of one unprocessed
    // element each from each of the input arrays
    struct ArrayElemCmpT {
        // Array elements are ordered in PQ/min heap with smaller elements
        // at higher priority
        bool operator() (const ArrayElemT& e1, const ArrayElemT& e2) const {
            return e1.val() > e2.val();
        }
    };
    priority_queue<ArrayElemT, vector<ArrayElemT>, ArrayElemCmpT> minHeap;

    // Maximum of elements would be end of range
    int currHeapMax = std::numeric_limits<int>::min();
    // Initialize the PQ/min heap with the first element from each of the
    // input arrays
    for (arrNumT i = 0; i != arrayV.size(); ++i) {
        if (arrayV[i].empty()) {
            throw domain_error("Error! Empty input array!");
        }
        currHeapMax = max(currHeapMax, arrayV[i][0]);
        minHeap.push(ArrayElemT(arrayV[i][0], i, 0));
    }

    // Extremeties/range of the current smallest sliding window
    int rangeStart, rangeEnd;
    // Minimum element/heap top would be start of range
    rangeStart = minHeap.top().val();
    rangeEnd = currHeapMax;

    while (!minHeap.empty()) {
        // Pop off the element at heap top
        auto top = minHeap.top();
        minHeap.pop();

        // Replace element at heap top by the next unprocessed element from
        // same input array to which element at heap top belonged in order
        // to slide the window
        auto an = top.arrayNum();
        auto nextArrIdx = top.arrayIdx() + 1;
        if (nextArrIdx < arrayV[an].size()) {
            int ne = arrayV[an][nextArrIdx];
            currHeapMax = max(currHeapMax, ne);
            minHeap.push(ArrayElemT(ne, an, nextArrIdx));
        } else {
            // At least one array has been fully examined, so exit
            break;
        }

        // Update the smallest range if new range of elements in sliding
        // window/heap is smaller
        if (rangeEnd - rangeStart > currHeapMax - minHeap.top().val()) {
            rangeEnd = currHeapMax;
            rangeStart = minHeap.top().val();
        }
    }

    return make_pair(rangeStart, rangeEnd);
}
