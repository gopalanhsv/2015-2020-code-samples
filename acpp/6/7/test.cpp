// System headers
#include <iostream>
#include <vector>
#include <string>

// Local includes
#include "studentInfo.h"
#include "analysis.h"

// Using declarations
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int
main() {
    // Read all the student records.
    vector<StudentInfoT> students;
    StudentInfoT record;
    while (read(cin, record)) {
        students.push_back(record);
    }

    // Segregate student records into those that turned in all the
    // homework and those who didn't (this will remain in the students
    // vector after extraction of those who did all homework) 
    vector<StudentInfoT> did = extractDidAllHomework(students);

    // Check that the analyses will actually show something
    if (did.empty()) {
        cout << "All students missed turning in some/all homework" << endl;
        return 1;
    }
    if (students.empty()) {
        cout << "All students turned in all homework" << endl;
        return 1;
    }

    // Output the analysis
    writeAllAnalysis(cout, did, students);

    return 0;
}
