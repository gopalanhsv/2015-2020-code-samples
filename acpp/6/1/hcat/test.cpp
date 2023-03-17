// System includes
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

// Local includes
#include "frame.h"
#include "hcat.h"

// Using declarations
using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::ostream;
using std::domain_error;

istream&
readVec(istream& in, vector<string>& v) {
    if (in) {
        v.clear();
        string line;
        while (getline(in, line)) {
            v.push_back(line);
        }
        in.clear();
    }
    return in;
}

void
displayVec(ostream& os, const vector<string>& v) {
    if (!os) {
        throw domain_error("Error! Invalid o/p stream! Exiting...!");
    }

    if (0 == v.size()) {
        throw domain_error("Error! Empty o/p vector! Exiting...!");
    }

    for (vector<string>::const_iterator iter = v.begin();
            iter != v.end(); ++iter) {
        os << *iter << endl;
    }

    return;
}

int
main() {
    vector<string> p;
    readVec(cin, p);
    try {
        vector<string> hp = hcat(p, frame(p));
        try {
            displayVec(cout, hp);
        } catch (domain_error e) {
            cout << e.what() << endl;
            return 1;
        }
    } catch (domain_error e) {
        cout << e.what() << endl;
        return 1;
    }

    return 0;
}
