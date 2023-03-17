// System headers
#include <stdexcept>
#include <cmath>

// Local includes

// Using declarations
using std::domain_error;

// Statics, globals, typedefs

void
errorCheckOnInput(int nDigits, int digitSum) {
    if (0 == nDigits) {
        throw domain_error("Error! ndigits 0! Exiting...!");
    }

    if (digitSum < 0) {
        throw domain_error("Error! digit sum -ve! Exiting...!");
    }

    if (0 == digitSum) {
        if (1 != nDigits) {
            throw domain_error("Error! "
                "ndigits > 1 with digit sum 0! Exiting...!");
        }
        return;
    }

    // Sum of digits exceeds max possible val for given number of digits
    if (digitSum > 9 * nDigits) {
        throw domain_error("Error! "
            "Sum of digits specified exceeds possible numbers! Exiting...!");
    }

    // Sum of digits below min possible val for given number of digits
    if (digitSum < (0 + (9 * (nDigits - 1)))) {
        throw domain_error("Error! "
            "Sum of digits specified less than possible numbers! Exiting...!");
    }
}

int
sumOfDigits(int n) {
    int sum = 0;
    while (n) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int
findLargestNumUsingBruteForce(int nDigits, int digitSum) {
    try {
        errorCheckOnInput(nDigits, digitSum);
    } catch (domain_error& e) {
        throw e;
    }

    if (0 == digitSum && 1 == nDigits) {
        return 0;
    }

    // Iterate over all possible numbers for the given number of digits
    // Select the one whose sum of digits matches the specified value
    int maxPossibleNum = pow(10, nDigits) - 1;
    int minPossibleNum = pow(10, nDigits - 1);
    for (int i = maxPossibleNum; i >= minPossibleNum + 1; --i) {
        if (digitSum == sumOfDigits(i)) {
            return i;
        }
    }
}

int
findLargestNumUsingGreedyMethod(int nDigits, int digitSum) {
    try {
        errorCheckOnInput(nDigits, digitSum);
    } catch (domain_error& e) {
        throw e;
    }

    if (0 == digitSum && 1 == nDigits) {
        return 0;
    }

    // Adopt greedy method of selecting max possible value for
    // a digit (i.e. 9) till from most significant digit till least significant
    // digit is reached which can be the remainder sum
    int number = 0;
    while (nDigits-- > 0) {
        if (digitSum >= 9) {
            digitSum -= 9;
            number = number * 10 + 9;
        } else {
            number = number * 10 + digitSum;
            break;
        }
    }

    return number;
}
