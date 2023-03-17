// System headers
#include <iostream>
#include <stdexcept>

// Local includes
#include "../lib/Str.h"
#include "../lib/Vec.h"
#include "frame.h"

// Using declarations
using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::ostream;
using std::domain_error;

istream&
readVec(istream& in, Vec<Str>& v) {
    if (in) {
        v.clear();

        Str s;
        while (in >> s)
            v.push_back(s);

        in.clear();
    }
    return in;
}

void
printVec(ostream& os, const Vec<Str>& v) {
    if (!os)
        throw domain_error("Error! In o/p stream");

    for (Vec<Str>::const_iterator iter = v.begin();
        iter != v.end(); ++iter) {
        os << *iter << endl;
    }
}

int
main() {
    // Read the character picture
    Vec<Str> p;
    readVec(cin, p);
    // Frame the character picture
    Vec<Str> fp = frame(p);
    // Print the character picture
    try {
        printVec(cout, fp);
    } catch (domain_error e) {
        cout << e.what() << endl;
    }
    return 0;
}
