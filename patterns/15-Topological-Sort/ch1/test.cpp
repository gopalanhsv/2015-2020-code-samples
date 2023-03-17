// System headers
#include <iostream>
#include <stdexcept>
#include <vector>
#include <iterator>
#include <algorithm>
#include <string>

// Local includes
#include "reconstructSequence.h"

// Using declarations
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::istream_iterator;
using std::ostream_iterator;
using std::back_inserter;
using std::domain_error;
using std::copy;

// Statics, typedefs, globals

void
readVec(vector<int>& v) {
    v.clear();
    copy(istream_iterator<int>(cin),
        istream_iterator<int>(), back_inserter(v));
    cin.clear();
    cin.ignore(1000, '\n');
}

void
printVec(const vector<int>& v) {
    cout << "[ ";
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, ", "));
    cout << "]";
}

void
printVecOfVec(const vector<vector<int> >& vOfV) {
    cout << endl;
    for (auto v : vOfV) {
        printVec(v);
        cout << ", ";
    }
    cout << endl;
}

int
readNum(const string& s) {
    while (1) {
        cout << s;
        int x;
        if (cin >> x) {
            return x;
        } else {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << endl << "Try again!!!" << endl;
        }
    }
}

void
test() {
    cout << "Enter reconstructed sequence : ";
    vector<int> rs;
    readVec(rs);

    unsigned n = readNum(
        "Enter number of subsequences for reconstructing sequence : ");
    vector<vector<int> > subSeqV;
    while (n--) {
        cout << endl << "Enter subsequence : ";
        vector<int> v;
        readVec(v);
        subSeqV.push_back(v);
    }

    cout << endl << "Original reconstructed sequence is : ";
    printVec(rs);
    cout << endl;
    cout << "Subsequences are : ";
    printVecOfVec(subSeqV);

    try {
        bool x = Sequence::isSoleSequenceOfSubsequences(rs, subSeqV);
        cout << "Original sequence "
            << ((x) ? "can" : "cannot")
            << " be reconstructed from given subsequences" << endl;
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
