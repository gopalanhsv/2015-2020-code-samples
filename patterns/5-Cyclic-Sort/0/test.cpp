// System headers
#include <vector>
#include <stdexcept>
#include <iterator>
#include <algorithm>
#include <iostream>

// Local includes
#include "cyclicSort.h"

// Using declarations
using std::vector;
using std::domain_error;
using std::cin;
using std::cout;
using std::endl;
using std::istream_iterator;
using std::ostream_iterator;
using std::copy;

// Statics, globals, typedefs

void
printVec(const vector<int>& v) {
    cout << endl;
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, ", "));
    cout << endl;
}

void
readVec(vector<int>& v) {
    v.clear();
    cout << "Enter num elements : ";
    int n;
    cin >> n;
    cout << "Enter input vector [1, " << n << "] : ";
    int x;
    int c = n;
    while (c && cin >> x) {
        if (x > n || x <= 0) {
            cout << "Enter num in range [0, " << n << "]" << endl;
            continue;
        }
        --c;
        v.push_back(x);
    }
    cin.clear();
    if (v.size() != n) {
        throw domain_error("Error! All elements not entered!");
    }
}

void
test() {
    try {
        vector<int> v;
        readVec(v);
        cout << "Input vector is : ";
        printVec(v);
        CyclicSort::sort(v);
        cout << "Sorted vector is : ";
        printVec(v);
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
