// System headers
#include <iostream>
#include <stdexcept>

// Local includes
#include "maxHeap.h"
#include "maxHeap.cpp"
#include "minHeap.h"
#include "minHeap.cpp"

// Using declarations
using std::cin;
using std::cout;
using std::endl;
using std::domain_error;

// Statics, typedefs, globals

void
testMaxHeap() {
    MaxHeap<int> mh;
    try {
        mh.insert(2);
        mh.insert(8);
        mh.insert(15);
        mh.insert(5);
        mh.insert(1);
        mh.insert(20);

        int m = mh.max();
        mh.removeMax();
        cout << "Max = " << m << endl;
        m = mh.max();
        mh.removeMax();
        cout << "Max = " << m << endl;
        m = mh.max();
        cout << "Max = " << m << endl;
        mh.insert(1000);
        m = mh.max();
        cout << "Max = " << m << endl;
    } catch (domain_error& e) {
        throw e;
    }
}

void
testMinHeap() {
    MinHeap<int> mh;
    try {
        mh.insert(2);
        mh.insert(8);
        mh.insert(15);
        mh.insert(5);
        mh.insert(1);
        mh.insert(20);

        int m = mh.min();
        cout << "Min = " << m << endl;
        mh.removeMin();
        m = mh.min();
        cout << "Min = " << m << endl;
        mh.removeMin();
        mh.insert(-800);
        m = mh.min();
        cout << "Min = " << m << endl;
    } catch (domain_error& e) {
        throw e;
    }
}

int
main() {
    try {
        testMaxHeap();
        testMinHeap();
    } catch (domain_error& e) {
        cout << e.what() << endl;
        return 1;
    }
    return 0;
}
