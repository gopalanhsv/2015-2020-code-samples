// System headers
#include <iostream>
#include <list>
#include <algorithm>

// Local includes
#include "Str.h"

// Using declarations
using std::cin;
using std::cout;
using std::endl;
using std::list;

void
test() {
    cout << "Test start" << endl;

    Str s1, s2;
    cout << "Enter a string1 : ";
    cin >> s1;
    cout << "Enter a string2 : ";
    cin >> s2;

    cout << "s1 == s2 : " << (s1 == s2) << endl;
    cout << "s1 != s2 : " << (s1 != s2) << endl;

    cout << "Test end" << endl;
}

int
main() {
    test();
    test();
    test();
    return 0;
}
