// System headers
#include <iostream>
#include <stdexcept>
#include <vector>
#include <utility>

// Local includes
#include "undirectedGraph.h"

// Using declarations
using std::vector;
using std::pair;
using std::cin;
using std::cout;
using std::endl;
using std::domain_error;
using std::runtime_error;

// Statics, typedefs, globals

void
testFn() {
    int n;
    cout << "Enter num vertices : ";
    cin >> n;
    UndirectedGraph ug(n);
    cout << endl << "Add edges ==>" << endl;
    while (cin) {
        int s, d;
        cout << "Enter src vertex : ";
        cin >> s;
        if (!cin) {
            break;
        }
        cout << "Enter dst vertex : ";
        while (!(cin >> d)) {
            cin.clear();
        }

        ug.addEdge(s, d);
    }

    try {
        vector<pair<int, int> > vcpVec = ug.greedyColoring();
        printVertexColors(vcpVec);
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
