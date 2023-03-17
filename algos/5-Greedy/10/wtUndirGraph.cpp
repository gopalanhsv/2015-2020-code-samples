// System headers
#include <vector>
#include <list>
#include <stdexcept>
#include <queue>
#include <iostream>
#include <limits>

// Local includes
#include "wtUndirGraph.h"
#include "disjointSets.h"

// Using declarations
using std::vector;
using std::list;
using std::priority_queue;
using std::domain_error;
using std::runtime_error;
using std::cout;
using std::endl;
using std::greater;
using std::make_pair;
using std::numeric_limits;

// Statics, typedefs, globals

const list<intPairT>&
WtdUndirGraph::getNeighbours(int v) const {
    if (_nVertices <= 0 || _nEdges <= 0 || _edges.empty()) {
        throw runtime_error("Error! The graph has either no edges/vertices");
    }
    if (v < 0 || v >= _nVertices) {
        throw domain_error("Error! Invalid vertex!");
    }

    return _adjList[v];
}

// Add an edge between vertices [u, v] with weight cost
void
WtdUndirGraph::addEdge(int u, int v, int cost) {
    if (u < 0 || v < 0 || v >= _nVertices || v >= _nVertices) {
        throw domain_error("Error! Invalid src/dst vertex!");
    }
    if (u < 0 || u >= _nVertices) {
        throw domain_error("Error! Invalid src vertex!");
    }
    if (v < 0 || v >= _nVertices) {
        throw domain_error("Error! Invalid dst vertex!");
    }

    // Create a new edge and add it the graph
    edgeT e(u, v, cost);
    _edges.push_back(e);
    // Add the vertices [u, v] to the neighbour lists of both
    _adjList[u].push_back(make_pair(v, cost));
    _adjList[v].push_back(make_pair(u, cost));
}

// Remove an edge between vertices [u, v] 
void
WtdUndirGraph::removeEdge(int u, int v) {
    if (u < 0 || v < 0 || v >= _nVertices || v >= _nVertices) {
        throw domain_error("Error! Invalid src/dst vertex!");
    }
    if (u < 0 || u >= _nVertices) {
        throw domain_error("Error! Invalid src vertex!");
    }
    if (v < 0 || v >= _nVertices) {
        throw domain_error("Error! Invalid dst vertex!");
    }

    // Remove the edge [u, v] from the edges vector
    vector<edgeT>::iterator edgeIter = _edges.begin();
    vector<edgeT>::iterator endEdgeIter = _edges.end();
    for (; edgeIter != endEdgeIter;) {
        edgeT& e = *edgeIter;
        if (e._s == u && e._d == v || e._s == v && e._d == u) {
            edgeIter = _edges.erase(edgeIter);
        } else {
            ++edgeIter;
        }
    }

    // Remove the edge [u, v] from the vertex u neighbour list
    list<intPairT>& neigbourListOfU = _adjList[u];
    list<intPairT>::iterator it = neigbourListOfU.begin();
    list<intPairT>::iterator eIt = neigbourListOfU.end();
    for (; it != eIt;) {
        if (it->first == v) {
            it = neigbourListOfU.erase(it);
        } else {
            ++it;
        }
    }

    // Remove the edge [u, v] from the vertex v neighbour list
    list<intPairT>& neigbourListOfV = _adjList[v];
    it = neigbourListOfV.begin();
    eIt = neigbourListOfV.end();
    for (; it != eIt;) {
        if (it->first == u) {
            it = neigbourListOfV.erase(it);
        } else {
            ++it;
        }
    }
}

void
WtdUndirGraph::displayMST(const list<edgeT>& mstEdges) {
    if (_nVertices <= 0 || _nEdges <= 0 || _edges.empty()) {
        throw runtime_error("Error! The graph has no edges/vertices");
    }

    if (mstEdges.empty()) {
        throw domain_error("Error! No MST edges!");
    }

    int mstWt = 0;
    list<edgeT>::const_iterator it = mstEdges.begin();
    list<edgeT>::const_iterator eIt = mstEdges.end();
    for (; it != eIt; ++it) {
        const edgeT& mstEdge = *it;
        cout << mstEdge._s << " -- " << mstEdge._d << endl;
        mstWt += mstEdge._cost;
    }

    cout << "MST weight = " << mstWt << endl;
}

