// System includes
#include <string>
#include <stdexcept>
#include <iostream>

// Local includes
#include "locString.h"

// Using dcelarations
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::domain_error;

// Statics, typedefs, globals

template<typename T>
T
readInput(const string& s) {
    T x;
    while (1) {
        cout << endl << s;
        if (cin >> x) {
            break;
        }
        cin.clear();
        cin.ignore(1000, '\n');
        cout << endl << "Try again!!!";
    }
    return x;
}

void
test() {
    string is = readInput<string>("Enter input string : ");
    try {
        string os = String::longestSubStringWithNoRepeatChars(is);
        cout << "Longest substring of " << is
            << " with no repeating chars is : " << os << " of len "
            << os.size() << endl;
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
