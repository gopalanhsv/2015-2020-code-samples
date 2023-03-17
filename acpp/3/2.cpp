#include <iostream>
#include <vector>
#include <algorithm>

// Using declarations
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::sort;

int
main() {
    
    
    // Read and store the numbers into a vector
    vector<int> numbers;
    int x;
    // Invariant: numbers contains all numbers read so far
    while (cin >> x) {
        numbers.push_back(x);
    }

    // Separate input from output
    cout << endl;

    // Check that the vector is populated
    if (!numbers.size()) {
        cout << "Error! No numbers entered! Exiting...!" << endl;
        return 1;
    }

    // Sort the vector of numbers in non decreasing order
    sort(numbers.begin(), numbers.end());

    // Compute quartiles
    typedef vector<int>::size_type vecSzT;

    return 0;
}
