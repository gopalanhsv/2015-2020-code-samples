// System headers
#include <iostream>
#include <vector>
#include <stdexcept>
#include <iterator>
#include <algorithm>
#include <string>

// Local includes
#include "minHeightTrees.h"

// Using declarations
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::domain_error;
using std::ostream_iterator;
using std::copy;

// Statics, typedefs, globals

unsigned
readNum(const string& s) {
    unsigned x;
    while (1) {
        cout << s;
        if (cin >> x) {
            break;
        }
        cin.clear();
        cin.ignore(1000, '\n');
        cout << endl << "Try again!!!" << endl;
    }
    return x;
}

void
printVec(const vector<unsigned>& v) {
    cout << endl;
    copy(v.begin(), v.end(), ostream_iterator<unsigned>(cout, " "));
    cout << endl;
}

void
test() {
    unsigned nv = readNum("Enter num graph vertices : ");
    UndirectedGraph g(nv);

    unsigned ne = readNum("Enter num graph edges : ");
    for (unsigned i = 1; i <= ne; ++i) {
        cout << "Enter edge #" << i << endl;
        unsigned u = readNum("Enter src : ");
        unsigned v = readNum("Enter dst : ");
        g.addEdge(u, v);
    }

    try {
        vector<unsigned> mhtV = g.computeMinHeightTreeRoots();
        cout << "Min height trees of given graph are rooted at : ";
        printVec(mhtV);
    } catch (domain_error& e) {
        throw e;
    }
}

int
main() {
    try {
        test();
    } catch (domain_error& e) {
        cout << e.what() << endl;
        return 1;
    }
    return 0;
}
