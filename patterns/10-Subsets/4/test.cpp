// System headers
#include <vector>
#include <string>
#include <stdexcept>
#include <iostream>
#include <iterator>
#include <algorithm>

// Local includes
#include "stringPermutations.h"

// Using declarations
using std::string;
using std::vector;
using std::domain_error;
using std::cin;
using std::cout;
using std::endl;
using std::ostream_iterator;
using std::copy;

// Statics, typedefs, globals

void
printVecOfVec(vector<string>& vs) {
    cout << endl;
    copy(vs.begin(), vs.end(), ostream_iterator<string>(cout, "\n"));
    cout << endl;
}

void
testFn() {
    while (true) {
        cout << "Enter input string : ";
        string s;
        if (cin >> s) {
            try {
                vector<string> lcp =
                    String::generateAllLetterCasePermutations(s);
                cout << "All Letter case permuations of " << s << " are : ";
                printVecOfVec(lcp);
            } catch (domain_error& e) {
                throw e;
            }
        } else {
            cin.clear();
            cin.ignore(10000, '\n');
            break;
        }
    }
}

int
main() {
    try {
        testFn();
    } catch (domain_error& e) {
        cout << e.what() << endl;
        return 1;
    }
    return 0;
}
