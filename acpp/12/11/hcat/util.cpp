// System headers
#include <algorithm>

// Local includes
#include "../lib/Str.h"
#include "../lib/Vec.h"
#include "util.h"

using std::max;

Str::size_type
width(const Vec<Str>& v) {
    Str::size_type maxlen = 0;
    for (Vec<Str>::size_type i = 0; i != v.size(); ++i) {
        maxlen = max(maxlen, v[i].size());
    }
    return maxlen;
}
