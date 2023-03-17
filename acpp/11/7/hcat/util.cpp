// System headers
#include <string>
#include <algorithm>

// Local includes
#include "../Vec/Vec.h"
#include "util.h"

using std::string;
using std::max;

string::size_type
width(const Vec<string>& v) {
    string::size_type maxlen = 0;
    for (Vec<string>::size_type i = 0; i != v.size(); ++i) {
        maxlen = max(maxlen, v[i].size());
    }
    return maxlen;
}
