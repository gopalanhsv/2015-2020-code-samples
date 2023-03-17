// System headers
#include <vector>
#include <stdexcept>
#include <queue>
#include <deque>
#include <utility>
#include <algorithm>
#include <cmath>

// Local includes
#include "array.h"

// Using declarations
using std::vector;
using std::deque;
using std::priority_queue;
using std::pair;
using std::make_pair;
using std::domain_error;
using std::min;
using std::sort;

// Statics, typedefs, globals
typedef vector<int>::size_type vecSzT;

vector<int>::size_type
Array::findClosestNumToKey(const std::vector<int>& v, int key) {
    // Binary search to determine the element in vector closest to key
    // (i.e. min diff from key). So search for key itself
    vecSzT startIdx = 0;
    vecSzT endIdx = v.size() - 1;
    while (startIdx <= endIdx) {
        vecSzT mid = startIdx + (endIdx - startIdx) / 2;
        if (v[mid] == key) {
            return mid; // Key found
        }

        if (key > v[mid]) {
            // Key in upper half of search range
            startIdx = mid + 1;
        } else {
            // Key in lower half of search range
            if (0 == endIdx) {
                break;
            }
            endIdx = (0 == mid) ? 0 : mid - 1;
        }
    }
    // Key not found, but it would lie in the range bounded by
    // adjacent elements at [endIdx, startIdx]. So compute location
    // of element closest to key using the elements at these locations
    if (abs(key - v[startIdx]) > abs(key - v[endIdx])) {
        return endIdx;
    }
    return startIdx;
}

vector<int>
Array::nClosestNumbersToKey(const vector<int>& v, int key, unsigned int n) {
    if (v.empty()) {
        throw domain_error("Error! Empty input vector!");
    }
    if (n > v.size()) {
        throw domain_error("Error! Invalid value of nos to be found!");
    }

    // Location of element closest to key (can be the key itself)
    vecSzT closestIdx = findClosestNumToKey(v, key);

    // Examine all elements in range +n, -n on either sides of element
    // closest to key using a priority queue (min heap of elements ordered on
    // the basis of difference from key element); and determine n closest
    // elements to give key
    // Range [-n, +n] on either side of element closest to key
    vecSzT loIdx = (closestIdx < n) ? 0 : closestIdx - n;
    vecSzT hiIdx = min(closestIdx + n, v.size() - 1);
    // Pair holding an element and its difference from key
    typedef pair<int, unsigned int> elemKeyDiffPairT;
    struct elemKeyDiffPairCmp {
        // Comparison based on diff from key (for min heap)
        bool operator() (const elemKeyDiffPairT& p1,
            const elemKeyDiffPairT& p2) const {
            return p1.second > p2.second;
        }
    };
    // PQ/min heap of elements ordered on the basis of difference from key
    priority_queue<elemKeyDiffPairT,
        vector<elemKeyDiffPairT>, elemKeyDiffPairCmp> minHeap;  
    // Add the elements in search range [-n, +n] to key
    for (vecSzT i = loIdx; i <= hiIdx; ++i) {
        elemKeyDiffPairT ekdp = make_pair(v[i], abs(v[i] - key));
        minHeap.push(ekdp);
    }

    // Extract 'n' elements from min heap to get 'n' closest elements to key
    vector<int> nClosestElemsV;
    for (unsigned long i = 0; i != n; ++i) {
        elemKeyDiffPairT ekdp = minHeap.top();
        minHeap.pop();
        nClosestElemsV.push_back(ekdp.first);
    }

    // Return sorted n closest elements to key
    sort(nClosestElemsV.begin(), nClosestElemsV.end());
    return nClosestElemsV;
}

vector<int>
Array::nClosestNumbersToKeyTwoPointerMethod(
    const vector<int>& v, int key, unsigned int n) {
    if (v.empty()) {
        throw domain_error("Error! Empty input vector!");
    }
    if (n > v.size()) {
        throw domain_error("Error! Invalid value of nos to be found!");
    }

    // Location of element closest to key (can be the key itself)
    vecSzT closestIdx = findClosestNumToKey(v, key);

    // Examine all elements on either sides of element closest to key
    // using two pointer method, to determine 'n' elements closest to
    // key. Use a deque (double ended queue) to get closest elements in
    // sorted order
    deque<int> nClosestElemsD;
    // Start off with 2 pointers one at the closest element and other
    // next to closest element
    vecSzT loPtr = closestIdx;
    vecSzT hiPtr = closestIdx + 1;
    bool elemAtIdx0Added = false;
    for (unsigned long i = 0; i != n; ++i) {
        // Examine elements at the 2 pointer locations, add the element
        // closest to key from these two locations to the deque
        // of 'n' closest elements. Pointer location from which the
        // element gets added has to be advanced appropriately to next
        // element up/down as the case maybe
        if (!elemAtIdx0Added && hiPtr < v.size()) {
            // loPtr and hiPtr have not touched range boundaries
            if (abs(key - v[loPtr]) < abs(key - v[hiPtr])) {
                if (!elemAtIdx0Added && (0 == loPtr)) {
                    nClosestElemsD.push_front(v[loPtr]);
                    elemAtIdx0Added = true;
                } else {
                    nClosestElemsD.push_front(v[loPtr--]);
                }
            } else {
                nClosestElemsD.push_back(v[hiPtr++]);
            }
        } else if (!elemAtIdx0Added) {
            // loPtr has not touched lower range boundary
            if (0 == loPtr) {
                nClosestElemsD.push_front(v[loPtr]);
                elemAtIdx0Added = true;
            } else {
                nClosestElemsD.push_front(v[loPtr--]);
            }
        } else if (hiPtr < v.size()) {
            // hiPtr has not touched upper range boundary
            nClosestElemsD.push_back(v[hiPtr++]);
        }
    }

    // Copy 'n' elements from deque to vector
    vector<int> nClosestElemsV;
    copy(nClosestElemsD.begin(),
        nClosestElemsD.end(), back_inserter(nClosestElemsV));
    return nClosestElemsV;
}
