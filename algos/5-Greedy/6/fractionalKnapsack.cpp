// System headers
#include <vector>
#include <stdexcept>
#include <algorithm>

// Local includes
#include "fractionalKnapsack.h"

// Using declarations
using std::vector;
using std::sort;
using std::domain_error;

// Statics, globals, typedefs

bool
compareItemRatios(const ItemT& i1, const ItemT& i2) {
    return ((double(i1.val)/(i1.wt)) > (double(i2.val)/(i2.wt)));
}

double
maxValueOfFractionalKnapsack(int capacity, vector<ItemT> itemV) {
    if (itemV.empty()) {
        throw domain_error("Error! Empty input vector of items! Exiting...!");
    }

    // Sort the knapsack items in the decreasing order of value to weight ratios
    sort(itemV.begin(), itemV.end(), compareItemRatios);

    // For the knapsack value to have max value for a given capacity, greedily
    // fill it up with items having the max value for a given weight, or in other
    // words with items in the decreasing order of value/weight ratio

    // Iterate over the item vectors (already sorted in the decreasing order
    // of value/weight ratio)
    typedef vector<ItemT>::size_type vecSzT;
    double knapsackVal = 0.0;
    double knapsackWt = 0.0;
    for (vecSzT i = 0; i != itemV.size(); ++i) {
        // If the current item when newly added to knapsack
        // is does not result in knapsack weight exceeding knapsack
        // capacity, add the item wholly and move to next item
        // Otherwise do partial addition of the item in order
        // to fill knapsack upto its capacity and exit
        const struct ItemT& item = itemV[i];
        if (knapsackWt + item.wt < capacity) {
            // Full addition of item
            knapsackWt += item.wt;
            knapsackVal += item.val;
        } else {
            // Partial addition of item and exit
            double remainderWt = double(capacity) - knapsackWt;
            knapsackVal += (item.val * (remainderWt / item.wt));
            break;
        }
    }

    return knapsackVal;
}

vector<ItemT>
constructConsolidatedItemVec(
    const std::vector<int>& iValV, const std::vector<int>& iWtV) {
    if (iValV.empty() || iWtV.empty()) {
        throw domain_error("Error! Empty input val or wt vector! Exiting...!");
    }

    if (iValV.size() != iWtV.size()) {
        throw domain_error("Error! "
            "Mismatch in sizes of input val & wt vectors! Exiting...!");
    }

    typedef vector<int>::size_type vecSzT;
    vector<ItemT> itemV;
    for (vecSzT i = 0; i != iValV.size(); ++i) {
        ItemT item(iValV[i], iWtV[i]);
        itemV.push_back(item);
    }

    return itemV;
}
