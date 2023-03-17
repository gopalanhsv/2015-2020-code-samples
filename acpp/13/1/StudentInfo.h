#ifndef _STUDENT_INFO_H_
#define _STUDENT_INFO_H_

// System headers
#include <iostream>
#include <string>

// Local includes
#include "Core.h"

// Using declarations

// Statics, globals, typedefs

class StudentInfo {
public:
    // Constructors
    StudentInfo() : cp(0) {}
    StudentInfo(const StudentInfo&);
    ~StudentInfo();

    // Assignment operator
    StudentInfo& operator=(const StudentInfo&);

    // Interface functions
    std::istream& read(std::istream&);
    double grade() const;
    std::string name() const;

    static bool compare(const StudentInfo&, const StudentInfo&);

private:
    Core* cp;
};

#endif /* _STUDENT_INFO_H_ */
