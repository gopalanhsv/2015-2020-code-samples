#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

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
    // Read the lines and split using input operator
    vector<string> words;
    readLines(cin, words);

    // Print the individual words
    try {
        printVec(cout, words);
    } catch (domain_error e) {
        cout << e.what() << endl;
    }
    return 0;
}
