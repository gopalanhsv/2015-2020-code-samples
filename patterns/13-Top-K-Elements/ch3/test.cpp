// System headers
#include <iostream>
#include <stdexcept>

// Local includes
#include "frequencyStk.h"

// Using declarations
using std::cin;
using std::cout;
using std::endl;
using std::runtime_error;

// Statics, typedefs and globals

void
pushElementProcess(FrequencyStack& fs) {
    while (true) {
        int e;
        cout << "Enter element to be pushed : ";
        if (cin >> e) {
            fs.push(e);
            break;
        } else {
            cout << "Try again!!!" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }
    }
}

void
popElementProcess(FrequencyStack& fs) {
    if (fs.empty()) {
        cout << "Empty stack!" << endl;
    } else {
        cout << "Popped element is " << fs.pop() << endl;
    }
}

void
test() {
    FrequencyStack fs;
    while (true) {
        unsigned int opt;
        cout << "Enter 1 to push element/2 to pop element/other to quit" << endl;
        if (cin >> opt) {
            try {
                switch (opt) {
                    case 1:
                        pushElementProcess(fs);
                        break;
                    case 2:
                        popElementProcess(fs);
                        break;
                    default:
                        cout << "Exiting!!!" << endl;
                        return;
                }
            } catch (runtime_error& e) {
                throw e;
            }
        } else {
            cin.clear();
            cin.ignore(1000, '\n');
            break;
        }
    }
}

int
main() {
    try {
        test();
    } catch (runtime_error& e) {
        cout << e.what() << endl;
        return 1;
    }
}
