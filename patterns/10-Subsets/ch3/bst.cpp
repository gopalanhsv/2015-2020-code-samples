// System headers
#include <stdexcept>
#include <unordered_map>

// Local includes
#include "bst.h"

// Using declarations
using std::domain_error;
using std::unordered_map;

// Statics, typedefs, globals

// Hash table mapping the number of BST nodes to the number of unique
// BST trees which can be constructed using same.
unordered_map<long, long long> dpMemoizationTbl;

unsigned long long
BST::numUniqueTrees(long numNodes) {
    if (numNodes < 0) {
        throw domain_error("Error! Invalid -ve number of bst nodes!");
    }

    // Recursively determine number of unique BSTs which can be
    // constructed using nodes -> 1 to numNodes 
    return numUniqueTreesRecursive(numNodes);
}

unsigned long long
BST::numUniqueTreesRecursive(long numNodes) {
    // Recursion termination base case : 0/1 nodes => 1 tree
    if (numNodes < 1) {
        return 1;
    }

    long long totalTrees = 0;
    // Iterate over the set of node numbers which form the BST.
    // Determine the number of unique trees which can be constructed
    // using each of the nodes as root sequentially one by one; and
    // add up the number of unique trees
    for (long i = 1; i <= numNodes; ++i) {
        // Recursively compute the number of BSTs which can constructed
        // with root as 'i', nodes 1 to i - 1 in left subtree,
        // nodes i + 1 to numNodes in right subtree,
        long long nLeftSubtrees = numUniqueTreesRecursive(i - 1);
        long long nRightSubtrees = numUniqueTreesRecursive(numNodes - i);
        long long numTreesRootedAtI = nLeftSubtrees * nRightSubtrees;
        // Update total number of unique trees with the number of trees
        // which can be constructed rooted at 'i'
        totalTrees += numTreesRootedAtI;
    }

    return totalTrees;
}

unsigned long long
BST::numUniqueTreesDPMemoization(long numNodes) {
    if (numNodes < 0) {
        throw domain_error("Error! Invalid -ve number of bst nodes!");
    }

    // Recursively determine number of unique BSTs which can be
    // constructed using nodes -> 1 to numNodes 
    return numUniqueTreesRecursiveDPMemoization(numNodes);
}

unsigned long long
BST::numUniqueTreesRecursiveDPMemoization(long numNodes) {
    // Recursion termination base case : 0/1 nodes => 1 tree
    if (numNodes < 1) {
        return 1;
    }

    // Check if the memoization table has precomputed entry from an
    // earlier recursion iteration giving the number of unique bst
    // trees for given number of nodes
    if (dpMemoizationTbl.find(numNodes) != dpMemoizationTbl.end()) {
        return dpMemoizationTbl[numNodes];
    }

    long long totalTrees = 0;
    // Iterate over the set of node numbers which form the BST.
    // Determine the number of unique trees which can be constructed
    // using each of the nodes as root sequentially one by one; and
    // add up the number of unique trees
    for (long i = 1; i <= numNodes; ++i) {
        // Recursively compute the number of BSTs which can constructed
        // with root as 'i', nodes 1 to i - 1 in left subtree,
        // nodes i + 1 to numNodes in right subtree,
        long long nLeftSubtrees =
            numUniqueTreesRecursiveDPMemoization(i - 1);
        long long nRightSubtrees =
            numUniqueTreesRecursiveDPMemoization(numNodes - i);
        long long numTreesRootedAtI = nLeftSubtrees * nRightSubtrees;
        // Update total number of unique trees with the number of trees
        // which can be constructed rooted at 'i'
        totalTrees += numTreesRootedAtI;
    }

    // Update the DP memoization table so that the subproblem need not
    // be solved again
    dpMemoizationTbl[numNodes] = totalTrees;
    return dpMemoizationTbl[numNodes];
}
