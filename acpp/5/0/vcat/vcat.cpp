#include "vcat.h"

using std::string;
using std::vector;

// Returns a character picture with the top vector of strings
// stacked above the bottom vector
vector<string>
vcat(const vector<string>& top, const vector<string>& bottom) {
    // Init return with the top pic
    vector<string> ret(top);

    // Iterate over the bottom pic line by line, appending each
    // line to the pic to be returned
    for (vector<string>::const_iterator iter = bottom.begin();
        iter != bottom.end(); ++iter) {
        ret.push_back(*iter);
    }

    return ret;
}
