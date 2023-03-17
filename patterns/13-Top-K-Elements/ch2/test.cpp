// System headers
#include <iostream>
#include <stdexcept>
#include <vector>
#include <iterator>
#include <algorithm>

// Local includes
#include "tasks.h"

// Using declarations
using std::cin;
using std::cout;
using std::endl;
using std::domain_error;
using std::copy;
using std::istream_iterator;
using std::ostream_iterator;
using std::back_inserter;
using std::vector;

// Statics, typedefs, globals

void
readVec(vector<char>& v) {
    v.clear();
    copy(istream_iterator<char>(cin),
        istream_iterator<char>(), back_inserter(v));
    cin.clear();
    cin.ignore(1000, '\n');
}

void
printVec(const vector<char>& v) {
    cout << endl;
    for (auto t : v) {
        if (t == '!') {
            cout << "idle->";
        } else {
            cout << t << "->";
        }
    }
    cout << endl;
}

void
test() {
    cout << "Enter tasks to be scheduled :";
    vector<char> tv;
    readVec(tv);
    cout << "Input tasks are : ";
    printVec(tv);

    unsigned long md;
    while (true) {
        cout << "Enter min distance between same tasks for scheduling : ";
        if (cin >> md) {
            break;
        }
        cin.clear();
        cin.ignore(1000, '\n');
        cout << endl << "Try again!!!" << endl;
    }

    try {
        tv = TaskScheduler::schedule(tv, md);
        cout << "Task after scheduling require "
            << tv.size() << " intervals!" << endl;
        cout << "Scheduling order is ";
        printVec(tv);
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
