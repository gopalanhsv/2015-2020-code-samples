#include "frame.h"

using std::string;
using std::vector;
using std::max;

// Returns the length of longest string in vector
string::size_type
width(const vector<string>& v) {
    string::size_type maxlen = 0;
    for (vector<string>::size_type i = 0; i != v.size(); ++i) {
        maxlen = max(maxlen, v[i].size());
    }
    return maxlen;
}

// Returns a vector framing the given vector
vector<string>
frame(const vector<string>& v) {
    // Construct top & bottom borders
    string::size_type maxlen = width(v);
    string border(maxlen + 4, '*');

    vector<string> ret;
    // Create top border
    ret.push_back(border);

    // Iterate through the vector and frame all lines
    for (vector<string>::size_type i = 0; i != v.size(); ++i) {
        // Add border & pad lines lesser than the longest length
        ret.push_back(
            string("* " + v[i] + string(maxlen - v[i].size(), ' ') + " *"));
    }

    // Create bottom border
    ret.push_back(border);

    return ret;
}
