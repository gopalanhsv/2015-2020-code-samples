// System headers
#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>

// Local includes
#include "Vec.h"

// Using declarations
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::istream_iterator;
using std::ostream_iterator;
using std::back_inserter;
using std::copy;

void
test() {
    cout << "Test start" << endl;

    string s;
    cout << "Enter string : " << endl;
    getline(cin, s);

    cout << endl << "Displaying string" << endl;
    cout << s << endl;

    cout << endl << "Initializing Vec from a string" << endl;
    Vec<string::value_type> v(s.begin(), s.end());

    cout << endl << "Displaying Vec " << endl;
    copy(v.begin(), v.end(), ostream_iterator<string::value_type>(cout,""));

    cout << endl << "Test end" << endl;
}

int
main() {
    test();
    return 0;
}
