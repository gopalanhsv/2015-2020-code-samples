// System headers
#include <iostream>

// Local includes

// Using declarations
using std::cout;
using std::endl;

// Typedefs, etc

int
main(int argc, char **argv) {
    if (argc > 1) {
        cout << argv[1];
        for (int i = 2; i != argc; ++i) {
            cout << " " << argv[i];
        }
    } else {
        cout << "No args supplied";
    }
    cout << endl;
    return 0;
}
