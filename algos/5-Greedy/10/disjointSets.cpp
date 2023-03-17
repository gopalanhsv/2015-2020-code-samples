// System headers
#include <vector>
#include <stdexcept>

// Local includes
#include "disjointSets.h"

// Using declarations
using std::vector;
using std::domain_error;

// Statics, typedefs, globals 

// Constructors
DisjointSets::DisjointSets() : _n(0) {
}

void
DisjointSets::makeSet(int n) {
    if (n < 1) {
        throw domain_error("Error! n < 1!");
    }
    _n = n;
    parentIdVec.resize(n);
    setRankVec.resize(n);

    // Creating n disjoint sets by setting set/parent id
    // of each element to itself
    for (vector<int>::size_type i = 0; i != parentIdVec.size(); ++i) {
        parentIdVec[i] = i;
        setRankVec[i] = 0;
    }
}

// Find the set id/id of representative element for given element
int
DisjointSets::findSet(int v) {
    if (v >= _n || v < 0) {
        throw domain_error("Error! Invalid element id!");
    }

    // Find the set id/representative element id
    int id = parentIdVec[v];
    while (id != parentIdVec[id]) {
        id = parentIdVec[id];
    }

    return id;
}

// Do a Union of two sets to which the given elements below
// (if they are placed in disjoint sets)
void
DisjointSets::setUnion(int u, int v) {
    if (u >= _n || u < 0) {
        throw domain_error("Error! Invalid element id!");
    }
    if (v >= _n || v < 0) {
        throw domain_error("Error! Invalid element id!");
    }
    // Find the set id/representative element id for
    // both elements
    int id1 = findSet(u);
    int id2 = findSet(v);
    // Disjoint set union/merge only if the two sets have
    // different set ids
    if (id1 != id2) {
        // Add the set with lower rank to the bigger rank set
        if (setRankVec[id1] > setRankVec[id2]) {
            parentIdVec[id2] = id1;
        } else {
            parentIdVec[id1] = id2;
        }
        if (setRankVec[id1] == setRankVec[id2]) {
            // Set ranks same, so increment rank of 2nd set
            // as 1st set is being added to 2nd set
            setRankVec[id2] += 1;
        }
    }
}
