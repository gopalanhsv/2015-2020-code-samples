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

    Str s;
    cout << "Enter a string : ";
    cin >> s;

    const char cp[] = "Hero am I?";

    cout << s + cp << endl;
    cout << cp + s << endl;

    cout << "Test end" << endl;
}

int
main() {
    test();
    test();
    test();
    return 0;
}
