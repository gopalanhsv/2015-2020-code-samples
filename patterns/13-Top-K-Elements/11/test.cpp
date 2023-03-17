// System headers
#include <string>
#include <iostream>
#include <stdexcept>

// Local includes
#include "str.h"

// Using declarations
using std::string;
using std::domain_error;
using std::cin;
using std::cout;
using std::endl;

// Statics, typedefs, globals

void
test() {
    while (true) {
        cout << "Enter string to be rearranged such that no same "
            << "characters are adjacent : ";
        string is;
        if (cin >> is) {
            try {
                string os = Str::rearrangeWithNoSameAdjacentChars(is);
                cout << "Rearranged string is : " << os << endl;
            } catch (domain_error& e) {
                throw e;
            }
        } else {
            cin.clear();
            cin.ignore(1000, '\n');
            break;
        }
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
