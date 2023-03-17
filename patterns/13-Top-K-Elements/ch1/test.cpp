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

void
test() {
    cout << "Enter input string to be rearranged : ";
    string is;
    cin >> is;
    while (true) {
        unsigned long k;
        cout << endl << "Enter min distance k only after which same "
            << "chars should occur :";
        if (cin >> k) {
            try {
                string os = Str::reorderStrWithSameCharsKDistApart(is, k);
                if (!os.empty()) {
                    cout << "Rearranged string is " << os << endl;
                } else {
                    cout << "Input string cannot be rearranged" << endl;
                }
            } catch (domain_error& e) {
                throw e;
            }
            break;
        } else {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Try again!!" << endl;
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