list<edgeT>
WtdUndirGraph::computeKruskalMST() {
    if (_nVertices <= 0 || _nEdges <= 0 || _edges.empty()) {
        throw runtime_error("Error! The graph has no edges/vertices");
    }

    // Construct a forest where each vertex is in its
    // own disjoint set
    DisjointSets forest;
    forest.makeSet(getNumVertices());
    // Priority queue ordering the edges in the order
    // of increasing cost/weight from queue front to back
    priority_queue<edgeT, vector<edgeT>, greater<edgeT> >
        edgePQ(_edges.begin(), _edges.end());

    // MST edges list
    list<edgeT> mstEdges;
    // Process all edges in the order of decreasing wts/cost
    while (!edgePQ.empty()) {
        // Get the minimum weight edge (PQ top)
        const edgeT e = edgePQ.top();
        edgePQ.pop();

        // If the vertices of minimum wt edge are in disjoint sets,
        // merge the vertices into the same set (this edge gets added
        // to MST)
        int u = e._s;
        int v = e._d;
        if (forest.findSet(u) != forest.findSet(v)) {
            forest.setUnion(u, v);
            mstEdges.push_back(e);
        }
    }

    return mstEdges;
}

// For Prim MST algo
// Each vertex is associated with a label
typedef struct LabelT {
    int _v; // Vertex
    int _d; // Min Distance to vertex from parent vertex
    int _parent; // Parent vertex
    LabelT(int v, int d, int p) {
        _v = v;
        _d = d;
        _parent = p;
    }
} LabelT;

// For ordering vertex Labels in a Priority Queue in the
// order of increasing distances
namespace std {
    template<>
    struct greater<LabelT> {
        bool operator() (const LabelT& l1, const LabelT& l2) const {
            return l1._d > l2._d;
        }
    };
};

list<edgeT>
WtdUndirGraph::computePrimMST() {
    if (_nVertices <= 0 || _nEdges <= 0 || _edges.empty()) {
        throw runtime_error("Error! The graph has no edges/vertices");
    }

    // Associate a label with each vertex
    vector<LabelT> labels; //(getNumVertices());
    // Each vertex label initialized with distance = +infinity, parent as -1;
    for (int v = 0; v != _nVertices; ++v) {
        LabelT label(v, numeric_limits<int>::max(), -1);
        labels.push_back(label);
    }

    // Start with vertex 0. Set its label distance as 0
    // (it will be the MST root)
    labels[0]._d = 0;

    list<edgeT> mstEdges;
    // Tracks which vertices are in MST
    vector<bool> vertexInMst(_nVertices, false);
    // Priority queue to determine the smallest wt edge connecting the
    // MST vertices partition to non-MST vertices partition
    priority_queue<LabelT, vector<LabelT>, greater<LabelT> >
        pQ(labels.begin(), labels.end());
    // Iterate over all vertices in the order of increasing label distances
    while (!pQ.empty()) {
        // Pop off the vertex at PQ top
        const LabelT topLabel = pQ.top();
        pQ.pop();

        // Add popped off vertex to MST (since its the non MST-vertex be
        // reached by an edge with least cost from an MST vertex)
        int v = topLabel._v;
        if (vertexInMst[v]) {
            // Skip if vertex already in MST (duplication can happen
            // in case of label distance updation to a vertex already
            // in PQ)
            continue;
        }
        vertexInMst[v] = true;
        if (topLabel._parent != -1) {
            mstEdges.push_back(
                edgeT(topLabel._parent, topLabel._v, topLabel._d));
        }

        // Examine all neighbours of the newly added vertex which are not in
        // the MST. Non MST neighbours are added to the label priority queue.
        // The label distances along with parent of all non MST neigbours are
        // also updated if the neighbours can be reached from currently popped
        // vertex 'v' with lower distance/cost
        const list<intPairT>& neighbours = getNeighbours(v);
        list<intPairT>::const_iterator it = neighbours.begin();
        list<intPairT>::const_iterator eIt = neighbours.end();
        for (; it != eIt; ++it) {
            const int nv = it->first; // Neighbour vertex id
            const int ec = it->second; // Edge to 'nv' via vertex 'v'
            if (!vertexInMst[nv]) {
                // Non MST Neighbour vertex can be reached from current newly
                // added vertex via an edge with lesser cost
                if (ec < labels[nv]._d) {
                    // Update the neigbour vertex labels
                    labels[nv]._d = ec;
                    labels[nv]._parent = v;
                    // Add the updated label for vertex to PQ. This may cause
                    // PQ to have multiple label entries for same vertex; but
                    // always least cost(label distance) is chosen. Can skip
                    // other vertex labels by checking for MST presence prior
                    // to de-popped label processing
                    LabelT label(nv, ec, v);
                    pQ.push(label);
                }
            }
        }
    }

    return mstEdges;
}

