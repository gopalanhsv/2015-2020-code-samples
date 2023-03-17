// System headers
#include <vector>
#include <queue>
#include <stdexcept>

// Local includes
#include "arrays.h"

// Using declarations
using std::vector;
using std::priority_queue;
using std::domain_error;

// Globals, typedefs, statics
typedef vector<vector<int> >::size_type arrNumT;
typedef vector<int>::size_type arrIdxT;

// Array element entity
class ArrayElement {
public:
    // Constructor
    ArrayElement(int v, arrNumT an, arrIdxT ai) :
        _val(v), _arrNum(an), _arrIdx(ai) {}

    // Accessors
    inline int val() const { return _val; }
    inline arrNumT arrayNum() const { return _arrNum; }
    inline arrIdxT arrayIdx() const { return _arrIdx; }

private:
    int _val; // Element value
    arrNumT _arrNum; // Tracks array to which element belongs
    arrIdxT _arrIdx; // Tracks location within array
};

int
Arrays::kthSmallestNumAmongstAll(
    const vector<vector<int> >& arrayV, unsigned long k) {
    if (arrayV.empty()) {
        throw domain_error("Error! Empty input array vector!");
    }

    // PQ/min heap of elements (1 element each from each input array of
    // sorted arrays) ordered in descending order of element value
    struct ArrayElemCmp {
        // Array elements with lesser value are given higher priority
        bool operator() (const ArrayElement& a1, const ArrayElement& a2) {
            return a1.val() > a2.val();
        }
    };
    priority_queue<ArrayElement, vector<ArrayElement>, ArrayElemCmp> minHeap;

    // Push least value element (i.e. element at index 0 from each of the
    // sorted input arrays to heap)
    for (arrNumT i = 0; i != arrayV.size(); ++i) {
        minHeap.push(ArrayElement(arrayV[i][0], i, 0));
    }

    unsigned long smallestElementIdx = 0;
    while (!minHeap.empty()) {
        // Pop off the smallest element from min-heap
        auto se = minHeap.top();
        minHeap.pop();

        // Kth element being popped off => Kth smallest element
        // across all arrays
        if (++smallestElementIdx == k) {
            return se.val();
        }

        // Replace element which is popped off with next greater element
        // from the same array to which the popped off element belonged to
        arrNumT arrNum = se.arrayNum();
        arrIdxT nextArrIdx = se.arrayIdx() + 1;
        if (nextArrIdx < arrayV[arrNum].size()) {
            minHeap.push(
                ArrayElement(arrayV[arrNum][nextArrIdx], arrNum, nextArrIdx));
        }
    }

    throw domain_error("Error! Total elements lesser than k!");
}
