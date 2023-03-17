// System headers
#include <list>
#include <vector>
#include <stdexcept>
#include <iostream>
#include <utility>

// Local includes
#include "undirectedGraph.h"

// Using declarations
using std::vector;
using std::list;
using std::runtime_error;
using std::domain_error;
using std::make_pair;
using std::pair;
using std::cout;
using std::endl;

// Statics, typedefs, globals

// Add an edge between vertices u & v
void
UndirectedGraph::addEdge(int u, int v) {
    if (u < 0 || v < 0 || u > _nVertices - 1 || v > _nVertices - 1) {
        throw domain_error("Error! Vertex ids not in permissible range!");
    }
    // Add the edge [u, v] to both vertex u & v in adjacency list
    _adjacencyList[u].push_back(v);
    _adjacencyList[v].push_back(u);
}

// Remove edge between vertices u & v
void
UndirectedGraph::removeEdge(int u, int v) {
    if (u < 0 || v < 0 || u > _nVertices - 1 || v > _nVertices - 1) {
        throw domain_error("Error! Vertex ids not in permissible range!");
    }
    // Remove the edge [u, v] from both vertex u & v in adjacency list
    _adjacencyList[u].push_back(v);
    list<int>& neighboursOfU = _adjacencyList[u];
    list<int>::iterator it = neighboursOfU.begin();
    list<int>::iterator endIt = neighboursOfU.end();
    for (; it != endIt;) {
        if (*it == v) {
            it = neighboursOfU.erase(it);
        } else {
            ++it;
        }
    }
    list<int>& neighboursOfV = _adjacencyList[v];
    it = neighboursOfV.begin();
    endIt = neighboursOfV.end();
    for (; it != endIt;) {
        if (*it == u) {
            it = neighboursOfV.erase(it);
        } else {
            ++it;
        }
    }
}

void
printVertexColors(const vector<pair<int, int> >& vertexColorPairVec) {
    typedef vector<pair<int, int> >::size_type vecSzT;
    for (vecSzT i = 0; i != vertexColorPairVec.size(); ++i) {
        cout << "Vertex " << vertexColorPairVec[i].first << " ---> "
            << "Color " << vertexColorPairVec[i].second << endl;
    }
}

vector<pair<int, int> >
UndirectedGraph::greedyColoring() {
    if (0 == _nVertices || _adjacencyList.empty()) {
        throw runtime_error("Error! Graph has no edges and/or vertices!");
    }

    // Initialize all vertices to be uncolored (i.e -1)
    const int VertexUncoloredT = -1;
    vector<int> vertexColor(_nVertices, VertexUncoloredT);

    // Iterate over all the vertices of the graph
    for (int v = 0; v != getNumVertices(); ++v) {
        // Skip greedy coloring if vertex is already colored
        if (vertexColor[v] != VertexUncoloredT) {
            continue;
        }

        // Color the vertex using the greedy approach by employing
        // first available color (determined by scanning its neighbour
        // colors)

        // Initialize all colors as available (max number of colors would be
        // the number of graph vertices)
        vector<int> colorAvailable(_nVertices, true);
        // Now mark those colors as unavailble which are already used
        // by neighbours of current vertex 'v'
        const list<int>& neighbourVertices = getVertexNeighbours(v);
        list<int>::const_iterator it = neighbourVertices.begin();
        list<int>::const_iterator endIt = neighbourVertices.end();
        for (;it != endIt; ++it) {
            const int nv = *it;
            if (vertexColor[nv] != VertexUncoloredT) {
                colorAvailable[vertexColor[nv]] = false;
            }
        }

        // Iterate through the freelist of colors to determine the first
        // available color which can be used. Color the current vertex 'v'
        // with this color (greedy approach)
        int c = 0;
        for (; c != colorAvailable.size(); ++c) {
            if (colorAvailable[c]) {
                break;
            }
        }
        vertexColor[v] = c;
    } // end looping over all vertices

    vector<pair<int, int> > vertexColorPairVec;
    for (int v = 0; v != getNumVertices(); ++v) {
        vertexColorPairVec.push_back(make_pair(v, vertexColor[v]));
    }

    return vertexColorPairVec;
}
