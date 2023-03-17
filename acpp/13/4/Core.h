#ifndef _CORE_H_
#define _CORE_H_

// System headers
#include <string>
#include <vector>
#include <iostream>

// Local includes

// Using declarations

// Typedefs, statics, globals
class StudentInfo;

class Core {
    friend class StudentInfo;
public:
    // Constructors
    Core() : midterm(0), final(0) {}
    Core(std::istream&);
    // Destructor
    virtual ~Core() {};

    virtual std::istream& read(std::istream&);
    virtual double grade() const;
    virtual bool valid() const;
    std::string name() const { return n; }

protected:
    virtual Core* clone() const { return new Core(*this); }
    std::istream& readCommon(std::istream&);
    std::istream& readHomework(std::istream&, std::vector<double>&);

    // Data members
    double midterm, final;
    std::vector<double> homework;

private:
    std::string n;
};

bool
compareCorePtrs(const Core* cp1, const Core* cp2);

#endif /* _CORE_H_ */
