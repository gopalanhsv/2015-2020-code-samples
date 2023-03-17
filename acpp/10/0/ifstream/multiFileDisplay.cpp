// System headers
#include <iostream>
#include <fstream>
#include <string>

// Local includes

// Using declarations
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::ifstream;

// Typedefs

int
main(int argc, char **argv) {
    int failCnt = 0;
    if (argc > 1) {
        for (int i = 1; i != argc; ++i) {
            ifstream in(argv[i]);
            if (in) {
                cout << "FILE " << argv[i] << endl;
                string line;
                while (getline(in, line)) {
                    cout << line << "\n";
                }
            } else {
                cerr << "Unable to open " << argv[i] << endl;
                ++failCnt;
            }
        }
    }
    return failCnt;
}
