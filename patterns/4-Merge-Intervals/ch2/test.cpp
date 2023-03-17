// System headers
#include <vector>
#include <iostream>
#include <stdexcept>

// Local includes
#include "cpuLoad.h"

// Using declarations
using std::vector;
using std::domain_error;
using std::cin;
using std::cout;
using std::endl;

// Statics, globals, typedefs

void
readVec(vector<Job>& v) {
    v.clear();
    cout << "Enter number of jobs : ";
    int n;
    cin >> n;
    while (n--) {
        int s, e, l;
        cout << endl << "Enter job start time : ";
        while (!(cin >> s));
        cout << endl << "Enter job end time : ";
        while (!(cin >> e));
        cout << endl << "Enter job cpu load : ";
        while (!(cin >> l));
        v.push_back({s, e, l});
    }
}

void
printVec(const vector<Job>& jv) {
    cout << endl;
    for (auto j : jv) {
        cout << "[ " << j.start() << ", " << j.end() <<
            ", " << j.load() << "] " << endl;
    }
    cout << endl;
}

void
testFn() {
    vector<Job> jv;
    readVec(jv);
    cout << "Input jobs are : ";
    printVec(jv);
    int maxLoad = Cpu::computeMaxLoadForJobs(jv);
    cout << "Max load on CPU is " << maxLoad << endl;
}

int
main() {
    try {
        testFn();
    } catch (domain_error& e) {
        cout << e.what() << endl;
        return 1;
    }
    return 0;
}
