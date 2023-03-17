// System headers
#include <iostream>
#include <vector>
#include <stdexcept>
#include <iterator>
#include <algorithm>
#include <string>

// Local includes
#include "fruits2Baskets.h"

// Using declarations
using std::vector;
using std::string;
using std::domain_error;
using std::cin;
using std::cout;
using std::endl;
using std::istream_iterator;
using std::ostream_iterator;
using std::back_inserter;
using std::copy;

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
    copy(v.begin(), v.end(), ostream_iterator<char>(cout, " "));
    cout << endl;
}

template<typename T>
T
readInput(const string& s) {
    T x;
    while (1) {
        cout << s;
        if (cin >> x) {
            break;
        }
        cin.clear();
        cin.ignore(1000, '\n');
        cout << endl << "Try again !!!" << endl;
    }
    return x;
}

void
test() {
    cout << "Enter input array of fruits : ";
    vector<char> fv;
    readVec(fv);
    cout << "Input array of fruits is : ";
    printVec(fv);

    unsigned nb = readInput<unsigned>("Enter number of baskets : ");

    try {
        unsigned maxf = FruitsToBaskets::maxContiguousFruitsToBaskets(fv, nb);
        cout << "Maximum of " << maxf << " contiguous fruits can be filled in "
            << nb << " baskets" << endl;
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
