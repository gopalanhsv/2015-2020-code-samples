#ifndef _MIN_HT_TREES_H_
#define _MIN_HT_TREES_H_

// System headers
#include <vector>
#include <unordered_map>
#include <cassert>

// Local includes
// Using declarations
// Statics, typedefs, globals

class UndirectedGraph {
public:
    // Constructor
    UndirectedGraph(unsigned nv);

    // Adds given vertex to the graph
    void addVertex(unsigned v);

    // Adds given edge to the graph
    void addEdge(unsigned u, unsigned v);

    // Determines the vertices of the graph which form min height trees
    std::vector<unsigned> computeMinHeightTreeRoots();

private:
    // Interfaces
    // Returns number of vertices in the graph
    inline unsigned numVertices() const { return _nv; }

    // Returns true if given node is a leaf, false otherwise
    inline bool
    isLeaf(unsigned v) {
        return _numEdgesTbl[v] == 1;
    }

    // Returns list of neighbour vertices to given vertex
    std::vector<unsigned>& neighbourVertices(unsigned v);

    // Removes given edge from the graph
    void removeEdgeVirtual(unsigned u, unsigned v);

    // Removes given vertex from the graph
    void removeVertexVirtual(unsigned v);

    // Data members

    // Num vertices
    unsigned _nv;
    // Adjacency list per vertex
    std::unordered_map<unsigned, std::vector<unsigned> > _adjListTbl;
    // Hash table which tracks the number of edges per vertex 
    std::unordered_map<unsigned, unsigned> _numEdgesTbl;
};

#endif /* _MIN_HT_TREES_H_ */
