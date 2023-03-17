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
    std::string name() {
        return n;
    }
    std::istream& read(std::istream&);
    double grade() const;

private:
    // Data members
    // Student name
    std::string n;
    // Midterm, finals and homework grades
    double midterm, final;
    std::vector<double> homework;
};

bool compare(StudentInfo&, StudentInfo&);
