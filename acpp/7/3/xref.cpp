// System headers
#include <string>
#include <vector>
#include <map>
#include <stdexcept>
#include <iostream>
#include <algorithm>

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
using std::find;

// Typedefs

map<string, vector<unsigned long> >
xref(istream& in, vector<string> findWords(const string& s)) {
    if (!in) {
        throw domain_error("Error! Errored i/p stream! Exiting...!");
    }

    // Association from a word seen at the input to the line
    // numbers where it was seen
    map<string, vector<unsigned long> > wordToLines;

    // Read all lines from the input, get the constituent words and
    // update the assocition from word to respective line numbers
    unsigned long lineNumber = 0;
    string line;
    while (getline(in, line)) {
        // Get the constituent words from read line
        vector<string> lineWords = findWords(line);
        // Iterate over all the constituent words
        for (vector<string>::const_iterator iter =
            lineWords.begin(); iter != lineWords.end(); ++iter) {
            // Associate the word with current line number
            // Avoid duplicate occurences of same line number
            // for a word
            vector<unsigned long>& lineNums = wordToLines[*iter];
            if (find(lineNums.begin(), lineNums.end(), lineNumber)
                == lineNums.end()) {
                lineNums.push_back(lineNumber);
            }
        }
        ++lineNumber;
    }

    return wordToLines;
}

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
