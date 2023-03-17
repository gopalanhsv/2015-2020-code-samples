// System headers
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <algorithm>
#include <iterator>

// Local includes
#include "locString.h"

// Using declarations
using std::vector;
using std::string;
using std::domain_error;
using std::cin;
using std::cout;
using std::endl;
using std::ostream_iterator;

// Statics, typedefs, globals

template<typename T>
void
printVec(const vector<T>& v) {
    cout << endl;
    copy(v.begin(), v.end(), ostream_iterator<T>(cout, " "));
    cout << endl;
}

template<typename T>
T
readInput(const string& s) {
    T x;
    while (1) {
        cout << s;
        if (cin >> x) {
            break;
        }
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Error! Try again!" << endl;
    }
    return x;
}

void
test() {
    string s = readInput<string>("Enter input string : ");
    string p = readInput<string>("Enter search pattern : ");

    try {
        vector<string::size_type> patternLocV = String::findAnagrams(s, p);
        if (patternLocV.empty()) {
            cout << "No anagrams of " << p << " present in " << s << endl;
        } else {
            cout << "Anagrams of " << p << " present in " << s << " at ";
            printVec<string::size_type>(patternLocV);
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
        return 1;
    }
    return 0;
}
