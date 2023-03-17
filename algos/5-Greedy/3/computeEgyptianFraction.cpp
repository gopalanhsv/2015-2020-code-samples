// System headers
#include <vector>
#include <stdexcept>
#include <iostream>

// Local includes
#include "computeEgyptianFraction.h"

// Using declarations
using std::vector;
using std::domain_error;
using std::cout;
using std::endl;

// Statics, typedefs and globals

void
computeEgyptianFraction(int n, int d,
    vector<int>& intPart, vector<int>& fractionalParts) {
    // Numerator or denominator is 0
    if (0 == n || 0 == d) {
        return;
    }

    // Numerator exceeds denominator
    if (n > d) {
        // Compute divisible quotient
        intPart.push_back(n / d);
        if (0 != n % d) {
            // Numerator not divisible by denominator, so need to compute
            // egyptian fraction for remainder part after divison
            computeEgyptianFraction(n % d, d, intPart, fractionalParts);
        }
        return;
    }

    // Numerator is lesser than deominator here onwards
    if (0 == d % n) {
        // Denominator is completely divisible by numerator
        fractionalParts.push_back(d / n);
    } else {
        // Greedily Compute the max unit fractional part possible
        int maxFractionalPart = d / n + 1;
        fractionalParts.push_back(maxFractionalPart);
        // Recursive compute the egyptian fraction for value remaining
        // after removing the max unit fractional part
        // i.e [(n / d) - (1 / maxFractionalPart)]
        computeEgyptianFraction(n * maxFractionalPart - d, d * maxFractionalPart,
            intPart, fractionalParts);
    }
}

void
printEgyptianFraction(vector<int>& intParts, vector<int>& fractionalParts) {
    if (intParts.empty() && fractionalParts.empty()) {
        throw domain_error("Error! Both int and frac parts empty!");
    } 

    typedef vector<int>::size_type vecSzT;
    for (vecSzT i = 0; i != intParts.size(); ++i) {
        cout << intParts[i] << " + ";
    }
    if (!fractionalParts.empty()) {
        cout << "1/" << fractionalParts[0];
        for (vecSzT i = 1; i <= fractionalParts.size() - 1; ++i) {
            cout << " + 1/" << fractionalParts[i];
        }
    }
    cout << endl;
}

void
computeEgyptianFraction(int n, int d) {
    vector<int> intParts;
    vector<int> fracParts;
    computeEgyptianFraction(n, d, intParts, fracParts);
    printEgyptianFraction(intParts, fracParts);
}
