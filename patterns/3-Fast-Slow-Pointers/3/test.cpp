// System headers
#include <iostream>

// Local includes
#include "happyNumber.h"

// Using declarations
using std::cin;
using std::cout;
using std::endl;

void
testFn() {
    unsigned int n;
    cout << "Enter a number : ";
    while (cin >> n) {
        bool x = Number::isHappyNumber(n);
        cout << n << " is " << (x ? "" : "not ") << "a happy number" << endl;
        cout << endl << "Enter a number : ";
    }
}

int
main() {
    testFn();
    return 0;
}
