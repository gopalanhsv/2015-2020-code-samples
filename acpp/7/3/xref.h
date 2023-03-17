#ifndef _XREF_H_
#define _XREF_H_

// System headers
#include <string>
#include <vector>
#include <map>

// Local includes
#include "split.h"

// Using declarations

// Typedefs

std::map<std::string, std::vector<unsigned long> >
xref(std::istream&,
    std::vector<std::string> findWords(const std::string&) = split);

void displayXrefTable(std::ostream& os,
    const std::map<std::string, std::vector<unsigned long> >&);

#endif
