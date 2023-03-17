// System headers
#include <iostream>
#include <string>
#include <stdexcept>

// Local headers
#include "../Vec/Vec.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::istream;
using std::ostream;
using std::domain_error;

istream&
readLines(istream& in, Vec<string>& v) {
    if (in) {
        v.clear();

        string x;
        while (in >> x)
            v.push_back(x);

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
    // Read the lines and split using input operator
    Vec<string> words;
    readLines(cin, words);

    // Print the individual words
    try {
        printVec(cout, words);
    } catch (domain_error e) {
        cout << e.what() << endl;
    }
    return 0;
}
