// System headers
#include <iostream>
#include <stdexcept>
#include <string>

// Local includes
#include "locString.h"

// Using declarations
using std::domain_error;
using std::cin;
using std::cout;
using std::endl;
using std::string;

// Statics, typedefs, globals

template<typename T>
T
readInput(const string& os) {
    T x;
    while (1) {
        cout << os;
        if (cin >> x) {
            break;
        }
        cin.clear();
        cin.ignore(1000, '\n');
        cout << endl << "Error! Try again!" << endl;
    }
    return x;
}

void
test() {
    string s = readInput<string>("Enter input string : ");
    string p = readInput<string>("Enter pattern string to search for : ");

    try {
        bool present = String::hasPatternPermutation(s, p);
        cout << s << (present ? " has" : " doesn't have")
            << " permutation of " << p << endl;
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
