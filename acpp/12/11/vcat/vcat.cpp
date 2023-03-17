// System headers

// Local includes
#include "../lib/Str.h"
#include "../lib/Vec.h"
#include "vcat.h"

// Returns a character picture with the top vector of strings
// stacked above the bottom vector
Vec<Str>
vcat(const Vec<Str>& top, const Vec<Str>& bottom) {
    // Init return with the top pic
    Vec<Str> ret(top);

    // Iterate over the bottom pic line by line, appending each
    // line to the pic to be returned
    for (Vec<Str>::const_iterator iter = bottom.begin();
        iter != bottom.end(); ++iter) {
        ret.push_back(*iter);
    }

    return ret;
}
