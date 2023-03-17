// System headers
#include <iostream>
#include <stdexcept>
#include <iterator>
#include <string>
#include <vector>
#include <algorithm>

// Local includes
#include "expression.h"

// Using declarations
using std::domain_error;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::ostream_iterator;
using std::copy;

// Statics, typedefs, globals

void
printVecOfVec(const vector<long>& v) {
    cout << endl;
    copy(v.begin(), v.end(), ostream_iterator<long>(cout, ", "));
    cout << endl;
}

void
test() {
    while (true) {
        cout << "Enter expression string to be evaluated : ";
        string expr;
        if (cin >> expr) {
            try {
                vector<long> ov =
                    Expression::computeAllPossibleOutputs(expr);
                    //Expression::computeAllPossibleOutputsDP(expr);
                cout << endl;
                cout << "Possible outputs of expression " << expr << " are :";
                printVecOfVec(ov);
            } catch (domain_error& e) {
                throw e;
            }
        } else {
            cin.clear();
            cin.ignore(10000, '\n');
            break;
        }
    }
}

int
main() {
    try {
        test();
    } catch(domain_error& e) {
        cout << e.what() << endl;
        return 1;
    }
    return 0;
}
