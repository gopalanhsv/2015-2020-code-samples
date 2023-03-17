// System headers
#include <string>
#include <vector>
#include <iostream>
#include <ios>
#include <iomanip>
#include <algorithm>
#include <stdexcept>

// Local includes
#include "Core.h"
#include "Grad.h"
#include "RefHandle.h"

// Using declarations
using std::cin;
using std::cout;
using std::endl;
using std::setprecision;
using std::streamsize;
using std::string;
using std::vector;
using std::max;
using std::sort;
using std::domain_error;
using std::runtime_error;

// Typedefs, statics, globals

bool
compareCoreRefHandles(const RefHandle<Core>& hc1, const RefHandle<Core>& hc2) {
    return hc1->name() < hc2->name();
}

int
main() {
    // Read the student records and store them in vector
    vector<RefHandle<Core> > students;
    RefHandle<Core> record;
    string::size_type maxlen = 0;
    char ch;
    while (cin >> ch) {
        if ('U' == ch) {
            record = new Core(cin);
        } else if ('G' == ch) {
            record = new Grad(cin);
        } else {
            cout << "Error! Incorrect student type! Exiting...!" << endl;
            return 1;
        }
        maxlen = max(maxlen, record->name().size());
        students.push_back(record);
    }

    // Sort the student records alphabetically
    sort(students.begin(), students.end(), compareCoreRefHandles);

    // Compute the grade for each student and output the student records
    // in alphabetical order with the grades lining up vertically
    for (vector<RefHandle<Core> >::size_type i = 0; i != students.size(); ++i) {

        const string& sname = students[i]->name();
        cout << sname << string(maxlen + 1 - sname.size(), ' ');

        try {
            double g = students[i]->grade();
            streamsize prec = cout.precision();
            cout << setprecision(3) << g << setprecision(prec) << endl;
        } catch (runtime_error re) {
            cout << re.what() << endl;
            return 1;
        } catch (domain_error de) {
            cout << de.what() << endl;
            return 1;
        }
    }

    return 0;
}
