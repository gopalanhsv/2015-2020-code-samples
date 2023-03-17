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
    cout << "String contents are :";
    for (Str::iterator iter = s.begin(); iter != s.end(); ++iter) {
        cout << " " << *iter;
        *iter = 'm';
    }
    cout << "Modified string = " << s << endl;
    cout << endl;
}

void
testConst() {
    cout << "Test start" << endl;

    const Str s = "Baba donkey";
    cout << "String contents are :";
    for (Str::const_iterator iter = s.begin(); iter != s.end(); ++iter) {
        cout << " " << *iter;
    }
    cout << endl;
}

int
main() {
    test();
    test();
    testConst();
    return 0;
}
