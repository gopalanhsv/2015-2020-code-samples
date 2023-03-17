// System headers
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <utility>
#include <iterator>
#include <algorithm>

// Local includes
#include "scheduleAllTasks.h"

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
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
}

void
printVecOfVec(const vector<vector<unsigned> >& vOfV) {
    cout << endl;
    for (auto v : vOfV) {
        printVec(v);
        cout << endl;
    }
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
        vector<vector<unsigned> >  allOrderedTasksV =
            TaskScheduler::scheduleAllTasks(nt, preReqV);
        if (allOrderedTasksV.empty()) {
            cout << "Task scheduling not possible due to cyclic dependency"
                <<  " of prerequisites!" << endl;
        } else {
            cout << "All tasks schedule order as per prerequisites : ";
            printVecOfVec(allOrderedTasksV);
        }
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
