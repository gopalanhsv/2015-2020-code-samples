// System headers
#include <algorithm>

// Local includes
#include "../lib/Str.h"
#include "../lib/Vec.h"
#include "util.h"

// Using declarations
using std::max;

// Returns a vector framing the given vector
Vec<Str>
frame(const Vec<Str>& v) {
    // Construct top & bottom borders
    Str::size_type maxlen = width(v);
    Str border(maxlen + 4, '*');

    Vec<Str> ret;
    // Create top border
    ret.push_back(border);

    // Iterate through the vector and frame all lines
    for (Vec<Str>::size_type i = 0; i != v.size(); ++i) {
        // Add border & pad lines lesser than the longest length
        ret.push_back(
            Str("* " + v[i] + Str(maxlen - v[i].size(), ' ') + " *"));
    }

    // Create bottom border
    ret.push_back(border);

    return ret;
}
