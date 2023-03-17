// System includes
#include <string>
#include <vector>
#include <algorithm>

// Local includes
#include "hcat.h"
#include "frame.h"

// Using declarations
using std::string;
using std::vector;
using std::max;

string::size_type paddedLeftPicWidth1 = 0;

string
padStr(const string& s) {
    return s + string(paddedLeftPicWidth1 - s.size(), ' ');
}

// Pad left pic so that all rows are of same size
vector<string>
padLeftPic(const vector<string>& p) {
    vector<string> pp;
    paddedLeftPicWidth1 = width(p) + 1;
    transform(p.begin(), p.end(), back_inserter(pp), padStr);
    return pp;
}

// Horizontally concatenate the left and right pics
vector<string>
hcat(const vector<string>& left, const vector<string>& right) {

    // Pad left pic so that all rows are of same size
    vector<string> paddedLeft = padLeftPic(left);
    
    // Add corresponding rows of padded left and right pic together
    vector<string> ret;
    string::size_type nrows = max(paddedLeft.size(), right.size());
    for (vector<string>::size_type r = 0; r != nrows; ++r) {
        string s =
            ( r < paddedLeft.size() ) ? 
                paddedLeft[r] : string(paddedLeftPicWidth1, ' ');
        if (r < right.size()) {
            s += right[r];
        }
        ret.push_back(s);
    }

    return ret;
}
