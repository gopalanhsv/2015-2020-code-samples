// System headers
#include <iostream>
#include <string>
#include <algorithm>

// Local includes
#include "lpsLen.h"

// Using declarations
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::domain_error;
using std::max;

// Statics, typedefs, globals
typedef string::size_type strSzT;

void
test() {
    while (true) {
        string s;
        cout << endl << "Enter string s1 : ";
        while (!(cin >> s));

        try {
            strSzT l = lpsLenBruteForce(s);
            cout << "Longest palindromic subsequence length of "
                << "string " << s
                << " via brute force is " << l << endl;
        } catch (domain_error& e) {
            throw e;
        }

        try {
            strSzT l = lpsLenDpMemoization(s);
            cout << "Longest palindromic subsequence length of "
                << "string " << s
                << " via dp memoization is " << l << endl;
        } catch (domain_error& e) {
            throw e;
        }

        try {
            strSzT l = lpsLenDpTabulation(s);
            cout << "Longest palindromic subsequence length of "
                << "string " << s
                << " via dp tabulation is " << l << endl;
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
