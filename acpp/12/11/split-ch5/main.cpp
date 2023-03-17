// System headers
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <iterator>

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

        Str line;
        while (getline(in, line))
            v.push_back(line);

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

Vec<Str>
splitAllLines(const Vec<Str>& lines) {
    if (0 == lines.size())
        throw domain_error(
            "Error! No lines entered! Pls re-eenter! Exiting...!");

    Vec<Str> ret;
    for (Vec<Str>::size_type i = 0; i != lines.size(); ++i) {
        Vec<Str> v = split(lines[i]);
        std::copy(v.begin(), v.end(), std::back_inserter(ret));
    }

    return ret;
}

int
main() {
    // Read the lines
    Vec<Str> lines;
    readLines(cin, lines);
    // Split the lines into individual words
    Vec<Str> v;
    try {
        v = splitAllLines(lines);
    } catch (domain_error e) {
        cout << e.what() << endl;
    }
    
    // Print the individual words
    try {
        printVec(cout, v);
    } catch (domain_error e) {
        cout << e.what() << endl;
    }
    return 0;
}
