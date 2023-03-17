// System headers
#include <string>
#include <vector>
#include <map>
#include <stdexcept>
#include <iostream>

// Local includes
#include "split.h"
#include "xref.h"

// Using declarations
using std::string;
using std::vector;
using std::map;
using std::domain_error;
using std::istream;
using std::ostream;
using std::endl;

// Typedefs

void
displayXrefTable(ostream& os,
    const map<string, vector<unsigned long> >& xrefTbl) {
    if (!os) {
        throw domain_error("Error! Errored o/p stream! Exiting...!");
    }

    if (xrefTbl.empty()) {
        throw domain_error("Error! Empty xref table! Exiting...!");
    }

    os << endl;
    // Iterate over every entry in the xref table
    for (map<string, vector<unsigned long> >::const_iterator
        iter = xrefTbl.begin(); iter != xrefTbl.end(); ++iter) {
        // Output the word
        os << "<" << iter->first << "> occurs on line(s) : ";

        // Output the first line number
        const vector<unsigned long>& lines = iter->second;
        vector<unsigned long>::const_iterator lineIter = lines.begin();
        os << *lineIter;
        ++lineIter;
        // Output the other line numbers
        for (; lineIter != lines.end(); ++lineIter) {
            os << ", " <<  *lineIter;
        }

        os << endl;
    }
    os << endl;
}
