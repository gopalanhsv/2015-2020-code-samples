// System headers
#include <limits>
#include <iostream>
#include <cctype>

// Local includes

// Using declarations
using std::cout;
using std::cin;
using std::endl;
using std::size_t;

// Statics, globals, typedefs


long long
maxIndex(long arr[], size_t arrSz) {
    long max = std::numeric_limits<long>::min();
    long long idx = -1;
    for (size_t i = 0; i != arrSz; ++i) {
        if (arr[i] > max) {
            idx = i;
            max = arr[i];
        }
    }
    return idx;
}

long long
minIndex(long arr[], size_t arrSz) {
    long min = std::numeric_limits<long>::max();
    long long idx = -1;
    for (size_t i = 0; i != arrSz; ++i) {
        if (arr[i] < min) {
            idx = i;
            min = arr[i];
        }
    }
    return idx;
}

long long
linearSearch(long arr[], size_t arrSz, long numToFind) {
    long long idx = -1;
    for (size_t i = 0; i != arrSz; ++i) {
        if (arr[i] == numToFind) {
            idx = i;
            break;
        }
    }
    return idx;
}

int
main() {
    long a[] = { 2, 4, 6, 3, 5, 7, 9, 1, 8 };
    size_t arrSz = sizeof(a) / sizeof(a[0]);
    

    cout << "Max Num in array is = " << a[maxIndex(a, arrSz)] << endl;
    cout << "Min Num in array is = " << a[minIndex(a, arrSz)] << endl;

    long x;
    
    while (cin >> x) {
        long long i = linearSearch(a, arrSz, x);
        if (i < 0) {
            cout << "Number " << x << " not found" << endl;
        } else {
            cout << "Number " << x << " at index = " << i << endl;
        }
    }

    return 0;
}
