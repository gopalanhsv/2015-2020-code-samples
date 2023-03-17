// System includes
#include <string>
#include <vector>
#include <iostream>
#include <stdexcept>

// Local includes
#include "split.h"

// Using declarations
using std::string;
using std::vector;
using std::ostream;
using std::cin;
using std::cout;
using std::endl;
using std::domain_error;

void
displayVec(ostream& os, const vector<string>& v) {
    if (!os) {
        throw domain_error("Error! Invalid o/p stream! Exiting...!");
    }
    if (0 == v.size()) {
        throw domain_error("Error! Empty input vector! Exiting...!");
    }
    os << endl;
    for (vector<string>::size_type i = 0; i != v.size(); ++i) {
        os << v[i] << endl;
    }
}

int
main() {
    string line;
    while (getline(cin, line)) {
        vector<string> v = split(line);
        try {
            displayVec(cout, v);
        } catch (domain_error e) {
            cout << e.what() << endl;
            return 1;
        }
    }
    return 0;
}
