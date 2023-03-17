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
using std::ostream;
using std::setfill;
using std::setw;
using std::left;
using std::fixed;

typedef string::size_type strSzT;

void
displayRecords(ostream& os, StudentInfoRecordsT& students) {
    // Sort the student records alphabetically
    sort(students.begin(), students.end(), compare);

    // Find the longest student name amongst all records
    strSzT maxlen = 0;
    StudentInfoRecordsT::const_iterator iter = students.begin();
    StudentInfoRecordsT::const_iterator endIter = students.end();
    for (; iter != endIter; ++iter) {
        maxlen = max(maxlen, (*iter).name.size());
    }

    // Display all student records with the name padded out
    // to longest name length along with the computed grade
    iter = students.begin();
    endIter = students.end();
    for (; iter != endIter; ++iter) {
        const StudentInfoT& si = *iter;
        os << setw(maxlen + 1) << left << si.name;
        streamsize prec = os.precision();
        double finalGrade = grade(*iter);
        os << fixed << setprecision(3) << finalGrade << setprecision(prec);
        cout << endl;
    }
    cout << endl;
}

int
main() {
    // Read all the student data records and
    // compute the largest of all student names
    StudentInfoRecordsT students;
    StudentInfoT record;
    string::size_type maxlen = 0;
    while (read(cin, record)) {
        maxlen = max(maxlen, record.name.size());
        students.push_back(record);
    }

    // Separate input and output
    cout << endl;

    // Compute the final grade and display the same
    // for all students in alphabetical ordering
    cout << "================================================" << endl;
    cout << "ALL STUDENTS" << endl;
    cout << "================================================" << endl;
    try {
        displayRecords(cout, students);
    } catch (domain_error e) {
        cout << e.what() << endl;
        return 1;
    }
    cout << "================================================" << endl;

    StudentInfoRecordsT failed = extractFails(students);

    // Display passed students
    cout << "================================================" << endl;
    cout << "PASSED STUDENTS" << endl;
    cout << "================================================" << endl;
    try {
        displayRecords(cout, students);
    } catch (domain_error e) {
        cout << e.what() << endl;
        return 1;
    }
    cout << "================================================" << endl;

    // Display failed students
    cout << "================================================" << endl;
    cout << "FAILED STUDENTS" << endl;
    cout << "================================================" << endl;
    try {
        displayRecords(cout, failed);
    } catch (domain_error e) {
        cout << e.what() << endl;
        return 1;
    }
    cout << "================================================" << endl;

    return 0;
}
