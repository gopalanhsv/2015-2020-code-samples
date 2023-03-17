// System headers
#include <vector>
#include <stdexcept>
#include <algorithm>

// Local includes
#include "knapSack.h"

// Using declarations
using std::vector;
using std::domain_error;
using std::max;

// Statics, typedefs, globals

int
maxValueOfknapsackRecursive(const vector<int>& itemCosts,
    const vector<int>& itemWts, vecSzT nItems, int capacity) {

    // We will be considering only the first 'nItems' of the
    // items (from both item vectors) for insertion into the knapsack

    // Base cases
    // If no items are being considered for insertion into the
    // knapsack, value of knapsack would be 0
    if (0 == nItems) {
        return 0;
    }
    // If items are being considered for insertion into the knapsack
    // with capacity 0, nothing can be inserted & value of knapsack would be 0
    if (0 != nItems && 0 == capacity) {
        return 0;
    }

    // Max value of the knapsack considering the 1st nItems from both
    // the item vectors would be the maximum of the following two values :-
    // 1. If the last item wt exceeds the current knapsack capacity, exclude it
    //    from knaspsack. Consider max value of the knapsack excluding last
    //    item (at index nItems - 1) for the same capacity
    int maxValExcludingLastItem =
        maxValueOfknapsackRecursive(itemCosts, itemWts, nItems - 1, capacity);
    int lastItemWt = itemWts[nItems - 1];
    if (lastItemWt > capacity) {
        return maxValExcludingLastItem;
    }

    // 2. If the last item wt does not exceed the current knapsack capacity,
    //    include it in the knapsack. Consider max value of the knapsack
    //    including last item (at index nItems - 1), by also finding the value for
    //    knapsack for lesser capacity by reducing the last item wt
    int lastItemCost = itemCosts[nItems - 1];
    int maxValIncludingLastItem = lastItemCost +
        maxValueOfknapsackRecursive(itemCosts, itemWts, nItems - 1,
            capacity - lastItemWt);

    return max(maxValExcludingLastItem, maxValIncludingLastItem);
}

int
maxValueOfknapsackRecursive(const vector<int>& itemCosts,
    const vector<int>& itemWts, int capacity) {

    if (itemCosts.empty() || capacity <= 0) {
        throw domain_error("Error! Empty input vector/invalid capacity val!");
    }

    if (itemCosts.size() != itemWts.size()) {
        throw domain_error("Error! "
            "Mismatch in sizes of item costs and item wts vector!");
    }

    return maxValueOfknapsackRecursive(itemCosts, itemWts,
        itemCosts.size(), capacity);
}

int
maxValueOfknapsackRecursiveDPMemoization(const vector<int>& itemCosts,
    const vector<int>& itemWts, vecSzT nItems, int capacity,
    vector<vector<int> > knapsackValTbl) {

    // We will be considering only the first 'nItems' of the
    // items (from both item vectors) for insertion into the knapsack

    // Base cases
    // If no items are being considered for insertion into the
    // knapsack, value of knapsack would be 0
    if (0 == nItems) {
        return 0;
    }
    // If items are being considered for insertion into the knapsack
    // with capacity 0, nothing can be inserted & value of knapsack would be 0
    if (0 != nItems && 0 == capacity) {
        return 0;
    }

    // Max value of the knapsack considering the 1st nItems from both
    // the item vectors would be the maximum of the following two values :-
    // 1. If the last item wt exceeds the current knapsack capacity, exclude it
    //    from knaspsack. Consider max value of the knapsack excluding last
    //    item (at index nItems - 1) for the same capacity
    int maxValExcludingLastItem =
        maxValueOfknapsackRecursiveDPMemoization(
            itemCosts, itemWts, nItems - 1, capacity, knapsackValTbl);
    int lastItemWt = itemWts[nItems - 1];
    if (lastItemWt > capacity) {
        // Update the knapsack lookup table
        knapsackValTbl[nItems][capacity] = maxValExcludingLastItem;
        return knapsackValTbl[nItems][capacity];
    }

    // 2. If the last item wt does not exceed the current knapsack capacity,
    //    include it in the knapsack. Consider max value of the knapsack
    //    including last item (at index nItems - 1), by also finding the value for
    //    knapsack for lesser capacity by reducing the last item wt
    int lastItemCost = itemCosts[nItems - 1];
    int maxValIncludingLastItem = lastItemCost +
        maxValueOfknapsackRecursiveDPMemoization(itemCosts, itemWts,
            nItems - 1, capacity - lastItemWt, knapsackValTbl);

    // Update the knapsack lookup table
    knapsackValTbl[nItems][capacity] = 
        max(maxValExcludingLastItem, maxValIncludingLastItem);

    return knapsackValTbl[nItems][capacity];
}

