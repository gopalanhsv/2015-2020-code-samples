#include <iostream>
#include <iomanip>
#include <ios>

using std::cout;
using std::cin;
using std::endl;
using std::setw;
using std::setprecision;
using std::streamsize;

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
computeFieldWidth(const unsigned long nDigits, const unsigned int prec,
    unsigned long& nw, unsigned long & n2w) {
    // 2 additional spaces + 1 decimal point + prec digits to rt of decimal
    nw = nDigits + 2 + 1 + prec;
    // 2 additional spaces + 1 decimal point + prec digits to rt of decimal
    n2w = nDigits * 2 + 2 + 1 + prec;
}

int
main() {
    // Read the number till which squares have to be computed
    cout << "Pls enter the max number for the range [1...n] :";
    double n;
    cin >> n;

    // Get the num of digits in number n.
    unsigned long nd = nDigits(n);

    // Get the the display width for priting number and its squares
    unsigned long nwidth, n2width;
    // Fixed precision width set to 2 (i.e. only 2 digit to right
    // of decimal point)
    const unsigned long prec = 2;
    computeFieldWidth(nd, prec, nwidth, n2width);

    // Separate input and output
    cout << endl;
    for (double i = 0; i != n + 1; ++i) {
        double i2 = i * i; 
        cout << setprecision(prec) << std::fixed;
        cout << setw(nwidth) << i << setw(n2width) << i2 << endl;
    }
    return 0;
}
