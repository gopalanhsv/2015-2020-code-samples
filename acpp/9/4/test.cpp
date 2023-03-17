// System headers
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <ios>
#include <iomanip>
#include <stdexcept>

// Local includes
#include "grade.h"
#include "studentInfo.h"

// Using declarations
using std::string;
using std::vector;
using std::max;
using std::sort;
using std::cin;
using std::cout;
using std::endl;
using std::streamsize;
using std::setprecision;
using std::domain_error;

// Typedefs and globals

int
main() {
    StudentInfo record;
    vector<StudentInfo> students;
    string::size_type maxlen = 0;
    // Read and populate the student records, and find
    // the student name with maximum length
    while (record.read(cin)) {
        maxlen = max(maxlen, record.name().size());
        students.push_back(record);
    }

    // Sort the records alphabetically
    sort(students.begin(), students.end(), compare);

    cout << endl;
    // Display the student records in alphabetical order after
    // computing final grade. Also line up the grades vertically
    // by insertion of appropriate padding after the name
    for (vector<StudentInfo>::size_type i = 0; i != students.size(); ++i) {
        // Skipping invalid students (i.e. those with no homework grades)
        if (students[i].valid()) {
            const string& sn = students[i].name();
            cout << sn << string(maxlen + 1 - sn.size(), ' ');
            double grade = students[i].grade();
            streamsize prec = cout.precision(3);
            cout << setprecision(3) << grade << setprecision(prec) << endl;
        }
    }
    cout << endl;

    return 0;
}
