// System includes
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

// Local includes
#include "vcat.h"

// Using declarations
using std::string;
using std::vector;
using std::copy;
using std::back_inserter;

// Vertically concatenate the given two pictures (vectors of strings)
// by stacking one of top of the other
vector<string>
vcat(const vector<string>& top, const vector<string>& bottom) {
    // Initialize the vcat picture with the top picture
    vector<string> ret(top);
    // Add the bottom picture to vcat picture
    copy(bottom.begin(), bottom.end(), back_inserter(ret));
    return ret;
}