// Dijkstra algo
// Type for storing vertex, shortest distance tuples
typedef struct vtxDistT {
    int _v; // Vertex id
    int _d; // Current shortest distance from source
    // Constructor
    vtxDistT(int v, int d) : _v(v), _d(d) {}
private:
    vtxDistT() {}
} vtxDistT;

// Comparison class for ordering vtxDistT struct in a priority
// queue on the basis of distances from a source vertex
namespace std {
    template<>
    struct greater<vtxDistT> {
        bool operator() (const vtxDistT& lhs, const vtxDistT rhs) const {
            return lhs._d > rhs._d;
        };
    };
};

vector<int>
WtdUndirGraph::dijkstraShortestPath(int src) {
    if (_nVertices <= 1 || _nEdges <= 0 || _edges.empty()) {
        throw runtime_error("Error! Graph has nil vertices/edges!");
    }

    // Maintains the currently known shortest distance for
    // each vertex (initialized to +infinity)
    vector<int> shortestDistVec(getNumVertices(),
        std::numeric_limits<int>::max());

    // Priority queue of [vertex id, shortest distance from reference vertex] tuples
    // ordered in ascending order of distances. First/top element contains vertex
    // at shortest distance from source vertex
    priority_queue<vtxDistT, vector<vtxDistT>, greater<vtxDistT> > pQ;

    // Start with source vertex as vertex 0 and find the shortest distance
    // to other vertices
    // Add vertex 'src' to PQ and set its distance as 0
    shortestDistVec[src] = 0;
    pQ.push(vtxDistT(src, shortestDistVec[src]));
    
    // Examine all vertices and compute the shortest distance from
    // source vertex 0
    while (!pQ.empty()) {
        // Vertex identified by top/front element in PQ would
        // be at the shortest distance. Pop it off from PQ
        const vtxDistT topVtxDst = pQ.top();
        pQ.pop();
        // Get the vertex id, distance which are at shortest
        // distance.
        int v = topVtxDst._v;
        int dv = topVtxDst._d;
        // Skip processing popped off vertex if its
        // already at shortest distance
        if (shortestDistVec[v] < dv) {
            continue;
        }
        // Update the shortest distance for popped off vertex
        shortestDistVec[v] = dv;
        // Examine all neigbours of popped off vertex 'v'.
        const list<intPairT>& neigbours = getNeighbours(v);
        list<intPairT>::const_iterator it = neigbours.begin();
        list<intPairT>::const_iterator eIt = neigbours.end();
        for (; it != eIt; ++it) {
            // If any neighbour 'nv' can be reached via vertex 'v'
            // (using edge u-v) from source with a shorter path, add
            // the neighbour 'nv' to the PQ with updated shortest distance
            int nv = it->first; // Neighbour vertex id
            int ec = it->second; // Edge cost to neigbour from v
            if (dv + ec < shortestDistVec[nv]) {
                vtxDistT neighVtxDist(nv, dv + ec);
                pQ.push(neighVtxDist);
            }
        }
    }

    return shortestDistVec;
}

void
WtdUndirGraph::displayVertexShortestDistance(const std::vector<int>& dV) {
    if (dV.empty()) {
        throw domain_error("Error! Empty distance vector!");
    }

    cout << 0 << " --> " << dV[0];
    for (vector<int>::size_type i = 1; i != dV.size(); ++i) {
        cout << ", " << i << " --> " << dV[i];
    }
    cout << endl;
}
