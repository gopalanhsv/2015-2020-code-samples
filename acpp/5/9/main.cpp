#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

#include "lowerupper.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::istream;
using std::ostream;
using std::domain_error;

istream&
readVec(istream& in, vector<string>& v) {
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
    // Read the words from input
    vector<string> words;
    readVec(cin, words);
    // Split the words into lowercase only followed by
    // non-lowercase words
    vector<string> v = lcaseFollowedByUcase(words);
    // Print the words
    try {
        printVec(cout, v);
    } catch (domain_error e) {
        cout << e.what() << endl;
    }
    return 0;
}
