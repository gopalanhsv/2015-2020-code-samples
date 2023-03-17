// System headers
#include <vector>
#include <list>
#include <queue>
#include <stdexcept>

// Local includes
#include "permutations.h"

// Using declarations
using std::vector;
using std::list;
using std::queue;
using std::domain_error;

// Statics, typedefs, globals

vector<vector<int> >
Numbers::generateAllPermutations(const vector<int>& v) {
    if (v.empty()) {
        throw domain_error("Error! Empty input vector!");
    }

    // Vector of all permutations
    vector<vector<int> > permutationSetsV;

    // Queue holding permutation sets of elements examined/processed
    // When all input elements have been examined, this queue will end
    // up holding all the permutation sets
    queue<list<int> > permutationSetsQ;
    // Initialize with empty set
    permutationSetsQ.push({});

    // Iterate sequentially over every element of input vector
    // of numbers whose permutations subsets are to be determined
    for (auto n : v) {

        // All Permutation sets of elements of input vector iterated/
        // processed uptill previous iteration are already determined.
        // Combine the element 'n' of input vector seen in this iteration
        // with the previously determined permutation sets to form the
        // permutation sets of all elements seen till now

        // Add the element being processed in this iteration to each of
        // the permutation sets constructed uptill the previous
        // iteration/input element processed at every insertion point in
        // each of the permutation sets
        typedef queue<list<int> >::size_type qSzT;
        qSzT permutationSetsQSz = permutationSetsQ.size();
        // Iterate over all permutations sets constructed in previous iteration
        // to form new permutation sets with new element
        for (qSzT i = 0; i != permutationSetsQSz; ++i) {
            // Dequeue the permutation set determined in previous iteration
            // from permutations sets Q
            list<int> oldPermSet = permutationSetsQ.front();
            permutationSetsQ.pop();
            // Combine dequeued old permutation set with new element at every
            // insertion position to form new permutation sets
            list<int>::iterator it = oldPermSet.begin();
            list<int>::iterator eIt = oldPermSet.end();
            unsigned int insertionPos = 0;
            // Iteration over every element/location in the old set
            while (it != eIt) {
                // Create a copy of the old dequeued permutation set
                list<int> newPermSet(oldPermSet);
                // Determine location in the new permutation set where to
                // insert new element from input vector (it should be same as 
                // the corresponding element being iterated over in the old
                // permutation set currently)
                list<int>::iterator insertPosIter = newPermSet.begin();
                for (unsigned int i = 0; i != insertionPos; ++i) {
                    ++insertPosIter;
                }
                // Insert the new element from input vector to
                // form new permutation
                newPermSet.insert(insertPosIter, n);
                // Advance to the next location in old dequeued permutation set
                ++it, ++insertionPos;
                // Append new permutation set to end of permutation sets Q for
                // processing next element from input vector. If all elements
                // have been seen, add new permutation to result vector of
                // permutations
                if (newPermSet.size() == v.size()) {
                    permutationSetsV.push_back({newPermSet.begin(),
                        newPermSet.end()});
                } else {
                    permutationSetsQ.push(newPermSet);
                }
            }
            // Construct the last permutation for dequeued permutation set by
            // inserting new element from input vector at end. Append to
            // permutation sets Q or result vector based on whether all input
            // elements have been seen or not
            list<int> newPermSet(oldPermSet);
            newPermSet.push_back(n);
            if (newPermSet.size() == v.size()) {
                permutationSetsV.push_back({newPermSet.begin(),
                    newPermSet.end()});
            } else {
                permutationSetsQ.push(newPermSet);
            }
        }
    }

    return permutationSetsV;
}

vector<vector<int> >
Numbers::generateAllPermutationsRecursive(const vector<int>& v) {
    if (v.empty()) {
        throw domain_error("Error! Empty input vector!");
    }

    vector<vector<int> > finalPermutationsV;
    // Tracks index of input vector element which is added
    // to permutation generated in previous recursion steps
    vector<int>::size_type inputNumVecIdx = 0;
    vector<int> prevPermutation;
    generateAllPermutationsRecursive(v, inputNumVecIdx,
        prevPermutation, finalPermutationsV);

    return finalPermutationsV;
}

void
Numbers::generateAllPermutationsRecursive(const vector<int>& v,
    vector<int>::size_type inputNumVecIdx,
    vector<int>& prevPermutation,
    vector<vector<int> >& finalPermutationsV) {

    // If all input vector elements have been processed, then previous
    // generated permutation would be one containing all input elements
    // and is a candidate for inclusion into final permutations vector
    if (inputNumVecIdx == v.size()) {
        finalPermutationsV.push_back(prevPermutation);
        return;
    }

    // All input vector elements yet to be processed. Process the
    // current input vector element by combining it with permutation
    // generated in previous step to generate permutations containing
    // previous permutation and the new element inserted at all locations
    // of previous permutation
    vector<int>::size_type prevPermSz = prevPermutation.size();
    // Iterate over all possible insertion positions of previous
    // permutation
    for (vector<int>::size_type insertPos = 0;
        insertPos <= prevPermSz; ++insertPos) {
        // Generate a new permutation by inserting the new
        // vector element at insertion position of previous permutation
        vector<int> newPermutation(prevPermutation);
        newPermutation.insert(
            newPermutation.begin() + insertPos, v[inputNumVecIdx]);
        // Generate all permutations possible of new permutation
        // with remainder of elements in the input vector recursively
        generateAllPermutationsRecursive(v, inputNumVecIdx + 1,
            newPermutation, finalPermutationsV);
    }
}
