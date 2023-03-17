// System headers
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <stdexcept>

// Local includes
#include "knapSack.h"

// Using declarations
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::domain_error;
using std::istream_iterator;
using std::ostream_iterator;
using std::back_inserter;
using std::copy;

// Statics, typedefs, globals

void
readVec(vector<int>& v) {
    v.clear();
    copy(istream_iterator<int>(cin), istream_iterator<int>(),
        back_inserter(v));
    cin.clear();
}

void
printVec(const vector<int>& v) {
    cout << endl;
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
}

void
testFn() {
    cout << "Enter knapsack capacity : ";
    int cap;
    cin >> cap;
    cout << "Enter array of item costs : ";
    vector<int> ic;
    readVec(ic);
    cout << endl << "Item costs :";
    printVec(ic);
    cout << "Enter array of item weights : ";
    vector<int> iw;
    readVec(iw);
    cout << endl << "Item weights :";
    printVec(iw);
    try {
        int val = maxValueOfknapsackRecursive(ic, iw, cap);
        cout << "Max val of knapsack via recursive method = ";
        cout << val << endl;
    } catch (domain_error& e) {
        throw e;
    }

    try {
        int val = maxValueOfknapsackRecursiveDPMemoization(ic, iw, cap);
        cout << "Max val of knapsack via recursive dp memoization method = ";
        cout << val << endl;
    } catch (domain_error& e) {
        throw e;
    }

    try {
        int val = maxValueOfknapsackRecursiveDPMemoization(ic, iw, cap);
        cout << "Max val of knapsack via dp tabulation method = ";
        cout << val << endl;
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
