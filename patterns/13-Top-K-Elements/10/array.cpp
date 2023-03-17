// System headers
#include <vector>
#include <queue>
#include <stdexcept>

// Local includes
#include "array.h"

// Using declarations
using std::vector;
using std::priority_queue;
using std::domain_error;
using std::greater;
using std::less;

// Statics, typedefs, globals

unsigned long
Array::elementsSumBetweenK1AndK2SmallestElems(
    const vector<int>& v, unsigned long k1, unsigned long k2) {
    if (v.empty()) {
        throw domain_error("Error! Empty input vector!");
    }
    if (k1 > k2 || k2 > v.size() || k1 == 0) {
        throw domain_error("Error! Invalid value of k1/k2!");
    }

    // Base case of no elements
    if (k1 == k2) {
        return 0;
    }

    // Add all elements of input vector to a min heap. This will
    // ensure that input vector elements can be popped off in
    // ascending order commencing from smallest to largest element
    priority_queue<int, vector<int>, greater<int> > minHeap;
    for (auto e : v) {
        minHeap.push(e);
    }

    // Remove k1 elements from min heap => k1 smallest elements gone
    // and next element would be k+1 smallest element.
    for (unsigned long int i = 1; i <= k1; ++i) {
        minHeap.pop();
    }
    // Pop off and sum up the next set of elements sequentially upto
    // but not including original k2 smallest element; this would
    // give sum of elements between k1 and k2 smallest elements
    unsigned long sum = 0;
    for (unsigned long int i = k1 + 1; i != k2; ++i) {
        sum += minHeap.top();
        minHeap.pop();
    }

    return sum;
}
