#ifndef _WEIGHTED_UNDIRECTED_GRAPH_H_
#define _WEIGHTED_UNDIRECTED_GRAPH_H_

// System headers
#include <vector>
#include <list>

// Local includes

// Using declarations

// Statics, typedefs, globals
typedef struct std::pair<int, int> intPairT;

typedef struct edgeT {
    int _s; // Src vertex
    int _d; // Dst vertex
    int _cost; // Edge weight/cost

    edgeT(int src, int dst, int cost) {
        _s = src;
        _d = dst;
        _cost = cost;
    }

} edgeT;

namespace std {
    template<>
    struct greater<edgeT> {
    public:
        bool operator() (const edgeT& e1, const edgeT& e2) const {
            return e1._cost > e2._cost;
        }
    };
};

// Weighted undirected graph
class WtdUndirGraph {
public:
    // Constructors
    WtdUndirGraph(int v, int e) : _nVertices(v),
        _nEdges(e), _adjList(std::vector<std::list<intPairT> >(v)) {}

    // Accessors
    int getNumVertices() const { return _nVertices; }
    int getNumEdges() const { return _nEdges; }
    const std::vector<edgeT>& getEdges() const { return _edges; }
    const std::vector<std::list<intPairT> >& getAdjacencyList() const {
        return _adjList;
    }
    const std::list<intPairT>& getNeighbours(int v) const;

    // Add/remove edges
    void addEdge(int src, int dst, int cost);
    void removeEdge(int src, int dst);

    // MST display
    void displayMST(const std::list<edgeT>& mstEdges);

    // MST Kruskal
    std::list<edgeT> computeKruskalMST();

    // MST Prim
    std::list<edgeT> computePrimMST();

    // Dijkstra shortest path
    std::vector<int> dijkstraShortestPath(int src);

    // Print shortest distance for each vertex
    void displayVertexShortestDistance(const std::vector<int>& dV);

private:
    WtdUndirGraph();

    // Data members
    int _nVertices;
    int _nEdges;
    std::vector<edgeT> _edges;
    std::vector<std::list<intPairT> > _adjList;
};

#endif /* _WEIGHTED_UNDIRECTED_GRAPH_H_ */
