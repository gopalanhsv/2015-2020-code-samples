// System includes
#include <string>
#include <vector>
#include <iostream>
#include <stdexcept>

// Local includes
#include "findUrl.h"

// Using declarations
using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::ostream;
using std::domain_error;

// Typedefs

istream&
readLinesAndConvertToString(istream& is, string& s) {
    if (is) {
        s.clear();
        string line;
        while (getline(is, line)) {
            s += line;
        }
        is.clear();
    }
    return is;
}

void
displayStrVec(ostream& os, const vector<string>& v) {
    if (!os) {
        throw domain_error("Error! Empty o/p stream! Exiting...!");
    }

    if (0 == v.size()) {
        throw domain_error("Error! Empty input display vector! Exiting...!");
    }

    os << endl << endl;
    for (vector<string>::size_type i = 0; i != v.size(); ++i) {
        os << v[i] << endl;
    }
    os << endl << endl;
}

int
main() {
    string file;
    readLinesAndConvertToString(cin, file);
    vector<string> urls = findUrl(file);
    try {
        try {
            displayStrVec(cout, urls);
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
