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

template<typename OutStrIterT, typename OutIntIterT>
void
xref(std::istream& in, OutStrIterT os, OutIntIterT oi,
    std::vector<std::string> findWords(const std::string& s) = split) {

    using std::string;
    using std::vector;
    using std::domain_error;

    if (!in) {
        throw domain_error("Error! Errored i/p stream! Exiting...!");
    }

    // Read all lines from the input, get the constituent words and
    // update the association from word to respective line numbers
    unsigned long lineNumber = 0;
    string line;
    while (getline(in, line)) {
        // Get the constituent words from read line
        vector<string> lineWords = findWords(line);
        // Iterate over all the constituent words
        for (vector<string>::const_iterator iter =
            lineWords.begin(); iter != lineWords.end(); ++iter) {
            // Associate the word with current line number
            // and send it to output
            *os++ = *iter;
            *oi++ = lineNumber;
        }
        ++lineNumber;
    }
}

void displayXrefTable(std::ostream& os,
    const std::map<std::string, std::vector<unsigned long> >&);

#endif
