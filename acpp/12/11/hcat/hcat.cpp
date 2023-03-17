// Local includes
#include "../lib/Str.h"
#include "../lib/Vec.h"
#include "util.h"
#include "hcat.h"

Vec<Str>
hcat(const Vec<Str>& left, const Vec<Str>& right) {
    Vec<Str> ret;

    // Max len of left pic (for determining left padding) + 1 
    // for spacing between left and right pics
    Str::size_type width1 = width(left) + 1;

    // Indices for traversing all rows of both pics
    Str::size_type l = 0, r = 0;
    Str::size_type i = 0;
    // Traverse all rows of both the left and right pictures
    // While all rows of both left and right pics are not traversed
    while ((l != left.size()) || (r != right.size())) {
        // For constructing a row of new pic from both pics
        // in current iteration
        Str s;

        // Insert from left pic if feasible
        if (l != left.size())
            s += left[l++];

        // Pad out the current row to max width of left pic + 1
        s += Str(width1 - s.size(), ' ');

        // Insert from right pic if feasible
        if (r != right.size())
            s += right[r++];

        // Add the current constructed row to new pic
        ret.push_back(s);
    }

    return ret;
}
