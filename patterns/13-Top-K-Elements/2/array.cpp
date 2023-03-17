// System headers
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <queue>

// Local includes
#include "array.h"

// Using declarations
using std::domain_error;
using std::vector;
using std::priority_queue;
using std::less;

// Statics, typedefs, globals

int
Array::kthSmallestNumber(const std::vector<int>& v, unsigned long k) {
    if (v.empty()) {
        throw domain_error("Error! Empty input vector!");
    }
    if (k >= v.size() || 0 == k) {
        throw domain_error("Error! Invalid value of k");
    }

    // Iterate over the vector elements sequentially and use them to
    // construct + maintain a heap/priority queue of k smallest
    // elements seen so far. The heap/priority queue should be a 
    // max-heap to ensure that its top would always have the kth
    // smallest element seen so far
    priority_queue<int, vector<int>, less<int> > maxHeap;
    for (auto e : v) {
        // Add current element to heap
        maxHeap.push(e);
        // Current element addition to PQ/heap exceeds size beyond 'k'
        // Remove the max value element from PQ to ensure that it contains
        // only 'k' elements seen so far
        if (maxHeap.size() > k) {
            maxHeap.pop();
        }
    }

    // PQ top has max element amongst 'k' smallest elements seen so far
    // Would be the kth smallest elements
    return maxHeap.top();
}
