// System headers
#include <iostream>
#include <string>

// Local includes
#include "scsLen.h"

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
        cout << endl << "Enter string s1 : ";
        while (!(cin >> s));
        cout << endl << "Enter string s2 : ";
        while (!(cin >> t));

        try {
            strSzT l = scsLenBruteForce(s, t);
            cout << "Shortest common supersequence len between "
                << "string " << s << " & string " << t
                << " via brute force is " << l << endl;
        } catch (domain_error& e) {
            throw e;
        }

        try {
            strSzT l = scsLenDPMemoization(s, t);
            cout << "Shortest common supersequence len between "
                << "string " << s << " & string " << t
                << " via dp memoization is " << l << endl;
        } catch (domain_error& e) {
            throw e;
        }

        try {
            strSzT l = scsLenDPTabulation(s, t);
            cout << "Shortest common supersequence len between "
                << "string " << s << " & string " << t
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
