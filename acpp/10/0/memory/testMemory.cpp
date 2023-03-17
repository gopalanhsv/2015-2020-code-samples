// System headers
#include <iostream>
#include <string>
#include <algorithm>

// Local includes

// Using declarations
using std::cin;
using std::cout;
using std::endl;
using std::hex;
using std::dec;
using std::string;
using std::copy;

int*
pointer_to_local() {
    int x = 50;
    return &x;
}

int*
pointer_to_static() {
    static int x = 100;
    return &x;
}

int*
pointer_to_dynamic() {
    int *x = new int(2000);
    return x;
}

size_t
strlen(const char *s) {
    size_t l = 0;
    while (*s++ != '\0')
        ++l;
    return l;
}

char*
copyString(const char* s) {
    size_t len = strlen(s) + 1;
    char *nStr = new char[len];
    copy(s, s + len, nStr);
    return nStr;
}

int
main(int argc, char **argv) {
    int *var; // = pointer_to_local();
    cout << "Local Var x at " << hex << var <<
        dec << " : Val is " << *var << endl;

    var = pointer_to_static();
    cout << "Static Var x at " << hex << var <<
        dec << " : Val is " << *var << endl;

    var = pointer_to_dynamic();
    cout << "Dynamic Var x at " << hex << var <<
        dec << " : Val is " << *var << endl;

    if (argc > 1) {    
        for (int i = 1; i != argc; ++i) {
            cout << copyString(argv[i]) << endl;
        }
    }

    return 0;
}
