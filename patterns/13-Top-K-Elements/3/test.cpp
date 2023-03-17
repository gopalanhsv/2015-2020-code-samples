// System headers
#include <vector>
#include <stdexcept>
#include <iostream>

// Local includes
#include "point.h"

// Using declarations
using std::vector;
using std::domain_error;
using std::cin;
using std::cout;
using std::endl;

// Statics, typedefs, globals

void
readVec(vector<Point>& v) {
    v.clear();
    while (true) {
        cout << endl;
        int x, y;
        cout << "Enter x coordinate :";
        if (!(cin >> x)) {
            cin.clear();
            cin.ignore(1000, '\n');
            break;
        }
        cout << "Enter y coordinate :";
        if (!(cin >> y)) {
            cin.clear();
            cin.ignore(1000, '\n');
            break;
        }
        Point p(x, y);
        v.push_back(p);
    }
}

void
printVec(const vector<Point>& v) {
    cout << endl;
    for (auto p : v) {
        cout << "[" << p.x() << ", " << p.y() << "] ";
    }
    cout << endl;
}

void
test() {
    vector<Point> pv;
    cout << "Enter input array of points : ";
    readVec(pv);
    cout << "Input points are : ";
    printVec(pv);

    while (true) {
        cout << endl << "Enter k (for getting k closest points to origin) ";
        unsigned long k;
        if (cin >> k) {
            try {
                vector<Point> kpv = PointsArray::kClosestPointsToOrigin(pv, k);
                cout << endl << k << " closest points to origin are :";
                printVec(kpv);
            } catch (domain_error& e) {
                throw e;
            }
        } else {
            cin.clear();
            cin.ignore(10000, '\n');
            break;
        }
    }
}

int
main() {
    try {
        test();
    } catch (domain_error& e) {
        cout << e.what() << endl;
        return 1;
    }
    return 0;
}
