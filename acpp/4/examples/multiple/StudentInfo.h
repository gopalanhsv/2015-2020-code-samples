#ifndef _STUDENT_INFO_H_
#define _STUDENT_INFO_H_

#include <string>
#include <vector>

typedef struct _StudentInfoT {
    std::string name;
    // Midterm, final and homework grades
    double midterm;
    double final;
    std::vector<double> homework;
} StudentInfoT;

// Reads data for a student in StudentInfo struct
// from specified input stream
std::istream& read(std::istream&, StudentInfoT&);

// Reads homework grades into given vector from specified
// input stream
std::istream& readHw(std::istream&, std::vector<double>&);

// Compares 2 StudentInfoT structs on the
// basis of alphabetical ordering
bool compare(const StudentInfoT&, const StudentInfoT&);

#endif /* _STUDENT_INFO_H_ */
