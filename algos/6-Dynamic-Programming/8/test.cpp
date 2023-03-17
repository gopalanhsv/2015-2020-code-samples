// System headers
#include <iostream>
#include <stdexcept>

// Local includes
#include "eggDrop.h"

// Using declarations
using std::cin;
using std::cout;
using std::endl;
using std::domain_error;

// Statics, typedefs, globals

void
test() {
    while (true) {
        int ne, nf;
        cout << endl << "Enter number of eggs : ";
        while (!(cin >> ne));
        cout << endl << "Enter number of floors : ";
        while (!(cin >> nf));

        try {
            int nt = minTrialsForEggDropBruteForce(ne, nf);
            cout << "Min drop attempts to determine floor at which egg breaks "
                << "for [" << ne << " eggs, " << nf << " floors] via "
                << "brute force is " << nt << endl;
        } catch (domain_error& e) {
            throw e;
        }

        try {
            int nt = minTrialsForEggDropDPMemoization(ne, nf);
            cout << "Min drop attempts to determine floor at which egg breaks "
                << "for [" << ne << " eggs, " << nf << " floors] via "
                << "dp memoization is " << nt << endl;
        } catch (domain_error& e) {
            throw e;
        }

        try {
            int nt = minTrialsForEggDropDPTabulation(ne, nf);
            cout << "Min drop attempts to determine floor at which egg breaks "
                << "for [" << ne << " eggs, " << nf << " floors] via "
                << "dp tabulation is " << nt << endl;
        } catch (domain_error& e) {
            throw e;
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
