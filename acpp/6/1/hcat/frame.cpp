// System includes
#include <string>
#include <vector>
#include <algorithm>

// Local includes
#include "frame.h"

// Using declarations
using std::string;
using std::vector;
using std::max;

string::size_type
width(const vector<string>& v) {
    string::size_type maxlen = 0;
    for (vector<string>::const_iterator i = v.begin(); i != v.end(); ++i) {
        maxlen = max(maxlen, i->size());
    }
    return maxlen;
}

vector<string>
frame(const vector<string>& v) {
    vector<string> ret;
    string::size_type w = width(v);
    string border(w + 4, '*');
    ret.push_back(border);
    for (vector<string>::const_iterator i = v.begin(); i != v.end(); ++i) {
        ret.push_back("* " + *i + string(w - i->size(), ' ') + " *");
    }
    ret.push_back(border);
    return ret;
}
