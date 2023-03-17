// System includes
#include <iostream>
#include <stdexcept>

// Local includes
#include "../lib/Str.h"
#include "../lib/Vec.h"
#include "split.h"

// Using declarations
using std::ostream;
using std::cin;
using std::cout;
using std::endl;
using std::domain_error;

void
displayVec(ostream& os, const Vec<Str>& v) {
    if (!os) {
        throw domain_error("Error! Invalid o/p stream! Exiting...!");
    }
    if (0 == v.size()) {
        throw domain_error("Error! Empty input vector! Exiting...!");
    }
    os << endl;
    for (Vec<Str>::size_type i = 0; i != v.size(); ++i) {
        os << v[i] << endl;
    }
}

int
main() {
    Str line;
    while (getline(cin, line)) {
        Vec<Str> v = split(line);
        try {
            displayVec(cout, v);
        } catch (domain_error e) {
            cout << e.what() << endl;
            return 1;
        }
    }
    return 0;
}
