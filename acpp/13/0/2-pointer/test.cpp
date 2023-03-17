// System headers
#include <iostream>
#include <ios>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <stdexcept>

// Local includes
#include "Core.h"
#include "Grad.h"

// Using declarations
using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::setprecision;
using std::streamsize;
using std::max;
using std::sort;
using std::domain_error;

// Typedefs, statics, globals

int
main() {
    // Read the student records and populate in records vector
    vector<Core*> students;
    string::size_type maxlen = 0;
    char ch;
    while (cin >> ch) {
        Core* record;
        if ('U' == ch) {
            record = new Core(cin);
        } else if ('G' == ch) {
            record = new Grad(cin);
        } else {
            cout << "Error! Incorrect student type! Exiting..!" << endl;
            return 1;
        }
        maxlen = max(maxlen, record->name().size());
        students.push_back(record);
    }

    // Arrange the records alphabetically
    sort(students.begin(), students.end(), compareCorePtrs);

    // Separate input and output
    cout << endl << endl;

    // Output the student records in alphabetically order after computing the
    // grades for each student. Ensure that the computed grades are lined
    // up vertically by insertion of appropriate padding after student names
    for (vector<Core>::size_type i = 0; i != students.size(); ++i) {
        cout << students[i]->name() <<
            string(maxlen + 1 - (students[i]->name()).size(), ' ');
        try {
            double g = students[i]->grade();
            streamsize prec = cout.precision();
            cout << setprecision(3) << g << setprecision(prec) << endl;
        } catch (domain_error e) {
            cout << e.what() << endl;
            return 1;
        }
        delete students[i];
    }

    return 0;
}
