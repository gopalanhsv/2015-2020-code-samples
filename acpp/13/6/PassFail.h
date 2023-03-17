#ifndef _PASS_FAIL_H_
#define _PASS_FAIL_H_

// System headers
#include <string>
#include <vector>
#include <iostream>

// Local includes
#include "Core.h"

// Using declarations

// Typedefs, statics, globals

class PassFail : public Core {
public:
    // Constructors
    PassFail() {}
    PassFail(std::istream&);

    std::istream& read(std::istream&);
    double grade() const;
    bool valid() const;

protected:
    PassFail* clone() const { return new PassFail(*this); }

    // Data members
private:
};

#endif /* _PASS_FAIL_H_ */
