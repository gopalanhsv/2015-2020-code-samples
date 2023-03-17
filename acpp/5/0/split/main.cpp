#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

#include "split.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::istream;
using std::ostream;
using std::domain_error;

istream&
readLines(istream& in, vector<string>& v) {
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

vector<string>
splitAllLines(const vector<string>& lines) {
    if (0 == lines.size())
        throw domain_error(
            "Error! No lines entered! Pls re-eenter! Exiting...!");

    vector<string> ret;
    for (vector<string>::size_type i = 0; i != lines.size(); ++i) {
        vector<string> v = split(lines[i]);
        ret.insert(ret.end(), v.begin(), v.end());
    }

    return ret;
}

int
main() {
    // Read the lines
    vector<string> lines;
    readLines(cin, lines);
    // Split the lines into individual words
    vector<string> v;
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
