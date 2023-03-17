// System headers
#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
#include <stdexcept>

// Local includes
#include "alienDictionary.h"

// Using declarations
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::istream_iterator;
using std::ostream_iterator;
using std::copy;
using std::back_inserter;
using std::domain_error;

// Statics, typedefs, globals

void
readStrings(vector<string>& v) {
    v.clear();
    copy(istream_iterator<string>(cin),
        istream_iterator<string>(), back_inserter(v));
    cin.clear();
    cin.ignore(1000, '\n');
}

void
printStrings(const vector<string>& v) {
    cout << endl;
    copy(v.begin(), v.end(), ostream_iterator<string>(cout, " "));
    cout << endl;
}

void
printChars(const vector<char>& v) {
    cout << endl;
    copy(v.begin(), v.end(), ostream_iterator<char>(cout, "->"));
    cout << endl;
}

void
test() {
    cout << "Enter words of alien dictionary in lexicographical order : ";
    vector<string> wordV;
    readStrings(wordV);
    cout << endl << "Alien words are : ";
    printStrings(wordV);

    try {
        vector<char> cV = AlienDict::dictionaryOrder(wordV);
        if (cV.empty()) {
            cout << "No ordering of chars due to cyclic dependency!" << endl;
        } else {
            cout << "Alien dictionary characters order is : ";
            printChars(cV);
        }
    } catch (domain_error& e) {
        throw e;
    }
}

int
main() {
    try {
        test();
    } catch (domain_error& e) {
        cout << e.what() << endl;
    }
    return 0;
}
