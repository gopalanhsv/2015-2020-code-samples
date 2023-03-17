// System headers
#include <iostream>
#include <string>
#include <stdexcept>

// Local includes
#include "../Vec/Vec.h"
#include "frame.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::istream;
using std::ostream;
using std::domain_error;

istream&
readVec(istream& in, Vec<string>& v) {
    if (in) {
        v.clear();

        string s;
        while (getline(in, s))
            v.push_back(s);

        in.clear();
    }
    return in;
}

void
printVec(ostream& os, const Vec<string>& v) {
    if (!os)
        throw domain_error("Error! In o/p stream");

    for (Vec<string>::const_iterator iter = v.begin();
        iter != v.end(); ++iter) {
        os << *iter << endl;
    }
}

int
main() {
    // Read the character picture
    Vec<string> p;
    readVec(cin, p);
    // Frame the character picture
    Vec<string> fp = frame(p);
    // Print the character picture
    try {
        printVec(cout, fp);
    } catch (domain_error e) {
        cout << e.what() << endl;
    }
    return 0;
}
