// System headers
#include <iostream>
#include <string>

// Local includes
#include "minEditDistance.h"

// Using declarations
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::domain_error;

// Statics, typedefs, globals
typedef string::size_type strSzT;

void
test() {
    while (true) {
        string s, t;
        cout << endl << "Enter source string : ";
        while (!(cin >> s));
        cout << endl << "Enter target string : ";
        while (!(cin >> t));

        try {
            strSzT d = minEditDistanceBruteForce(s, t);
            cout << "Min edit distance to convert source " << s
                << " to target " << t << " via "
                << "brute force is " << d << endl;
        } catch (domain_error& e) {
            throw e;
        }

        try {
            strSzT d = minEditDistanceDPMemoization(s, t);
            cout << "Min edit distance to convert source " << s
                << " to target " << t << " via "
                << "dp memoization is " << d << endl;
        } catch (domain_error& e) {
            throw e;
        }

        try {
            strSzT d = minEditDistanceDPTabulation(s, t);
            cout << "Min edit distance to convert source " << s
                << " to target " << t << " via "
                << "dp tabulation is " << d << endl;
        } catch (domain_error& e) {
            throw e;
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
