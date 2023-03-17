// System headers
#include <iostream>
#include <string>
#include <cstddef>

// Local includes

// Using declarations
using std::string;
using std::cin;
using std::cout;
using std::endl;

// Typedefs etc

size_t
strLen(const char *s) {
    size_t l = 0;
    while (*s++ != '\0') {
        ++l;
    }
    return l;
}

int
main() {
    cout << "Enter a string : ";
    string x;
    while (getline(cin, x)) {
        cout << "String len is " << strLen(x.c_str()) << endl;
        cout << "Enter a string : ";
    }
    return 0;
}
