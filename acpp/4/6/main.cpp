#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <ios>
#include <iomanip>
#include <stdexcept>

#include "StudentInfo.h"
#include "grade.h"

// Using declarations
using std::vector;
using std::string;
using std::max;
using std::sort;
using std::streamsize;
using std::setprecision;
using std::domain_error;
using std::cin;
using std::cout;
using std::endl;

int
main() {
    // Read all the student data records and
    // compute the largest of all student names
    vector<StudentInfoT> students;
    StudentInfoT record;
    string::size_type maxlen = 0;
    try {
        while (read(cin, record)) {
            maxlen = max(maxlen, record.name.size());
            students.push_back(record);
        }
    } catch (domain_error e) {
        cout << e.what() << endl;
        return 1;
    }

    // Sort the student records alphabetically
    sort(students.begin(), students.end(), compare);

    // Separate input and output
    cout << endl;

    // Compute the final grade and display the same
    // for all students in alphabetical ordering
    for (vector<StudentInfoT>::size_type i = 0; i != students.size(); ++i) {
        const string& s = students[i].name;
        // Output student name padded out on right to the
        // longest student name
        cout << s << string(maxlen + 1 - s.size(), ' ');
        // Compute final grade and display
        double final = grade(students[i]);
        streamsize prec = cout.precision();
        cout << setprecision(3) << final << setprecision(prec) << endl;
    }

    return 0;
}
