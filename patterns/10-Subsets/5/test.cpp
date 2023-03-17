// System headers
#include <vector>
#include <string>
#include <iostream>
#include <iterator>
#include <algorithm>

// Local includes
#include "paranthesis.h"

//  Using declarations
using std::vector;
using std::string;
using std::domain_error;
using std::cin;
using std::cout;
using std::endl;
using std::ostream_iterator;
using std::copy;

// Statics, globals, locals

void
printVec(const vector<string>& vs) {
    cout << endl;
    copy(vs.begin(), vs.end(), ostream_iterator<string>(cout, "\n"));
    cout << endl;
}

void
test() {
    while (true) {
        cout << "Enter number of paranthesis for which all balanced "
            << "permutations should be generated : ";
        int n;
        if (cin >> n) {
            vector<string> bpp =
                Permutations::generateBalancedParanthesisPairs(n);
            //vector<string> bpp =
            //    Permutations::generateBalancedParanthesisPairsViaRecursion(n);
            cout << "All balanced paranthesis combinations for " << n
                << " paranthesis are : ";
            printVec(bpp);
        } else {
            cin.clear();
            cin.ignore(100000, '\n');
            break;
        }
    }
}

int
main() {
    try {
        test();
    } catch (domain_error& e) {
        cout << e.what() << endl;
        return 1;
    }
    return 0;
}
