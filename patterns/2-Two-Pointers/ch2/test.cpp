// System headers
#include <iostream>
#include <string>
#include <stdexcept>

// Local includes
#include "backspaceCompare.h"

// Statics, typedefs, globals

// Using declarations
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::domain_error;

void
test() {
    while (1) {
        string s1, s2;
        cout << "Enter string s1 : ";
        while (!(cin >> s1));
        cout << "Enter string s2 : ";
        while (!(cin >> s2));

        try {
            bool e = BackspaceCompare::compare(s1, s2);
            cout << "Strings " << s1 << " and " << s2
                << " after backspace removal are "
                << ((e) ? "" : "not ") << "identical" << endl;
        } catch (domain_error& e) {
            throw e;
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
