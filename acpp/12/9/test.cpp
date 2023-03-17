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
    getline(cin, s);
    cout << s << endl;

    cout << "Test end" << endl;
}

int
main() {
    test();
    return 0;
}
