// System headers
#include <vector>
#include <unordered_map>
#include <queue>
#include <list>
#include <utility>
#include <stdexcept>

// Local includes
#include "scheduleTasks.h"

// Using declarations
using std::vector;
using std::unordered_map;
using std::list;
using std::queue;
using std::pair;
using std::domain_error;

// Statics, typedefs, globals

class Graph {
public:
    // Constructor
    Graph(unsigned nv) : _nv(nv) {
        for (unsigned v = 0; v != _nv; ++v) {
            _adjList[v] = list<unsigned>();
            _inDegreeTbl[v] = 0;
        }
    }

    // Returns number of graph vertices
    inline unsigned
    nVertices() const { return _nv; }

    // Returns true if given vertex has no incoming edges
    bool
    isSourceVertex(unsigned v) {
        if (v >= _nv) {
            throw domain_error("Error! isSourceVertex() invalid vertex id!");
        }
        return (_inDegreeTbl[v] == 0);
    }

    // Adds given edge to graph
    void
    addEdge(unsigned src, unsigned dst) {
        if (src >= _nv || dst >= _nv) {
            throw domain_error("Error! addEdge() invalid vertex id!");
        }
        // Add edge to adjacency list and update indegree of destination
        _inDegreeTbl[dst]++;
        _adjList[src].push_back(dst);
    }

    // Removes given edge from graph
    void
    removeEdge(unsigned src, unsigned dst) {
        if (src >= _nv || dst >= _nv) {
            throw domain_error("Error! removeEdge() invalid vertex id!");
        }
        // update indegree of destination
        _inDegreeTbl[dst]--;
    }

    // Returns topological sorting of vertices
    vector<unsigned>
    topologicalSort() {
        // BFS Queue of source vertices
        queue<unsigned> sourceQ;

        // Populate the source Q
        for (unsigned v = 0; v != nVertices(); ++v) {
            if (isSourceVertex(v)) {
                sourceQ.push(v);
            }
        }

        vector<unsigned> tsV;
        while (!sourceQ.empty()) {
            // Pop vertex at source Q front and add it to
            // topo sorted vertices
            unsigned sv = sourceQ.front();
            sourceQ.pop();
            tsV.push_back(sv);

            // Iterate over all neighbours attached to popped off source
            // vertex and remove the edge connecting source vertex to neighbor.
            // Post removal, if neighbor becomes a source vertex, add it to 
            // source BFS Q
            list<unsigned>& neighbours = _adjList[sv];
            for (list<unsigned>::iterator it = neighbours.begin();
                it != neighbours.end(); ++it) {
                unsigned nv = *it;
                removeEdge(sv, nv);
                if (isSourceVertex(nv)) {
                    sourceQ.push(nv);
                }
            }
        }

        return tsV;
    }

private:
    // Data members

    // Number of vertices
    unsigned _nv;
    // Adjacency list with parent vertex mapped to child vertices it
    // is directly connected to
    unordered_map<unsigned, list<unsigned> > _adjList;
    // Table maintaining the number of incoming edges for each vertex
    unordered_map<unsigned, unsigned> _inDegreeTbl;
};

bool
TaskScheduler::schedulingPossible(unsigned nTasks,
    const vector<pair<unsigned, unsigned> >& prerequisites) {
    if (0 == nTasks || prerequisites.empty()) {
        throw domain_error("Error! No task or empty prerequisites!");
    }

    // Create and initialize graph with prerequisites
    // as edges and tasks as vertices
    Graph taskGraph(nTasks);
    typedef vector<pair<unsigned, unsigned> >::size_type vecSzT;
    for (vecSzT i = 0; i != prerequisites.size(); ++i) {
        const pair<unsigned, unsigned>& edge = prerequisites[i];
        taskGraph.addEdge(edge.first, edge.second);
    }

    // Do a topological sorting of vertices of task graph as per prerequisites
    vector<unsigned> tsV = taskGraph.topologicalSort();

    // Not able to find a valid topological sort of vertices (due to cycle/
    // edge ordering) => scheduling of tasks not possible as per prerequisites
    if (tsV.size() != nTasks) {
        return false;
    }

    return true;
}
