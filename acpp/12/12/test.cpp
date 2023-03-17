// System headers
#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>

// Local includes
#include "Str.h"

// Using declarations
using std::cin;
using std::cout;
using std::endl;
using std::list;
using std::istream_iterator;
using std::ostream_iterator;
using std::back_inserter;
using std::copy;

void
testVec() {
    cout << "Test start" << endl;

    cout << "Enter integers followed by Ctrl-D" << endl;
    Vec<int> v;
    copy(istream_iterator<int>(cin),
        istream_iterator<int>(), back_inserter(v));

    Vec<int> nv;
    nv.insert(nv.begin(), v.begin(), v.end());
    cout << "Displaying new vec" << endl;
    copy(nv.begin(), nv.end(), ostream_iterator<int>(cout," "));

    cout << "Test end" << endl;
}

void
testStr() {
    cout << "Test start" << endl;

    cout << "Enter a new string to insert : ";
    Str s;
    cin >> s;
    cout << " Entered new string is : " << s << endl;

    Str os = "We willy winky who is a donkey?";
    cout << "Enter position [0 - " << os.size() << "]"
        << "in below string to insert new string ? " << endl;
    cout << os << endl;
    Str::size_type i;
    cin >> i;

    i = std::min(i, os.size());
    os.insert(os.begin() + i, s.begin(), s.end());
    cout << "New string after insertion is : " << endl;
    cout << os << endl;

    cout << "Test end" << endl;
}

int
main() {
    //testVec();
    testStr();
    return 0;
}
