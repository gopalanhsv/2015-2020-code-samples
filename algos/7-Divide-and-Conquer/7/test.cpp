// System headers
#include <iostream>
#include <stdexcept>
#include <vector>

// Local includes
#include "closestPointPair.h"

// Using declarations
using std::vector;
using std::domain_error;
using std::cin;
using std::cout;
using std::endl;

// Statics, globals, typedefs

void
readPointVec(PointVecT& pv) {
    pv.clear();
    cout << "Enter number of points : ";
    int n;
    cin >> n;
    while (n--) {
        PointT p;
        cout << endl << "Enter x coordinate : ";    
        while (!(cin >> p._x));
        cout << endl << "Enter y coordinate : ";    
        while (!(cin >> p._y));

        pv.push_back(p);
    }
}

void
printPointVec(const PointVecT& pv) {
    cout << endl;
    cout << "Points are : ";
    for (auto p : pv) {
        cout << "(" << p._x << ", " << p._y << "), ";
    }
    cout << endl;
}

void
testFn() {
    PointVecT pv;
    readPointVec(pv);
    printPointVec(pv);

    try {
        double md = closestPointPairDistanceBruteForce(pv);
        cout << "Minimum distance between given points via brute force is "
            << md << endl;
    } catch (domain_error& e) {
        throw e;
    }

    try {
        double md = closestPointPairDistanceDivConquer(pv);
        cout << "Minimum distance between given points via divide+conquer is "
            << md << endl;
    } catch (domain_error& e) {
        throw e;
    }
}

int
main() {
    try {
        testFn();
    } catch (domain_error& e) {
        cout << e.what() << endl;
        return 1;
    }
    return 0;
}
