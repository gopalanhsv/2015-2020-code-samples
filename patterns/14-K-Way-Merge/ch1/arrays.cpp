// System headers
#include <vector>
#include <queue>
#include <utility>
#include <functional>
#include <stdexcept>
#include <algorithm>

// Local includes
#include "arrays.h"

// Using namespaces
using std::vector;
using std::priority_queue;
using std::pair;
using std::make_pair;
using std::less;
using std::domain_error;
using std::push_heap;
using std::pop_heap;

// Statics, typedefs, globals

vector<pair<int, int> >
Arrays::findPairsWithLargestSum(const vector<int>& v1,
    const vector<int>& v2, unsigned int nPairs) {
    if (v1.empty() || v2.empty()) {
        throw domain_error("Error! One/both input vectors are empty!");
    }
    if (0 == nPairs || nPairs > (v1.size() * v2.size())) {
        throw domain_error("Error! Invalid num pairs asked for!");
    }

    // Vector holding upto 'nPairs' of number pairs from input vector ordered
    // in the form of a min heap in accordance with the sum of number pairs
    vector<pair<int, int> > minHeap;
    struct pairCmp {
        // Pairs with a lower sum are given priority over pairs with higher sum
        // in the min heap
        bool operator() (const pair<int, int>& p1,
            const pair<int, int>& p2) const {
            return ((p1.first + p1.second) > (p2.first + p2.second));
        }
    };

    // Iterate over a maximum of 'nPairs' numbers each from both input arrays
    // (numbers beyond this range in both arrays will not figure in the pairs
    // with largest sum as the arrays are in descending order)
    typedef vector<int>::size_type vecSzT;
    for (vecSzT i = 0; i != nPairs && i != v1.size(); ++i) {
        for (vecSzT j = 0; j != nPairs && j != v2.size(); ++j) {
            pair<int, int> newPair = make_pair(v1[i], v2[j]);
            if (minHeap.size() < nPairs) {
                // PQ doesn't have nPairs pairs. Insert new pair to min-heap
                minHeap.push_back(newPair);
                push_heap(minHeap.begin(), minHeap.end(), pairCmp());
            } else {
                // PQ has nPairs pairs

                // New pair sum less than minimum sum pair in PQ (i.e pair
                // at PQ front/top) implies no more search required as all
                // other successive array pairs will be lesser in sum (as
                // arrays sorted in descending order) 
                auto topPair = minHeap.front(); 
                if (newPair.first + newPair.second <
                    topPair.first + topPair.second) {
                    break;
                }

                // Add new pair to PQ only if its sum is more than that of
                // minimum sum pair in PQ (i.e pair at PQ top/front). Adding
                // new pair done after popping PQ top
                pop_heap(minHeap.begin(), minHeap.end(), pairCmp());
                minHeap.pop_back();
                minHeap.push_back(newPair);
                push_heap(minHeap.begin(), minHeap.end(), pairCmp());
            }
        }
    }

    return minHeap;
}
