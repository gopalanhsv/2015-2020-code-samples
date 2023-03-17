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
    // Read all the student records. Segregate student records into
    // those that turned in all the homework and thos who didn't
    vector<StudentInfoT> did, didnt;
    StudentInfoT record;
    while (read(cin, record)) {
        if (didAllHw(record)) {
            did.push_back(record);
        } else {
            didnt.push_back(record);
        }
    }

    // Check that the analyses will actually show something
    if (did.empty()) {
        cout << "All students missed turning in some/all homework" << endl;
        return 1;
    }
    if (didnt.empty()) {
        cout << "All students turned in all homework" << endl;
        return 1;
    }

    // Output the analysis
    writeAllAnalysis(cout, did, didnt);

    return 0;
}
