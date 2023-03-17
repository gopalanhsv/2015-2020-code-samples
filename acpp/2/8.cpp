#include <iostream>

using std::cout;
using std::endl;

int
main() {
    int prod = 1;
    for (int i = 1; i != 10; ++i) {
        prod *= i;
    }
    cout << "Product of numbers in the range [1, 10) is " << prod << endl;
    return 0;
}
