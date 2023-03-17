// System headers
#include <vector>
#include <queue>
#include <unordered_map>
#include <utility>
#include <stdexcept>

// Local includes
#include "topoSort.h"

// Using declarations
using std::vector;
using std::queue;
using std::unordered_map;
using std::pair;
using std::domain_error;

// Statics, typedefs, globals

class Graph {
public:
    // Constructor
    Graph(unsigned n) : _nv(n) {
        init();
    }

    void
    addEdge(unsigned src, unsigned dst) {
        if (src >= _nv || dst >= _nv) {
            throw domain_error("Error! Invalid vertex id in addEdge!");
        }
        // Add the destination/child vertex to src/parent vertex in 
        // adjacency list
        _adjList[src].push_back(dst);
        // Update indegree of child/destination vertex
        _inDegreeTbl[dst]++;
    }

    void
    removeEdge(unsigned src, unsigned dst) {
        if (src >= _nv || dst >= _nv) {
            throw domain_error("Error! Invalid vertex id in removeEdge!");
        }
        // Not updating the adjacency list, as it involves perf penalty
        // of updating vector mapped to src vertex and is not reqd for algo
        // Update indegree of child/destination vertex
        _inDegreeTbl[dst]--;
    }

    // Accessors
    unsigned nVertices() const {
        return _nv;
    }

    bool isSourceNode(unsigned v) {
        return _inDegreeTbl[v] == 0;
    }

    const vector<unsigned>& childVertices(unsigned v) {
        if (v >= _nv) {
            throw domain_error("Error! Invalid vertex id in childVertices!");
        }

        return _adjList[v];
    }

private:

    void
    init() {
        for (unsigned v = 0; v != _nv; ++v) {
            _inDegreeTbl[v] = 0;
        }
    }

    // Data members
    // Num vertices
    unsigned _nv;
    // Adjacency list i.e hash table mapping each vertex id => list of
    // child vertices it is connected to
    unordered_map<unsigned, vector<unsigned> > _adjList;
    // Hash table mapping each vertex id => in degree i.e. num incoming edges
    unordered_map<unsigned, unsigned> _inDegreeTbl;
};

vector<unsigned>
TopoSort::sort(unsigned nVertices,
    const vector<pair<unsigned, unsigned> >& edges) {
    if (!nVertices) {
        throw domain_error("Error! Invalid num vertices!");
    }
    if (edges.empty()) {
        throw domain_error("Error! Nil edges!");
    }

    // Initialize the graph
    Graph g(nVertices);

    // Create the graph by adding all edges
    for (auto e : edges) {
        g.addEdge(e.first, e.second);
    }

    // Add all source vertices to BFS queue
    queue<unsigned> sourceQ;
    for (unsigned v = 0; v != nVertices; ++v) {
        if (g.isSourceNode(v)) {
            sourceQ.push(v);
        }
    }

    // Topological sorted vertices
    vector<unsigned> sortedV;
    // Iterate over all source vertices in BFS Q
    while (!sourceQ.empty()) {

        // Pop off the vertex at Q front
        unsigned s = sourceQ.front();
        sourceQ.pop();

        // Add this source vertex to list of topologically sorted vertices
        sortedV.push_back(s);
        // Iterate over all edges commencing from this source/parent vertex
        // Done by using the child vertices attached to source
        for (auto d : g.childVertices(s)) {
            // Remove edge commencing from source to given child
            g.removeEdge(s, d);
            // If child node attached to parent/source node has become
            // a source node after edge removal, add to BFS Q
            if (g.isSourceNode(d)) {
                sourceQ.push(d);
            }
        }
    }

    // If topological sort does not yield all vertices, it indicates
    // presence of cycle in graph
    if (sortedV.size() != nVertices) {
        throw domain_error("Error! Graph is not a DAG!");
    }

    return sortedV;
}
