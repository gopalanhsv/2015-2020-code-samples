// System headers
#include <string>
#include <map>
#include <list>
#include <vector>
#include <iterator>
#include <algorithm>

// Local includes

// Using declarations
using std::string;
using std::map;
using std::list;
using std::vector;
using std::pair;
using std::back_inserter;
using std::copy;

// Typedefs, globals

int
main() {
    map<int, string> m;
    // x should be a container which supports push_back() operations
    // as its an argument to back_inserter
    list<pair<int, string> > x;
    copy(m.begin(), m.end(), back_inserter(x));
    // x1 should be a container which supports push_back() operations
    // as its an argument to back_inserter
    vector<pair<int, string> > x1;
    copy(m.begin(), m.end(), back_inserter(x1));
    // Below causes compile time error as m of map type has no support
    // for push_back ops 
    // copy(x.begin(), x.end(), back_inserter(m));
    return 0;
}
