#ifndef _DISJOINT_SETS_H_
#define _DISJOINT_SETS_H_

// System headers
#include <vector>

// Local includes

// Using declarations

// Statics, typedefs, globals 

class DisjointSets {
public:
    // Constructor
    DisjointSets();
    // Make N disjoint sets
    void makeSet(int n);
    // Find the set id/id of representative element for given element
    int findSet(int v);
    // Do a Union of two sets to which the given elements below
    // (if they are placed in disjoint sets)
    void setUnion(int u, int v);

private:
    // Member functions

    // Data members
    // Number of elements
    int _n;
    // Vector storing set id/parent element id for each element
    std::vector<int> parentIdVec;
    // Vector storing rank (i.e tree height or num set
    // elements) for each element
    std::vector<int> setRankVec;
};

#endif /* _DISJOINT_SETS_H_ */
