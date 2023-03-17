#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

#include "frame.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::istream;
using std::ostream;
using std::domain_error;

void
printVec(ostream& os, const vector<string>& v) {
    if (!os)
        throw domain_error("Error! In o/p stream");

    for (vector<string>::const_iterator iter = v.begin();
        iter != v.end(); ++iter) {
        os << *iter << endl;
    }
}

int
main() {
    // Read the character picture
    vector<string> p;
    // Frame the character picture
    vector<string> fp = frame(p);
    // Print the character picture
    try {
        printVec(cout, fp);
    } catch (domain_error e) {
        cout << e.what() << endl;
    }
    return 0;
}
