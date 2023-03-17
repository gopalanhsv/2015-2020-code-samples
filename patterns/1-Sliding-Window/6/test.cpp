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
    unsigned k =
        readInput<unsigned>("Enter max num of chars which can be replaced : ");

    try {
        unsigned l = String::longestSameCharSubtrLenPostCharReplacement(is, k);
        cout << "Longest substring of " << is
            << " with identical chars is of len " << l
            << " after replacing a maximum of " << k << " chars" << endl;
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
