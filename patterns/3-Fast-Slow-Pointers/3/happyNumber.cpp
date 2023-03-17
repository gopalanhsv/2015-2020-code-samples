// System headers

// Local includes
#include "happyNumber.h"

// Using declarations

// Statics, typedefs, globals

bool
Number::isHappyNumber(unsigned int n) {
    // Have 2 numbers slow and fast initialized to given number
    unsigned long slowNum = n;
    unsigned long fastNum = n;

    // The fast number computes the sum of squares of digits at 2x
    // the speed of the slow number. Do this till slow and fast
    // numbers converge and cycle there
    do {
        // Compute the square of sum of digits once for slow number
        slowNum = sumOfDigitsSquared(slowNum);
        // Compute the square of sum of digits twice for fast number
        fastNum = sumOfDigitsSquared(fastNum);
        fastNum = sumOfDigitsSquared(fastNum);
    } while (slowNum != fastNum);

    // If number is happy, slow and fast numbers converge to 1
    if (slowNum == 1) {
        return true;
    }

    return false;
}

unsigned long
Number::sumOfDigitsSquared(unsigned long n) {
    unsigned long sum = 0;
    while (n) {
        unsigned long d = n % 10;
        sum += d * d;
        n = n / 10;
    }
    return sum;
}
