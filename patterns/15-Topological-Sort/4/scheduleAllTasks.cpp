// System includes
#include <vector>
#include <queue>
#include <unordered_map>
#include <list>
#include <stdexcept>
#include <cassert>
#include <utility>
#include <algorithm>

// Local includes
#include "scheduleAllTasks.h"

// Using declarations
using std::vector;
using std::queue;
using std::pair;
using std::list;
using std::unordered_map;
using std::domain_error;
using std::find;

// Statics, typedefs, globals

class Graph {
public:
    // Constructor
    Graph(unsigned nv) : _nv(nv) {
        for (unsigned v = 0; v != _nv; ++v) {
            _inDegreeTbl[v] = 0;
            _adjListTbl[v] = list<unsigned>();
        }
    }

    // Returns the number of graph vertices
    inline unsigned nVertices() const { return _nv; }

    // Returns true if given vertex has no incoming edges, false otherwise
    inline bool
    isSourceVertex(unsigned v) {
        assert(v < _nv);
        return _inDegreeTbl[v] == 0;
    }

    // Returns list of neighbour vertices
    list<unsigned>&
    neighbourVertices(unsigned v) {
        assert(v < _nv);
        return _adjListTbl[v];
    }

    // Returns all source vertices
    vector<unsigned>
    sourceVertices() {
        vector<unsigned> sV;
        for (auto entry : _inDegreeTbl) {
            if (entry.second == 0) {
                sV.push_back(entry.first);
            }
        }
        return sV;
    }

    // Add given edge to graph
    void
    addEdge(unsigned u, unsigned v) {
        assert(u < _nv);
        assert(v < _nv);
        // Add child/destination vertex to list associated with parent/source
        _adjListTbl[u].push_back(v);
        // Update incoming edges at destination/child
        _inDegreeTbl[v]++;
    }

    // Add given edge to graph -- adjacency list not updated
    void
    addEdgeVirtual(unsigned u, unsigned v) {
        assert(u < _nv);
        assert(v < _nv);
        // Update incoming edges at destination/child
        _inDegreeTbl[v] += 1;
    }

    // Remove given edge from graph -- adjacency list not updated
    void
    removeEdgeVirtual(unsigned u, unsigned v) {
        assert(u < _nv);
        assert(v < _nv);
        // Update incoming edges at destination/child
        _inDegreeTbl[v] -= 1;
    }

    void
    allTopoSortsRecursive(vector<bool>& visited,
        vector<unsigned>& currTopoSortedV,
        vector<vector<unsigned> >& allTopoSorts) {

        bool allVerticesAreSourcesAndVisited = true;

        // Iterate over all vertices
        for (unsigned v = 0; v != nVertices(); ++v) {

            // If a vertex is a source vertex and not yet visited
            if (isSourceVertex(v) && !visited[v]) {

                // Remove the source vertex from graph
                for (auto child : neighbourVertices(v)) {
                    // Iterate over all neighbours of source and remove the
                    // edges connecting source/parent to child/neighbour
                    removeEdgeVirtual(v, child);
                }

                // Mark vertex as visited and add it to topological sort
                visited[v] = true;
                currTopoSortedV.push_back(v);

                // Recursively determine all topological sort paths with
                // this vertex removed
                allTopoSortsRecursive(visited, currTopoSortedV, allTopoSorts);

                // Backtrack by adding source vertex back to graph and
                // mark it as unvisited,remove it from topological sort
                // paths
                visited[v] = false;
                currTopoSortedV.pop_back();
                for (auto child : neighbourVertices(v)) {
                    // Iterate over all neighbours of source and add back
                    // edges connecting source/parent to child/neighbour
                    addEdgeVirtual(v, child);
                }

                allVerticesAreSourcesAndVisited = false;
            }
        }

        // If all sources have been examined and the current topo sort path
        // contains all vertices of graph, it is a candidate for sort path
        // commencing from first vertex in current topo sort path
        if (allVerticesAreSourcesAndVisited && 
            (currTopoSortedV.size() >= nVertices())) {
            allTopoSorts.push_back(currTopoSortedV);
        }
    }

    vector<vector<unsigned> >
    allTopoSorts() {

        vector<bool> visited(nVertices(), false);
        // Running vector of vertices seen per topo sort
        vector<unsigned> topoSortV;
        // To hold lists of all topo sort paths computed
        vector<vector<unsigned> > allTopoSortsV;
        allTopoSortsRecursive(visited, topoSortV, allTopoSortsV);

        return allTopoSortsV;
    }

private:
    // Data members
    // Num graph vertices
    unsigned _nv;
    // Adjacency list table associating list of child/destination
    // vertices with respective source/parent vertex
    unordered_map<unsigned, list<unsigned> > _adjListTbl;
    // Hash table maintaining number of incoming edges
    // associated with each vertex
    unordered_map<unsigned, unsigned> _inDegreeTbl;
};

vector<vector<unsigned> >
TaskScheduler::scheduleAllTasks(unsigned nTasks,
    const vector<pair<unsigned, unsigned> >& prerequisitesV) {

    if (0 == nTasks || prerequisitesV.empty()) {
        throw domain_error("Error! Invalid num tasks/input prerequisites!");
    }

    // Create and initialize an undirected graph with tasks as vertices and
    // prerequisites as edges
    Graph taskGraph(nTasks);
    typedef vector<pair<unsigned, unsigned> >::size_type vecSzT;
    for (auto p : prerequisitesV) {
        taskGraph.addEdge(p.first, p.second);
    }

    // All topological sorts commencing from all source vertices
    // give all possible task schedules
    return taskGraph.allTopoSorts();
}
