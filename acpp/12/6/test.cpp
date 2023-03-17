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
    cout << ((s) ?  "Non-E" : "E") << "mpty string" << endl;

    cout << "Enter a string : ";
    cin >> s;

    cout << ((s) ?  "Non-E" : "E") << "mpty string" << endl;
}

int
main() {
    test();
    test();
    test();
    return 0;
}
