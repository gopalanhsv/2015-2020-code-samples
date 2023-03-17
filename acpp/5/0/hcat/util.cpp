#include <string>
#include <vector>
#include <algorithm>
#include "util.h"

using std::string;
using std::vector;
using std::max;

string::size_type
width(const vector<string>& v) {
    string::size_type maxlen = 0;
    for (vector<string>::size_type i = 0; i != v.size(); ++i) {
        maxlen = max(maxlen, v[i].size());
    }
    return maxlen;
}
