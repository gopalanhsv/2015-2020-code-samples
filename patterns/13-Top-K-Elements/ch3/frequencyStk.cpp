// System headers
#include <queue>
#include <vector>
#include <stdexcept>

// Local includes
#include "frequencyStk.h"

// Using namespaces
using std::runtime_error;

// Statics, typedefs, globals

void
FrequencyStack::push(int n) {
    // Update element frequency count
    _frequencyCntTbl[n]++;
    // Create stack element
    StkElement newElem(n, _frequencyCntTbl[n], _globalSeqNum);
    // Add stack element to max heap
    _maxHeap.push(newElem);
    // Update global sequence number
    _globalSeqNum++;
}

int
FrequencyStack::pop() {
    if (empty()) {
        throw runtime_error("Error! No element in stack to pop()!");
    }

    // Pop off stack element at PQ top
    StkElement topElem = _maxHeap.top();
    _maxHeap.pop();

    // Update frequency/occurrence count of element. In case it falls
    // to 0, remove element from frequency table
    int n = topElem.num();
    if (_frequencyCntTbl[n] > 0) {
        _frequencyCntTbl[n]--;
    } else {
        _frequencyCntTbl.erase(n);
    }

    return n;
}

bool
FrequencyStack::empty() const {
    return _maxHeap.empty();
}
