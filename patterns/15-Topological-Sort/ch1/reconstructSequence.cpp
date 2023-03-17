// System headers
#include <vector>
#include <queue>
#include <unordered_map>
#include <list>
#include <stdexcept>

// Local includes
#include "reconstructSequence.h"

// Using declarations
using std::vector;
using std::unordered_map;
using std::queue;
using std::list;
using std::domain_error;

// Statics, typedefs, locals

class Graph {
public:
    Graph() {}

    // Adds given vertex to graph
    void
    addVertex(int v) {
        _adjListTbl[v] = list<int>();
        _inDegreeTbl[v] = 0;
    }

    // Adds given directed edge u->v to graph
    void
    addEdge(int u, int v) {
        _adjListTbl[u].push_back(v);
        _inDegreeTbl[v]++;
    }

    // Removes given directed edge u->v from graph
    void
    removeEdgeVirtual(int u, int v) {
        _inDegreeTbl[v]--;
    }

    // Returns true if given vertex is a source vertex
    // (no incoming edges), false otherwise
    inline bool
    isSourceVertex(int v) {
        return _inDegreeTbl[v] == 0;
    }

    // Returns source vertices (those with no incoming
    // edges) in the graph currently
    vector<int>
    sourceVertices() const {
        vector<int> sV;
        for (auto entry : _inDegreeTbl) {
            if (entry.second == 0) {
                sV.push_back(entry.first);
            }
        }
        return sV;
    }

    // Returns list of neighbour vertices of a given vertex
    list<int>&
    neighbourVertices(int v) {
        return _adjListTbl[v];
    }

    // Returns true if the given topological ordering of vertices is
    // the only single one possible with the graph vertices
    bool
    isTopologicalOrderingUniqueAndSingle(const vector<int>& topoOrder) {

        // Add source vertices to BFS Q to commence topological sort
        queue<int> sourceQ;
        for (auto v : sourceVertices()) {
            sourceQ.push(v);
        }

        // Topological sort of graph as per source vertices 
        // processed till this point
        vector<int> topoSortV;
        // Iterate till all possible source vertices are examined
        while (!sourceQ.empty()) {
            // Source vertices Q has more than one element, implies
            // multiple topological paths possible from this point
            // => no unique topological sort
            if (sourceQ.size() > 1) {
                return false;
            }

            int s = sourceQ.front();
            // Mismatch between source vertex to be dequeued and given
            // topological ordering implies that given ordering is incorrect 
            if (s != topoOrder[topoSortV.size()]) {
                return false;
            }

            // Deque the vertex at sourceQ front and add it to current
            // running topological sort
            sourceQ.pop();
            topoSortV.push_back(s);

            // Remove dequed source vertex 's' from graph (by removing all
            // edges (s, d) to neigbors 'd' of source vertex 's'
            for (auto d : neighbourVertices(s)) {
                removeEdgeVirtual(s, d);
                // Removal of edge results neighbor becoming a source,
                // add to source Q
                if (isSourceVertex(d)) {
                    sourceQ.push(d);
                }
            }
        }

        if (topoSortV.size() != topoOrder.size()) {
            return false;
        }

        return true;
    }

private:
    // Data members
    // Adjacency list mapping each integer to the list of integers it is
    // associated with/comes prior to in subsequences
    unordered_map<int, list<int> > _adjListTbl;
    // Table tracking number of incoming edges at each vertex
    unordered_map<int, unsigned> _inDegreeTbl;
    
};

bool
Sequence::isSoleSequenceOfSubsequences(const vector<int>& sequence,
    const vector<vector<int> >& subsequenceV) {
    if (sequence.empty() || subsequenceV.empty()) {
        throw domain_error("Error! Empty sequence/subsequences!");
    }

    // Model all the elements in the subsequences are graph vertices and
    // graph directed edges would represent the ordering amongst the
    // subsequence elements
    Graph subSeqGraph;

    // Iterate over all elements in all subsequences and add them as
    // graph vertices
    for (auto subSeq : subsequenceV) {
        if (subSeq.size() < 2) {
            throw domain_error("Error! Subsequence has less than 2 elems!");
        }
        for (auto elem : subSeq) {
            subSeqGraph.addVertex(elem);
        }
    }

    // Examine each subsequence 
    for (auto subSeq : subsequenceV) {
        // Examine adjacent subsequence elements and add them as directed
        // edges to subsequence graph with edge going from a subsequence
        // element to next subsequence element
        typedef vector<int>::size_type vecSzT;
        for (vecSzT i = 1; i != subSeq.size(); ++i) {
            int s = subSeq[i - 1];
            int d = subSeq[i];
            subSeqGraph.addEdge(s, d);
        }
    }

    // Check topological sort ordering of subsequence graph is identical
    // with given sequence
    return subSeqGraph.isTopologicalOrderingUniqueAndSingle(sequence);
}
