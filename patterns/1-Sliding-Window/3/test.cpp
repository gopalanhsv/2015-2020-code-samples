// System headers
#include <vector>
#include <stdexcept>
#include <iterator>
#include <algorithm>
#include <iostream>
#include <string>

// Local includes
#include "locString.h"

// Using declarations
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::domain_error;
using std::istream_iterator;
using std::ostream_iterator;
using std::back_inserter;
using std::copy;
using std::string;

// Statics, typedefs, globals

template<typename T>
T
readInput(const std::string& s) {
    T x;
    while (1) {
        cout << s;
        if (cin >> x) {
            break;
        }
        cin.clear();
        cin.ignore(1000, '\n');
        cout << endl << "Try again!!!" << endl;
    }
    return x;
}

void
test() {
    string s = readInput<string>("Enter input string : ");

    unsigned k =
        readInput<unsigned>("Enter num distinct chars in substring : ");
    try {
        unsigned l = String::longestSubStrLenWithKDistinctChars(s, k);
        cout << " Longest substring of " << s << " with " << k
            << " distinct characters is of length " << l << endl;
    } catch (domain_error& e) {
        throw e;
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
