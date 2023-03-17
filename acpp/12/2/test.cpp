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
test(Str& s) {
    cout << "Test start" << endl;

    cout << "Enter a string : ";
    cin >> s;
    cout << s << endl;

    cout << "c_str() = " << s.c_str() << endl;
    cout << "data() = " << s.data() << endl;

    cout << "Enter num chars to copy from string : ";
    size_t n;
    cin >> n;
    n = std::min(s.size(), n);
    char *buf = new char[n + 1];
    s.copy(buf, n);
    buf[n] = '\0';
    cout << "copy() = " << buf << endl;
    delete buf;

    cout << "Test end" << endl;
}

int
main() {
    Str s;
    test(s);
    test(s);
    test(s);
    return 0;
}
