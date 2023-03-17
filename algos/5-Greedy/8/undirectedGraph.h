#ifndef _UNDIRECTED_GRAPH_H_
#define _UNDIRECTED_GRAPH_H_

// System headers
#include <list>
#include <vector>
#include <utility>

// Local includes

// Using declarations

// Statics, typedefs, globals

class UndirectedGraph {
public:
    // Constructors
    UndirectedGraph(int v) : _nVertices(v), _adjacencyList(v, std::list<int>()) {}

    // Accessors
    int getNumVertices() const { return _nVertices; }
    const std::vector<std::list<int> >& getAdjacencyList() const {
        return _adjacencyList;
    }
    const std::list<int>& getVertexNeighbours(int v) const {
        return _adjacencyList[v];
    }

    // Add an edge between vertices u & v
    void addEdge(int u, int v);
    // Remove edge between vertices u & v
    void removeEdge(int u, int v);
    // Greedy coloring of entire graph
    std::vector<std::pair<int, int> > greedyColoring();

private:
    UndirectedGraph();

    // Data members
    int _nVertices;
    std::vector<std::list<int> > _adjacencyList;
};

// Prints the vertex id and associate color using specified vector input
void
printVertexColors(
    const std::vector<std::pair<int, int> >& vertexColorPairVec);

#endif /* _UNDIRECTED_GRAPH_H_ */
