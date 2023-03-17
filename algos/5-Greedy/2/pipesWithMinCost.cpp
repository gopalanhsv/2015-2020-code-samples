// System headers
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <queue>
#include <limits>

// Local includes
#include "pipesWithMinCost.h"

// Using declarations
using std::vector;
using std::domain_error;
using std::make_heap;
using std::push_heap;
using std::pop_heap;
using std::greater;
using std::priority_queue;
using std::deque;
using std::next_permutation;

// Typedefs, statics, globals

int
connectPipesWithMinCostUsingBruteForce(vector<int> pipeCost) {
    if (pipeCost.empty()) {
        throw domain_error("Error! Empty input vector! Exiting...!");
    }

    // Single pipe
    if (1 == pipeCost.size()) {
        return pipeCost[0];
    }

    // Init vector for generating all possible combinations
    // of combining the pipes
    typedef vector<int>::size_type vecSzT;
    vector<vecSzT> pipeIdxCombination(pipeCost.size(), 0);
    for (vecSzT i = 0; i != pipeCost.size(); ++i) {
        pipeIdxCombination[i] = i;
    }

    int minCost = std::numeric_limits<int>::max();
    // Iterate over all possible permutations for combining pipes
    do {
        int cost = 0;
        // Compute the cost for the current permutation of
        // combining pipes
        int prevNewPipeCost = pipeCost[pipeIdxCombination[0]];
        for (vecSzT i = 1; i != pipeCost.size(); ++i) {
            int newPipeCost = pipeCost[pipeIdxCombination[i]] + prevNewPipeCost;
            cost += newPipeCost;
            prevNewPipeCost = newPipeCost;
        }

        // Update the min cost if current permutation
        // strategy gives a better cost
        if (cost < minCost) {
            minCost = cost;
        }
    } while (next_permutation(pipeIdxCombination.begin(), pipeIdxCombination.end()));

    return minCost;
}

int
connectPipesWithMinCostUsingMinHeap(vector<int> pipeCost) {
    if (pipeCost.empty()) {
        throw domain_error("Error! Empty input vector! Exiting...!");
    }

    // Single pipe
    if (1 == pipeCost.size()) {
        return pipeCost[0];
    }

    // Make a min heap of the pipes cost vector (so that 
    // elements can be popped from it in the increasing order
    // of cost)
    make_heap(pipeCost.begin(), pipeCost.end(), greater<int>());
    // At every iteration follow the greedy approach --
    // 1. Select 2 pipes with the minimum cost (remove from pipe cost vector)
    // 2. Connect the 2 min cost pipes to make a new pipe
    // 3. Add the cost of new combined pipe to pipe cost vector
    // 4. Repeat the above steps till only a single combined pipe is left
    // Since we are always selecting 2 min cost pipes at each step, it is
    // ensured that we will end up connecting pipes with least cost
    int totalCost = 0;
    while (1 != pipeCost.size()) {
        // Select pipe with the minimum cost and remove it
        pop_heap(pipeCost.begin(), pipeCost.end(), greater<int>());
        int firstPipeCost = pipeCost.back();
        pipeCost.pop_back();
        // Select pipe with the minimum cost and remove it
        pop_heap(pipeCost.begin(), pipeCost.end(), greater<int>());
        int secondPipeCost = pipeCost.back();
        pipeCost.pop_back();
        // Connect the 2 min cost pipes to make a new pipe
        int newPipeCost = firstPipeCost + secondPipeCost;
        totalCost += newPipeCost;
        // Add the new pipe to pipe cost min heap
        pipeCost.push_back(newPipeCost);
        push_heap(pipeCost.begin(), pipeCost.end(), greater<int>());
    }

    return totalCost;
}

int
connectPipesWithMinCostUsingPriorityQ(vector<int> pipeCost) {
    if (pipeCost.empty()) {
        throw domain_error("Error! Empty input vector! Exiting...!");
    }
    // Single pipe case
    if (1 == pipeCost.size()) {
        return pipeCost[0];
    }

    // Make a PQ of pipes ordered in decreasing order of cost,
    // so that pipes may be removed from it in same order
    priority_queue<int, deque<int>, greater<int> >
        pQ(pipeCost.begin(), pipeCost.end());
    int totalCost = 0;
    // Adopt the following greedy approach --
    // 1. Construct a new pipe using 2 pipes with min cost from
    // the priority queue
    // 2. Add the new pipe to the priority queue
    // 3. Repeat the above till a single pipe stays in the priority queue
    // Above approach leads min total cost since the least cost
    // pipes are always selected at each iteration
    while (1 != pQ.size()) {
        int firstPipeCost = pQ.top();
        pQ.pop();
        int secondPipeCost = pQ.top();
        pQ.pop();
        int newPipeCost = firstPipeCost + secondPipeCost;
        totalCost += newPipeCost;
        pQ.push(newPipeCost);
    }

    return totalCost;
}
