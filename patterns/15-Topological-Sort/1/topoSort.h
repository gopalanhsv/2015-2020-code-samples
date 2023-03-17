#ifndef _TOPO_SORT_H_
#define _TOPO_SORT_H_

// System headers
#include <vector>
#include <utility>

// Local includes

// Using declarations

// Statics, typedefs, globals

class TopoSort {
public:
    static std::vector<unsigned> sort(unsigned nVertices,
        const std::vector<std::pair<unsigned, unsigned> >& edges);
private:
};

#endif /* _TOPO_SORT_H_ */
