#ifndef _STUDENT_INFO_H_
#define _STUDENT_INFO_H_

// System headers
#include <string>
#include <vector>

// Local includes

typedef struct _StudentInfoT {
    std::string name;
    double midterm, final;
    std::vector<double> homework;
} StudentInfoT;

std::istream& read(std::istream&, StudentInfoT&);

std::istream& readHw(std::istream&, std::vector<double>&);

bool compare(const StudentInfoT&, const StudentInfoT&);

// Extracts students who did all homework and returns the same.
// Retains only students who missed some homework in input vector
std::vector<StudentInfoT> extractDidAllHomework(std::vector<StudentInfoT>&);

// Returns true if given student turned in all the homework
bool didAllHw(const StudentInfoT& s);

#endif /* _STUDENT_INFO_H_ */
