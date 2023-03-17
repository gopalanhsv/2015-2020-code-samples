// System headers
#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <string>
#include <stdexcept>

// Local includes
#include "sortAlgos.h"

// Using declaration
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::istream_iterator;
using std::ostream_iterator;
using std::copy;
using std::sort;
using std::string;
using std::domain_error;

// Statics, globals, typedefs

void
readInputVec(vector<int>& v) {
    v.clear();
    cout << "Enter elements to be sorted : " << endl;
    copy(
        istream_iterator<int>(cin), istream_iterator<int>(), back_inserter(v));
    cin.clear();
}

void
printVec(const vector<int>& v) {
    cout << endl;
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
}

void
testSortTechnique(vector<int> v, const vector<int>& expectedResultVec,
    const string& s, void sortFn(vector<int>&)) {

    try {
        sortFn(v);
        cout << "Sorted vector after " << s << " is : ";
        printVec(v);

        cout << "Hand written " << s << " and std::sort results ";
        cout << ((v != expectedResultVec) ? "differ!" : "are same!") << endl;
        
    } catch (domain_error e) {
        cout << e.what() << endl;
    }
}

void
testSortAlgos() {
    vector<int> v, expectedResultVec;
    readInputVec(v);
    cout << "Read input vector is : ";
    printVec(v);

    expectedResultVec = v;
    sort(expectedResultVec.begin(), expectedResultVec.end());

    testSortTechnique(v, expectedResultVec, "insertion sort", insertionSort);
    testSortTechnique(v, expectedResultVec, "bubble sort", bubbleSort);
    testSortTechnique(v, expectedResultVec, "selection sort", selectionSort);
}

int
main() {
    testSortAlgos();
    return 0;
}

