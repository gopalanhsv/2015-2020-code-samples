// System headers
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <utility>
#include <iterator>
#include <algorithm>

// Local includes
#include "topoSort.h"

// Using declarations
using std::cin;
using std::cout;
using std::endl;
using std::domain_error;
using std::vector;
using std::string;
using std::pair;
using std::make_pair;
using std::ostream_iterator;
using std::copy;

// Statics, typedefs, globals

void
printVec(const vector<unsigned>& v) {
    cout << endl;
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
}

unsigned
readNum(const string& s) {
    unsigned n;
    while (1) {
        cout << s;
        if (cin >> n) {
            break;
        }
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Try again!" << endl;
    }
    return n;
}

void
test() {
    unsigned nv = readNum("Enter num vertices : ");
    vector<pair<unsigned, unsigned> > edgeV;
    unsigned ne = readNum("Enter num edges : ");
    for (unsigned i = 0; i != ne; ++i) {
        cout << endl << i + 1 << "th edge :" << endl;
        unsigned s = readNum("Enter source vertex : ");
        unsigned d = readNum("Enter destination vertex : ");
        edgeV.push_back(make_pair(s, d));
    }

    try {
        vector<unsigned> tsV = TopoSort::sort(nv, edgeV);
        cout << "Topologically sorted vertices are : ";
        printVec(tsV);
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
