#include <iostream>
#include <iomanip>

using std::cout;
using std::endl;
using std::setw;

int
main() {
    const unsigned long nwidth = 3 + 2; // 100 i.e 3 chars
    const unsigned long n2width = 5 + 2; // 100 * 100 = 10000 i.e 5 chars
    cout << endl;
    for (int i = 0; i != 101; ++i) {
        cout << setw(nwidth) << i << setw(n2width) << i * i << endl;
    }
    return 0;
}
