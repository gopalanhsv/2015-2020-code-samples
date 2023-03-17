// System includes
#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>

// Local includes

// Using declarations
using std::vector;
using std::copy;
using std::cout;
using std::endl;

int
main() {
    vector<int> u(10, 100);
    vector<int> v;
    copy(u.begin(), u.end(), back_inserter(v));
    for (vector<int>::size_type i = 0; i != v.size(); ++i)
        cout << v[i] << endl;
    return 0;
}
