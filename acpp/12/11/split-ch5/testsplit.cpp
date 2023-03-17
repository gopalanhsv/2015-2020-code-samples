// System headers
#include <iostream>
#include <stdexcept>

// Local includes
#include "../lib/Str.h"
#include "../lib/Vec.h"
#include "split.h"

using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::ostream;
using std::domain_error;

istream&
readLines(istream& in, Vec<Str>& v) {
    if (in) {
        v.clear();

        Str x;
        while (in >> x)
            v.push_back(x);

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
    // Read the lines and split using input operator
    Vec<Str> words;
    readLines(cin, words);

    // Print the individual words
    try {
        printVec(cout, words);
    } catch (domain_error e) {
        cout << e.what() << endl;
    }
    return 0;
}
