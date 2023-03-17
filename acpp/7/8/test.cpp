// System headers
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <stdexcept>

// Local includes
#include "xref.h"
#include "findUrl.h"

// Using declarations
using std::string;
using std::vector;
using std::map;
using std::cin;
using std::cout;
using std::endl;
using std::domain_error;

// Typedefs

int
main() {
    map<string, vector<unsigned long> > wordsToLinesTbl = xref(cin, findUrl);
    try {
        displayXrefTable(cout, wordsToLinesTbl);
    } catch (domain_error e) {
        cout << e.what() << endl;
    }
    return 0;
}
