// System headers
#include <vector>
#include <stdexcept>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <string>

// Local includes
#include "fractionalKnapsack.h"

// Using declarations
using std::vector;
using std::domain_error;
using std::cin;
using std::cout;
using std::endl;
using std::ostream_iterator;
using std::istream_iterator;
using std::back_inserter;
using std::copy;
using std::string;

// Statics, typedefs, globals

void
readVec(vector<int>& v) {
    v.clear();
    copy(istream_iterator<int>(cin), istream_iterator<int>(), back_inserter(v));
    cin.clear();
}

void
printVec(const vector<int>& v, const string& sep) {
    cout << endl;
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, sep.c_str()));
    cout << endl;
}

void
testFn() {
    int c;
    cout << "Enter knapsack capacity : ";
    cin >> c;
    vector<int> iVal, iWt;
    cout << "Enter item values : ";
    readVec(iVal);
    cout << "Enter item weights : ";
    readVec(iWt);
    cout << "Item values are : ";
    printVec(iVal, " ");
    cout << "Item weights are : ";
    printVec(iWt, " ");

    try {
        vector<ItemT> iv = constructConsolidatedItemVec(iVal, iWt);
        double mVal = maxValueOfFractionalKnapsack(c, iv);
        cout << "Max value of knapsack with given item is " << mVal << endl;
    } catch (domain_error& e) {
        throw e;
    }
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
