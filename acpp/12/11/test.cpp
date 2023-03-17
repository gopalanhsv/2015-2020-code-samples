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

    const char cp1[] = "shyam is a monkey";
    Str s(cp1);
    cout << s << endl;
    const char cp2[] = "mules are donkeys";
    Str r = cp2 + s;
    cout << r << endl;

    cout << "Test end" << endl;
}

int
main() {
    test();
    return 0;
}
