// System includes
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

// Local includes
#include "frame.h"

// Using declarations
using std::string;
using std::vector;
using std::max;
using std::transform;
using std::back_inserter;

static string::size_type maxlen = 0;

// Return the length of longest string in the vector
string::size_type
width(const vector<string>& v) {
    for (vector<string>::size_type i = 0; i != v.size(); ++i) {
        maxlen = max(v[i].size(), maxlen);
    }
    return maxlen;
}

string
frameString(const string& s) {
    // Add border and pad with spaces to length of longest string
    return string("* " + s + string(maxlen - s.size(), ' ') + " *");
}

// Returns a vector framing the given vector
vector<string>
frame(const vector<string>& p) {
    // Get the picture width (i.e max length of string in pic)
    maxlen = width(p);
    // Variable for storing framed pic
    vector<string> fp;
    // Top and bottom border of framed pic
    string border(maxlen + 4, '*');
    // Add top border to framed pic
    fp.push_back(border);
    // Frame each line of the pic
    transform(p.begin(), p.end(), back_inserter(fp), frameString);
    // Add bottom border to framed pic
    fp.push_back(border);
    return fp;
}
