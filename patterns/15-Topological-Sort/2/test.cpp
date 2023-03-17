// System headers
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <utility>
#include <iterator>
#include <algorithm>

// Local includes
#include "scheduleTasks.h"

// Using declarations
using std::cin;
using std::cout;
using std::endl;
using std::domain_error;
using std::vector;
using std::string;
using std::pair;
using std::make_pair;
using std::ostream_iterator;
using std::copy;

// Statics, typedefs, globals

void
printVec(const vector<unsigned>& v) {
    cout << endl;
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
}

unsigned
readNum(const string& s) {
    unsigned n;
    while (1) {
        cout << s;
        if (cin >> n) {
            break;
        }
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Try again!" << endl;
    }
    return n;
}

void
test() {
    unsigned nt = readNum("Enter num task : ");
    vector<pair<unsigned, unsigned> > preReqV;
    unsigned np = readNum("Enter num task prerequisites : ");
    for (unsigned i = 0; i != np; ++i) {
        cout << endl << i + 1 << "th prerequisite :" << endl;
        unsigned st = readNum("Enter source task : ");
        unsigned et = readNum("Enter end task : ");
        preReqV.push_back(make_pair(st, et));
    }

    try {
        bool b = TaskScheduler::schedulingPossible(nt, preReqV);
        cout << "Tasks scheduling " << (b ? "" : "not ") << "possible" << endl;
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
