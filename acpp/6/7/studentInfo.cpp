// System headers
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

// Local includes
#include "studentInfo.h"

// Using declarations
using std::string;
using std::vector;
using std::istream;
using std::cin;
using std::istream;
using std::find;
using std::stable_partition;

istream&
read(istream& in, StudentInfoT& si) {
    cin >> si.name >> si.midterm >> si.final;
    readHw(in, si.homework);
}

istream&
readHw(istream& in, vector<double>& homework) {
    if (in) {
        homework.clear();
        double x;
        while (in >> x)
            homework.push_back(x);
        in.clear();
    }
    return in;
}

bool
compare(const StudentInfoT& s1, const StudentInfoT& s2) {
    return s1.name < s2.name;
}

bool
didNotDoAllHw(const StudentInfoT& s) {
    return 
        find(s.homework.begin(), s.homework.end(), 0) != s.homework.end();
}

// Extracts students who did all homework and returns the same.
// Retains only students who missed some homework in input vector
vector<StudentInfoT>
extractDidAllHomework(vector<StudentInfoT>& students) {
    // Rearrange students who did not do all homework to beginning of vector
    // and rest of students(who did all homework) after them
    vector<StudentInfoT>::iterator iter
         = stable_partition(students.begin(), students.end(), didNotDoAllHw);
    // Create vector of students who did all homework from partitioned
    // marker values above. Then remove these students from input vector
    // such that it retains only students who missed some homework
    vector<StudentInfoT> didAllHw(iter, students.end());
    students.erase(iter, students.end());
    return didAllHw;
}

// Returns true if given student turned in all the homework
bool
didAllHw(const StudentInfoT& s) {
    return find(s.homework.begin(), s.homework.end(), 0.0) == s.homework.end();
}