int
maxValueOfknapsackRecursiveDPMemoization(const vector<int>& itemCosts,
    const vector<int>& itemWts, int capacity) {

    if (itemCosts.empty() || capacity <= 0) {
        throw domain_error("Error! Empty input vector/invalid capacity val!");
    }

    if (itemCosts.size() != itemWts.size()) {
        throw domain_error("Error! "
            "Mismatch in sizes of item costs and item wts vector!");
    }

    // Lookup table mapping the max values of knapsack for a given capacity
    // considering only particular first set/number of items from the 
    // item costs+wts vectors. All entries in the lookup table initialized to
    // -1 (invalid val). Row id respresnts the number of first set of items being
    // considered while column id represent the capacity of the knapsack
    vector<vector<int> >
        knapsackValTbl(itemCosts.size() + 1, vector<int>(capacity + 1, -1));
    return maxValueOfknapsackRecursiveDPMemoization(itemCosts, itemWts,
        itemCosts.size(), capacity, knapsackValTbl);
}

int
maxValueOfknapsackDPTabulation(const vector<int>& itemCosts,
    const vector<int>& itemWts, int capacity) {

    if (itemCosts.empty() || capacity <= 0) {
        throw domain_error("Error! Empty input vector/invalid capacity val!");
    }

    if (itemCosts.size() != itemWts.size()) {
        throw domain_error("Error! "
            "Mismatch in sizes of item costs and item wts vector!");
    }

    // Lookup table mapping the max values of knapsack for a given capacity
    // considering only particular first set/number of items from the 
    // item costs+wts vectors. All entries in the lookup table initialized to
    // -1 (invalid val). Row id respresnts the number of first set of items
    // being considered while column id represent the capacity of the knapsack
    vector<vector<int> >
        knapsackValTbl(itemCosts.size() + 1, vector<int>(capacity + 1, -1));

    // Now build up all the other entries in the DP knapsack value table
    for (vecVecSzT ni = 0; ni != itemCosts.size() + 1; ++ni) {
        for (vecSzT c = 0; c != capacity + 1; ++c) {
            int lastItemWt = itemWts[ni - 1];
            int lastItemCost = itemCosts[ni - 1];
            if (0 == ni || 0 == c) {
                // If the either the number of items to be inserted in knapsack
                // is nil; or the knapsack capacity is nil, max value of the
                // knapsack would be nil
                knapsackValTbl[ni][c] = 0;
            } else if (lastItemWt > capacity) {
                // 1. Last item wt exceeds current knapsack capacity, exclude
                //    it from knapsack. Consider max value of the knapsack
                //    excluding last item for the same capacity
                knapsackValTbl[ni][c] = knapsackValTbl[ni - 1][c];
            } else {
                // 2. Last item wt does not exceed the current knapsack capacity.
                //    Choose the max of the knapsack values -- that including
                //    last item, or that excluding the last item
                knapsackValTbl[ni][c] =
                    max(knapsackValTbl[ni - 1][c],
                        lastItemCost + knapsackValTbl[ni - 1][c - lastItemWt]);
            }
        }
    }

    // Bottom right corner of the DP table will give max value of knapsack
    return knapsackValTbl[itemCosts.size()][capacity];
}
