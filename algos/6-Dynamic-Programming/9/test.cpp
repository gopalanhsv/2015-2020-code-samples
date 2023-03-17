// System headers
#include <iostream>
#include <string>
#include <stdexcept>

// Local includes
#include "stringInterleaved.h"

// Using declarations
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::domain_error;

// Statics, globals, typedefs

void
test() {
    while (cin) {
        string s1, s2, s3;
        cout << "Enter component string #1 : ";
        cin >> s1;
        cout << "Enter component string #2 : ";
        cin >> s2;
        cout << "Enter string which is supposed to be "
            " interleaved from strings #1 & #2 : ";
        cin >> s3;

        try {
            bool x = isStringFormedByInterleavingBruteForce(s1, s2, s3);
            cout << "String " << s3 << " is "
                << ((x) ? "" : "not ") << "formed from strings "
                << s1 << " and " << s2
                << " via brute force algorithm" << endl;
        } catch (domain_error& e) {
            throw e;
        }

        try {
            bool x = isStringFormedByInterleavingDPMemoization(s1, s2, s3);
            cout << "String " << s3 << " is "
                << ((x) ? "" : "not ") << "formed from strings "
                << s1 << " and " << s2
                << " via DP memoization algorithm" << endl;
        } catch (domain_error& e) {
            throw e;
        }

        try {
            bool x = isStringFormedByInterleavingDPTabulation(s1, s2, s3);
            cout << "String " << s3 << " is "
                << ((x) ? "" : "not ") << "formed from strings "
                << s1 << " and " << s2
                << " via DP Tabulation algorithm" << endl;
        } catch (domain_error& e) {
            throw e;
        }

        try {
            bool x = isStringFormedByInterleavingDPOptimized(s1, s2, s3);
            cout << "String " << s3 << " is "
                << ((x) ? "" : "not ") << "formed from strings "
                << s1 << " and " << s2
                << " via DP optimized algorithm" << endl;
        } catch (domain_error& e) {
            throw e;
        }
    }
}

int
main() {
    try {
        test();
        return 0;
    } catch (domain_error& e) {
        cout << e.what() << endl;
    }
    return 0;
}


