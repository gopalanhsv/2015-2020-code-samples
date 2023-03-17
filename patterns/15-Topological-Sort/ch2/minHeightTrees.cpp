// System headers
#include <vector>
#include <unordered_map>
#include <queue>
#include <stdexcept>
#include <cassert>

// Local includes
#include "minHeightTrees.h"

// Using declarations
using std::vector;
using std::unordered_map;
using std::queue;
using std::domain_error;

// Statics, typedefs, globals

// Constructor
UndirectedGraph::UndirectedGraph(unsigned nv) : _nv(nv) {
    for (unsigned v = 0; v != _nv; ++v) {
        addVertex(v);
    }
}

// Adds given vertex to the graph
void
UndirectedGraph::addVertex(unsigned v) {
    assert(v < _nv);
    _adjListTbl[v] = vector<unsigned>();
    _numEdgesTbl[v] = 0;
}

// Adds given edge to the graph
void
UndirectedGraph::addEdge(unsigned u, unsigned v) {
    assert(u < _nv);
    assert(v < _nv);
    // Update adjacency list at vertices terminating the edge
    _adjListTbl[v].push_back(u);
    _adjListTbl[u].push_back(v);
    // Update table tracking number of edges at both vertices
    // terminating the given edge
    _numEdgesTbl[v]++;
    _numEdgesTbl[u]++;
}

// Returns list of neighbour vertices to given vertex
vector<unsigned>&
UndirectedGraph::neighbourVertices(unsigned v) {
    return _adjListTbl[v];
}

// Removes given edge from the graph
void
UndirectedGraph::removeEdgeVirtual(unsigned u, unsigned v) {
    // Update table tracking number of edges at both vertices
    // terminating the given edge
    _numEdgesTbl[v]--;
    _numEdgesTbl[u]--;
}

// Removes given vertex from the graph
void
UndirectedGraph::removeVertexVirtual(unsigned v) {
    _nv--;
    _numEdgesTbl.erase(v);
    _adjListTbl[v].clear();
    _adjListTbl.erase(v);
}

// Determines the vertices of the graph which form min height trees
vector<unsigned>
UndirectedGraph::computeMinHeightTreeRoots() {
    // BFS Q of currently running leaf vertices
    queue<unsigned> leafVertexQ;

    // Add all leaf vertices of graph to the leaf vertex Q
    for (unsigned v = 0; v != numVertices(); ++v) {
        if (isLeaf(v)) {
            leafVertexQ.push(v);
        }
    }

    // Keep on removing leaf vertices from the graph till
    // we end up with 1 or 2 graph vertices at the end
    while (numVertices() > 2) {
        // Remove all leaf vertices currently at this level
        typedef queue<unsigned>::size_type qSzT;
        qSzT leafQSz = leafVertexQ.size();
        for (qSzT i = 0; i != leafQSz; ++i) {
            // Dequeue leaf vertex at front of BFS Q
            unsigned lv = leafVertexQ.front();
            leafVertexQ.pop();

            // Remove dequeued leaf vertex from the graph
            // Remove all edges from the leaf vertex to its neighbours
            for (unsigned nv : neighbourVertices(lv)) {
                removeEdgeVirtual(lv, nv);
                // If removal of edge between leaf vertex and its neighbour
                // makes the neighbour a leaf, add the neighbour to queue
                // of leaf vertices
                if (isLeaf(nv)) {
                    leafVertexQ.push(nv);
                }
            }
            // Remove dequeued leaf vertex
            removeVertexVirtual(lv);
        }
    }

    // Vector holding minHtTreeRoots
    vector<unsigned> minHtTreeRootV;
    // At the end we are left with a max of 2 vertices (maybe 1).
    // These vertices will form the root of min height trees
    while (!leafVertexQ.empty()) {
        minHtTreeRootV.push_back(leafVertexQ.front());
        leafVertexQ.pop();
    }

    return minHtTreeRootV;
}

