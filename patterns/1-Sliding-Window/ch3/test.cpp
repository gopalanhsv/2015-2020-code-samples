// System headers
#include <string>
#include <iostream>
#include <stdexcept>

// Local includes
#include "locString.h"

// Using declarations
using std::cin;
using std::cout;
using std::endl;
using std::domain_error;
using std::string;

// Statics, typedefs, globals

template <typename T>
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
        cout << "Try again!!!" << endl;
    }
    return x;
}

void
test() {
    string s = readInput<string>("Enter input string : ");
    string p = readInput<string>("Enter search pattern string : ");

    try {
        string subStr = String::shortestSubstringHavingPattern(s, p);
        if (subStr.empty()) {
            cout << "Pattern " << p << " not found in " << s << endl;
        } else {
            cout << "Shortest substring of " << s << " with pattern "
                << p << " is " << subStr << endl;
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
