// System includes
#include <vector>
#include <unordered_map>
#include <queue>
#include <stdexcept>
#include <utility>

// Local includes
#include "array.h"

// Using declarations
using std::vector;
using std::unordered_map;
using std::priority_queue;
using std::domain_error;
using std::pair;

// Statics, typedefs, globals

vector<int>
Array::topKFrequentNumbers(const vector<int>& v, unsigned long k) {
    if (v.empty()) {
        throw domain_error("Error! Empty input vector!");
    }
    if (0 == k || k > v.size()) {
        throw domain_error("Error! Invalid value of k");
    }

    // Generate a frequency count table for the input vector elements
    // Hash map of vector element to its number of occurences
    unordered_map<int, unsigned int> elemFreqTbl;
    for (auto e : v) {
        elemFreqTbl[e]++;
    }

    // Iterate over the input elements (using the frequency table)
    // sequentially. Use them to populate a priority queue which
    // keeps track of the top k frequent elements amongst the ones
    // seen so far. This is done by ensuring that if the priority queue
    // contains more than k elements at any time, remove the least
    // frequent elements(one with min frequency count) from the
    // top/front of the priority queue => min heap based on element
    // frequency count
    typedef pair<int, unsigned int> elemFreqPairT;
    struct elemFreqCmp {
        bool
        operator()(const elemFreqPairT& e1, const elemFreqPairT& e2) {
            return e1.second > e2.second;
        }
    };

    priority_queue<elemFreqPairT, vector<elemFreqPairT>, elemFreqCmp> minHeap;
    // Iterate over the element->frequency count entries in the table
    for (auto elemFreqPair : elemFreqTbl) {
        // Add the entry to PQ maintaining top 'K' frequent elements
        minHeap.push(elemFreqPair);
        // Remove the least frequent element if the size of PQ > K
        if (minHeap.size() > k) {
            minHeap.pop();
        }
    }

    // Use the PQ of top K frequent element, frequency pairs to populate
    // a vector of top K frequent elements
    vector<int> topKFreqElemsV;
    while (!minHeap.empty()) {
        auto elemFreqCntPair = minHeap.top();
        minHeap.pop();
        topKFreqElemsV.push_back(elemFreqCntPair.first);
    }

    return topKFreqElemsV;
}
