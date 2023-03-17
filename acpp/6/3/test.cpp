// System includes
#include <vector>
#include <iostream>
#include <algorithm>

// Local includes

// Using declarations
using std::vector;
using std::copy;

int
main() {
    vector<int> u(10, 100);
    vector<int> v;
    copy(u.begin(), u.end(), v.begin());
    return 0;
}
