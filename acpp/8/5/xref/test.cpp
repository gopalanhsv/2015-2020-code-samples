// System headers
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <stdexcept>
#include <iterator>

// Local includes
#include "xref.h"

// Using declarations
using std::string;
using std::vector;
using std::map;
using std::cin;
using std::cout;
using std::endl;
using std::domain_error;
using std::back_inserter;
using std::ostream_iterator;

// Typedefs

int
main() {
    xref(cin, ostream_iterator<string>(cout, " "),
        ostream_iterator<unsigned long>(cout, "\n"));
    return 0;
}
