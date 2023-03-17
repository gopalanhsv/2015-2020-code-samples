// System headers
#include <iostream>
#include <list>

// Local includes
#include "Str.h"

// Using declarations
using std::cin;
using std::cout;
using std::endl;
using std::list;

void
test1() {
    cout << "Test 1 start" << endl;

    Str s;
    cout << s << endl;

    cout << "Enter a string : ";
    cin >> s;
    cout << s << endl;

    cout << "Enter a string : ";
    cin >> s;
    cout << s << endl;

    cout << "Test 1 end" << endl;
}

void
test2() {
    cout << "Test 2 start" << endl;

    Str s1("monkey is a donkey");
    cout << s1 << endl;

    Str s2("donkey is a monkey");
    cout << s2 << endl;

    s2 = s1;
    cout << s2 << endl;

    cout << "Test 2 end" << endl;
}

void
test3() {
    cout << "Test 3 start" << endl;

    const char *cp1 = "monkey is";
    cout << cp1 << endl;

    const char *cp2 = " a donkey";
    cout << cp2 << endl;

    Str s1 = cp1;
    cout << s1 << endl;

    Str s2 = cp2;
    s2 += cp2;
    cout << s2 << endl;

    cout << s1 + s2 << endl;

    cout << "Test 3 end" << endl;
}

int
main() {
    //test1();
    //test2();
    test3();
    return 0;
}
