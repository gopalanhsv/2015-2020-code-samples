#include <iostream>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;
using std::setw;

unsigned long
nDigits(unsigned long n) {
    unsigned int i = 0;
    while (n) {
        n = n / 10;
        ++i;
    }
    return i;
}

void
computeFieldWidth(const unsigned long nDigits,
    unsigned long& nw, unsigned long & n2w) {
    nw = nDigits + 2;
    n2w = nDigits * 2 + 2;
}

int
main() {
    // Read the number till which squares have to be computed
    cout << "Pls enter the max number for the range [1...n] :";
    unsigned long n;
    cin >> n;

    // Get the num of digits in number n.
    unsigned long nd= nDigits(n);

    // Get the the display width for priting number and its squares
    unsigned long nwidth, n2width;
    computeFieldWidth(nd, nwidth, n2width);

    // Separate input and output
    cout << endl;
    for (unsigned long i = 0; i != n + 1; ++i) {
        unsigned long long i2 = i * i; 
        cout << setw(nwidth) << i << setw(n2width) << i2 << endl;
    }
    return 0;
}
