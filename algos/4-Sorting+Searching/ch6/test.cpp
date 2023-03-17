// System headers
#include <vector>
#include <iostream>
#include <iterator>
#include <stdexcept>
#include <algorithm>

// Local includes
#include "searchInSortedMatrix.h"

// Using declaration
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::istream_iterator;
using std::ostream_iterator;
using std::copy;
using std::domain_error;

// Statics, globals, typedefs

void
readInputMatrix(vector<vector<int> >& matrix) {
    matrix.clear();
    int r, c;
    cout << "Enter num rows of matrix : ";
    cin >> r;
    cout << endl;
    cout << "Enter num cols of matrix : ";
    cin >> c;
    cout << endl;
    cout << "Enter matrix elements : " << endl;
    for (int i = 0; i != r; ++i) {
        cout << "Enter row " << i + 1 << " elements : " << endl;
        vector<int> rowElements;
        for (int j = 0; j != c; ++j) {
            int x;
            cin >> x;
            rowElements.push_back(x);
        }
        matrix.push_back(rowElements);
    }
}

void
printMatrix(const vector<vector<int> >& matrix) {
    cout << endl;
    for (vector<vector<int> >::size_type r = 0; r != matrix.size(); ++r) {
        cout << "Row " << r + 1 << " : ";
        copy(matrix[r].begin(),
            matrix[r].end(), ostream_iterator<int>(cout, ", "));
        cout << endl;
    }
    cout << endl;
}

void
testFn() {
    try {
        vector<vector<int> > v;
        readInputMatrix(v);
        cout << "Read matrix is : ";
        printMatrix(v);

        int key;
        cout << "Enter the key to be searched for : ";
        cin >> key;

        bool found = searchSortedMatrix(v, key);
        cout << "Key " << key <<
            ((found) ? " " : " not ") << "found!" << endl;
    } catch (domain_error e) {
        cout << e.what() << endl;
    }
}

int
main() {
    testFn();
    return 0;
}

