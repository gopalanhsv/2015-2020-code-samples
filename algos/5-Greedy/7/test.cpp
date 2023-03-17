// System headers
#include <iostream>
#include <stdexcept>

// Local includes
#include "findLargestNumber.h"

// Using declarations
using std::domain_error;
using std::cin;
using std::cout;
using std::endl;

// Statics, globals, typedefs

void
testFn() {
    while (true) {
        int nd, sd;
        cout << endl << "Enter number of digits : ";
        cin >> nd;
        cout << endl << "Enter sum of digits : ";
        cin >> sd;
        try {
            //int num = findLargestNumUsingGreedyMethod(nd, sd);
            int num = findLargestNumUsingBruteForce(nd, sd);
            cout << endl << "Number is " << num;
        } catch (domain_error& e) {
            throw e;
        }
    }
}

int
main() {
    try {
        testFn();
    } catch (domain_error& e) {
        cout << e.what() << endl;
        return 1;
    }
    return 0;
}
