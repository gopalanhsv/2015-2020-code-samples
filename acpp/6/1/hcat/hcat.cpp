// System includes
#include <string>
#include <vector>
#include <algorithm>

// Local includes
#include "frame.h"
#include "hcat.h"

// Using declarations
using std::string;
using std::vector;

vector<string>
hcat(const vector<string>& left, const vector<string>& right) {
    // Blank padding size for left picture
    string::size_type width1 = width(left) + 1;

    vector<string> ret;
    // Traverse all rows of both left and right pictures
    typedef vector<string>::const_iterator strIterT;
    strIterT lIter = left.begin();
    strIterT rIter = right.begin();
    while (lIter != left.end() || rIter != right.end()) {
        // String holding current row under construction
        string s;

        // Add row from left picture
        if (lIter != left.end()) {
            s += *lIter;
            ++lIter;
        }

        // Pad left side with appropriate number of blanks
        s += string(width1 - s.size(), ' ');

        // Add row from right picture
        if (rIter != right.end()) {
            s += *rIter;
            ++rIter;
        }

        // Add current constructed row
        ret.push_back(s);
    }
    return ret;
}
