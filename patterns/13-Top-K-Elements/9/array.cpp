// System headers
#include <vector>
#include <unordered_map>
#include <queue>
#include <utility>
#include <stdexcept>
#include <iostream>

// Local includes
#include "array.h"

// Using declarations
using std::vector;
using std::unordered_map;
using std::priority_queue;
using std::domain_error;
using std::pair;
using std::cout;
using std::endl;

// Statics, typedefs, globals

unsigned int
Array::maxDistinctElementsPostRemoval(
    const vector<int>& v, unsigned int nRemove) {
    if (v.empty()) {
        throw domain_error("Error! Empty input vector!");
    }
    // Num of elements to be removed exceeds array size => no elements would
    // be left post removal
    if (v.size() <= nRemove) {
        return 0;
    }

    // Construct frequency table mapping each element to its occurence count
    unordered_map<int, unsigned int> elemFreqCntTbl;
    for (auto e : v) {
        elemFreqCntTbl[e]++;
    }

    // Using the above frequency table, construct priority queue/min-heap of
    // element entries (for elements which have multiple occurences) with
    // least frequent elements at top and most frequent elements at bottom
    typedef pair<int, unsigned int> elemFreqCntPairT;
    struct elemFreqCntCmp {
        bool operator() (
            const elemFreqCntPairT& p1, const elemFreqCntPairT& p2) {
            return p1.second > p2.second;
        }
    };
    priority_queue<elemFreqCntPairT,
        vector<elemFreqCntPairT>, elemFreqCntCmp> multiElemsMinHeap;
    unsigned int nDistinctElems = 0;
    for (auto elemFreqCntPair : elemFreqCntTbl) {
        if (elemFreqCntPair.second == 1) {
            // Single element occurence -> increment count
            ++nDistinctElems;
        } else {
            // Multiple element occurence -> add to PQ
            multiElemsMinHeap.push(elemFreqCntPair);
        }
    }

    // Cycle through the min heap containing elements which occur multiple
    // time commencing from the least frequent to most frequent. For
    // each element, attempt to remove all occurences of it except 1
    // (to leave it as a distinct element) if feasible. Proceeding from least
    // frequent to most frequent element sequentially is greedy approach of
    // attempting to make most number of multiple occurrence elements distinct
    while (nRemove > 0 && !multiElemsMinHeap.empty()) {
        // Remove multiple occurrence element from PQ top
        auto elemFreqCntPair = multiElemsMinHeap.top();
        multiElemsMinHeap.pop();
        // Remove all occurences of dequeued element except
        // 1 if feasible to make it distinct
        unsigned int nElems = elemFreqCntPair.second;
        if (nRemove >= (nElems - 1)) {
            // Update number of distinct elements and number
            // left to be removed
            nRemove -= (nElems - 1);
            ++nDistinctElems;
        } else {
            // num elements - 1 more that number which can be
            // removed. So remove how much ever possible
            nRemove = 0;
        }
    }
    // Remove some distinct elements as per remaining remove count
    nDistinctElems -= nRemove;

    return nDistinctElems;
}
