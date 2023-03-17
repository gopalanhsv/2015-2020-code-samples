// System headers
#include <string>
#include <vector>
#include <iostream>

// Local includes

// Typedefs and globals

class StudentInfo {
public:
    // Interface
    // Constructors
    StudentInfo();
    StudentInfo(std::istream&);

    // Member functions
    std::string name() const {
        return n;
    }
    std::istream& read(std::istream&);
    double grade() const;
    bool valid() const;

private:
    // Data members
    // Student name
    std::string n;
    double computedGrade;
    bool validGrade;
};

bool compare(const StudentInfo&, const StudentInfo&);
