// Local includes
#include "../Vec/Vec.h"
#include "vcat.h"

using std::string;

// Returns a character picture with the top vector of strings
// stacked above the bottom vector
Vec<string>
vcat(const Vec<string>& top, const Vec<string>& bottom) {
    // Init return with the top pic
    Vec<string> ret(top);

    // Iterate over the bottom pic line by line, appending each
    // line to the pic to be returned
    for (Vec<string>::const_iterator iter = bottom.begin();
        iter != bottom.end(); ++iter) {
        ret.push_back(*iter);
    }

    return ret;
}
