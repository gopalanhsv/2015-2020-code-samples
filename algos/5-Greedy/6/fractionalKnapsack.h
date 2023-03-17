#ifndef _FRACTIONAL_KNAPSACK_H_
#define _FRACTIONAL_KNAPSACK_H_

// System headers
#include <vector>

// Local includes

// Using declarations

// Statics, globals, typedefs

// Representation of an item
typedef struct ItemT {
    // Constructors
    ItemT() : val(0), wt(0) {}
    ItemT(int v, int w) : val(v), wt(w) {}
    // Data members
    int val, wt;
} ItemT;

double
maxValueOfFractionalKnapsack(int capacity, std::vector<ItemT> itemV);

std::vector<ItemT>
constructConsolidatedItemVec(
    const std::vector<int>& iValV, const std::vector<int>& iWtV);

#endif /* _FRACTIONAL_KNAPSACK_H_ */
