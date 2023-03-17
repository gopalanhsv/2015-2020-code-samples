// System headers
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <iterator>

// Local includes
#include "split.h"

// Using declarations
using std::string;
using std::list;
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::ostream_iterator;
using std::back_inserter;

int
main() {
    string line;

    // TEST 1
    cout << "TEST#1" << endl;
    while (getline(cin, line)) {
        split(line, ostream_iterator<string>(cout, "\n"));
    }
    cin.clear();
    cout << endl;

    // TEST 2
    cout << "TEST#2" << endl;
    while (getline(cin, line)) {
        vector<string> vs;
        split(line, back_inserter(vs));
        copy(vs.begin(), vs.end(), ostream_iterator<string>(cout, "\n"));
    }
    cin.clear();
    cout << endl;

    // TEST 3
    cout << "TEST#3" << endl;
    while (getline(cin, line)) {
        list<string> ls;
        split(line, back_inserter(ls));
        copy(ls.begin(), ls.end(), ostream_iterator<string>(cout, "\n"));
    }
    cout << endl;
}
