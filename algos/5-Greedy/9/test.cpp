// System headers
#include <iostream>
#include <stdexcept>
#include <vector>
#include <list>
#include <utility>

// Local includes
#include "wtUndirGraph.h"

// Using declarations
using std::vector;
using std::list;
using std::pair;
using std::cin;
using std::cout;
using std::endl;
using std::domain_error;
using std::runtime_error;

// Statics, typedefs, globals

void
testFn() {
    int v, e;
    cout << "Enter num vertices : ";
    cin >> v;
    cout << "Enter num edges : ";
    cin >> e;
    WtdUndirGraph g(v, e);
    cout << endl << "Add edges ==>" << endl;
    while (e--) {
        int s, d, cost;
        cout << "Enter src vertex : ";
        cin >> s;
        if (!cin) {
            break;
        }
        cout << "Enter dst vertex : ";
        while (!(cin >> d)) {
            cin.clear();
        }
        cout << "Enter edge cost : ";
        while (!(cin >> cost)) {
            cin.clear();
        }

        g.addEdge(s, d, cost);
    }

    try {
        //list<edgeT> mstEdges = g.computeKruskalMST();
        list<edgeT> mstEdges = g.computePrimMST();
        g.displayMST(mstEdges);
    } catch (domain_error& e) {
        throw e;
    } catch (runtime_error& e) {
        throw e;
    }
}

int
main() {
    try {
        testFn();
    } catch (domain_error& e) {
        cout << e.what() << endl;
        return 1;
    } catch (runtime_error& e) {
        cout << e.what() << endl;
        return 1;
    }
    return 0;
}
