#ifndef _STUDENT_INFO_H_
#define _STUDENT_INFO_H_

// System headers
#include <iostream>
#include <string>

// Local includes
#include "Ptr.h"
#include "Core.h"

// Using declarations

// Statics, typedefs, globals

class StudentInfo {
public:
    StudentInfo() : pc(NULL) {}
    StudentInfo(std::istream&);

    std::istream& read(std::istream&);
    std::string name() const;
    double grade() const;
    static bool compare(const StudentInfo&, const StudentInfo&);

private:
    // Data members
    Ptr<Core> pc;
};

#endif /* _STUDENT_INFO_H_ */
