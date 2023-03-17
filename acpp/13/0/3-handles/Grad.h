#ifndef _GRAD_H_
#define _GRAD_H_

// System headers
#include <string>
#include <vector>
#include <iostream>

// Local includes
#include "Core.h"

// Using declarations

// Typedefs, statics, globals

class Grad : public Core {
public:
    // Constructors
    Grad() : thesis(0) {}
    Grad(std::istream&);

    std::istream& read(std::istream&);
    double grade() const;

protected:
    Grad* clone() const { return new Grad(*this); }

private:
    // Data members
    double thesis;
};

#endif /* _GRAD_H_ */
