#ifndef _CORE_H_
#define _CORE_H_

// System headers
#include <string>
#include <vector>
#include <iostream>

// Local includes

// Using declarations

// Typedefs, statics, globals

class Core {
public:
    // Constructors
    Core() : midterm(0), final(0) {}
    Core(std::istream&);

    virtual std::istream& read(std::istream&);
    virtual double grade() const;
    virtual Core* clone() const;
    std::string name() const { return n; }

protected:
    std::istream& readCommon(std::istream&);
    std::istream& readHomework(std::istream&, std::vector<double>&);

    // Data members
    double midterm, final;
    std::vector<double> homework;

private:
    std::string n;
};

bool
compare(const Core& c1, const Core& c2);

#endif /* _CORE_H_ */
