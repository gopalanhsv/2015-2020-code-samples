#ifndef _STUDENT_INFO_H_
#define _STUDENT_INFO_H_

#include <string>

#ifdef USE_VECTOR
#include <vector>
#elif USE_LIST
#include <list>
#else
#error "Define either USE_LIST or USE_VECTOR to pre-processor"
#endif

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

// Collection of student info records
#ifdef USE_VECTOR
typedef std::vector<StudentInfoT> StudentInfoRecordsT;
#elif USE_LIST
typedef std::list<StudentInfoT> StudentInfoRecordsT;
#endif

// Extract the students with failing grades out of
// the original set of records and return it
StudentInfoRecordsT extractFails(StudentInfoRecordsT& students);

#endif /* _STUDENT_INFO_H_ */
