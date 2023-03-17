// System headers
#include <vector>
#include <stdexcept>
#include <queue>
#include <functional>
#include <iostream>

// Local includes
#include "rope.h"

// Using declarations
using std::vector;
using std::priority_queue;
using std::domain_error;
using std::greater;

// Statics, typedefs, globals

unsigned long
Rope::connectWithMinCost(const vector<unsigned int>& rv) {
    if (rv.empty()) {
        throw domain_error("Error! Empty input rope costs array!");
    }

    // Maintain a min heap/PQ of the rope costs so that we can follow
    // greedy approach to removing 2 ropes with minimum cost from heap,
    // connecting them and adding them back to heap in order repeatedly;
    // to end up with single minimum cost connected rope
    priority_queue<unsigned int,
        vector<unsigned int>, greater<unsigned int> > ropeCostsMinHeap;
    // Add all the rope costs from input array to min heap
    for (auto cost : rv) {
        ropeCostsMinHeap.push(cost);
    }

    // Keep processing all the rope costs in min heap, connecting
    // ropes together till we end with a single connected rope
    // built up from individual ropes (i.e. heap is left with 1 element)
    unsigned long totalConnectionCost = 0;
    while (ropeCostsMinHeap.size() != 1) {
        // Since it is a min heap, popping off two elements from top
        // would give the two ropes (individual or connected) with
        // minimum cost at that point
        unsigned int minCost1 = ropeCostsMinHeap.top();
        ropeCostsMinHeap.pop();
        unsigned int minCost2 = ropeCostsMinHeap.top();
        ropeCostsMinHeap.pop();
        // Connect the 2 min cost together and add the connected
        // rope back to heap
        unsigned int connectedRopeCost = minCost1 + minCost2;
        totalConnectionCost += connectedRopeCost;
        ropeCostsMinHeap.push(connectedRopeCost);
    }

    return totalConnectionCost;
}
