#ifndef _ARRAY_H_
#define _ARRAY_H_

// System headers
#include <vector>
#include <queue>
#include <functional>

// Local includes
// Using declarations
// Statics, typedefs, globals

class KthLargestElement {
public:
    // Constructor
    KthLargestElement(const std::vector<int>& v, unsigned int k);

    // Accessors
    int addElement(int e);
    
private:
    KthLargestElement();

    // Data members
    // PQ/Min heap which keeps track of the latest K largest numbers
    // seen/added to the class object at any time, with the Kth
    // largest number(minimum amongst the set of K numbers) at the
    // top of heap
    std::priority_queue<int, std::vector<int>, std::greater<int> > _minHeap;
    unsigned int _maxAllowedHeapElems;
};

#endif /* _ARRAY_H_ */
