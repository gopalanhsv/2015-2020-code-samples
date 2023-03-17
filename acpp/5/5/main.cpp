#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

#include "center.h"

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

        string line;
        while (getline(in, line))
            v.push_back(line);

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
    // Read the character picture
    vector<string> p;
    readVec(cin, p);
    // Frame the character picture
    vector<string> fp = center(p);
    // Print the character picture
    try {
        printVec(cout, fp);
    } catch (domain_error e) {
        cout << e.what() << endl;
    }
    return 0;
}
