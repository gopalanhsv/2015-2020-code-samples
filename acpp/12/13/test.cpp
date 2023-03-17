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
    Vec<int> ov;
    copy(istream_iterator<int>(cin),
        istream_iterator<int>(), back_inserter(ov));
    cout << endl << "Displaying old vec " << endl;
    copy(ov.begin(), ov.end(), ostream_iterator<int>(cout," "));

    cin.clear();
    Vec<int> nv;
    copy(istream_iterator<int>(cin),
        istream_iterator<int>(), back_inserter(nv));
    cout << endl << "Displaying new vec " << endl;
    copy(nv.begin(), nv.end(), ostream_iterator<int>(cout," "));

    cout << endl << "Assigning new vec to old vec" << endl;
    ov.assign(nv.begin(), nv.end());
    cout << endl << "Displaying old vec " << endl;
    copy(ov.begin(), ov.end(), ostream_iterator<int>(cout," "));
    cout << endl << "Displaying new vec " << endl;
    copy(nv.begin(), nv.end(), ostream_iterator<int>(cout," "));

    cout << endl << "Test end" << endl;
}

void
testList() {
    cout << "Test start" << endl;

    cout << "Enter strings followed by Ctrl-D" << endl;
    std::list<Str> ol;
    copy(istream_iterator<Str>(cin),
        istream_iterator<Str>(), back_inserter(ol));
    cout << endl << "Displaying old list " << endl;
    copy(ol.begin(), ol.end(), ostream_iterator<Str>(cout," "));

    cout << endl << "Enter strings followed by Ctrl-D" << endl;
    cin.clear();
    Vec<Str> nv;
    copy(istream_iterator<Str>(cin),
        istream_iterator<Str>(), back_inserter(nv));
    cout << endl << "Displaying new vec " << endl;
    copy(nv.begin(), nv.end(), ostream_iterator<Str>(cout," "));

    cout << endl << "Assigning old list to new vec" << endl;
    nv.assign(ol.begin(), ol.end());
    cout << endl << "Displaying old list " << endl;
    copy(ol.begin(), ol.end(), ostream_iterator<Str>(cout," "));
    cout << endl << "Displaying new vec " << endl;
    copy(nv.begin(), nv.end(), ostream_iterator<Str>(cout," "));

    cout << endl << "Test end" << endl;
}

int
main() {
    //testVec();
    testList();
    return 0;
}
