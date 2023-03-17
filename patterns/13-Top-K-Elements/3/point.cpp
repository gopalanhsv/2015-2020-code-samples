// System headers
#include <vector>
#include <stdexcept>
#include <algorithm>

// Local includes
#include "point.h"

// Using declarations
using std::vector;
using std::domain_error;
using std::make_heap;
using std::pop_heap;
using std::push_heap;

// Statics, typedefs, globals

// Compare function for building a max heap of points based
// on points' respective distances from (0, 0)
struct PointCmp {
    bool operator()(const Point& p1, const Point& p2) const {
        return p1.squaredDistFromOrigin() < p2.squaredDistFromOrigin();
    }
};

vector<Point>
PointsArray::kClosestPointsToOrigin(
    const vector<Point>& pv, unsigned long k) {
    if (pv.empty()) {
        throw domain_error("Error! Empty input vector!");
    }
    if (0 == k || k > pv.size()) {
        throw domain_error("Error! Invalid value of k!");
    }

    // k Closest points to the origin are found by iterating over the
    // points input vector sequentially, and add the elements to a
    // heap/PQ which keeps track of the k closest points to the origin
    // amongst the points processed so far in iterating. This is done
    // by maintaining a heap of size k at all times, and replacing the
    // point at maximum distance from origin in the heap with new point
    // from input vector, if a new point at a closer distance to origin.
    // So the heap should be a max heap to ensure that
    // point at maximum distance from origin is always at top for easy
    // access for comparisons

    // Create a max heap using the first 'k' points
    vector<Point> maxHeapV(pv.begin(), pv.begin() + k);
    make_heap(maxHeapV.begin(), maxHeapV.end(), PointCmp());

    // Iterate over the remaining points from the input vector
    for (vector<Point>::size_type i = k; i != pv.size(); ++i) {
        // Replace point in heap at maximum distance from origin
        // (heap top) with newer point; if newer point is
        // closer to origin -- so that heap always has k points
        // at smallest distance from origin 
        const Point& maxDistHeapPt = maxHeapV.front();
        const Point& newPoint = pv[i];
        if (newPoint.squaredDistFromOrigin() <
                maxDistHeapPt.squaredDistFromOrigin()) {
            // Remove heap top element
            pop_heap(maxHeapV.begin(), maxHeapV.end(), PointCmp());
            maxHeapV.pop_back();
            // Add new point to heap
            maxHeapV.push_back(newPoint);
            push_heap(maxHeapV.begin(), maxHeapV.end(), PointCmp());
        }
    }

    return maxHeapV;
}
