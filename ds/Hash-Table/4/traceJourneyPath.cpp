// System headers
#include <vector>
#include <unordered_map>
#include <string>
#include <stdexcept>
#include <utility>

// Local includes
#include "traceJourneyPath.h"

// Using declarations
using std::string;
using std::vector;
using std::unordered_map;
using std::domain_error;
using std::pair;

// Statics, globals, typedefs

string
tracePath(const vector<pair<string, string> >& srcDstPairs) {
    if (srcDstPairs.empty()) {
        throw domain_error("Error! Empty input src/dst pair array!");
    }

    // Create 2 hash tables -
    // 1. Mapping from source to destination
    // 2. Reverse mapping from destination to source
    unordered_map<string, string> srcToDstHashTbl;
    unordered_map<string, string> dstToSrcHashTbl;
    typedef vector<pair<string, string> >::size_type vecSzT;
    for (vecSzT i = 0; i != srcDstPairs.size(); ++i) {
        const pair<string, string>& sdp = srcDstPairs[i];
        srcToDstHashTbl[sdp.first] = sdp.second;
        dstToSrcHashTbl[sdp.second] = sdp.first;
    }

    string src;
    // The src->dst pair map and dst->src reverse map will be set up such
    // 1. journey source will occur once as key in main map
    // 2. journey source will not occur as key in reverse map
    // 3. journey destination will occur as value once in main map
    // 4. journey destination will not occur as key in main map

    // Using above thesis, journey source would be the key which is not
    // found in reverse map while iterating over entire main map keys
    // and searching for same in reverse map
    for (vecSzT i = 0; i != srcDstPairs.size(); ++i) {
        const pair<string, string>& sdp = srcDstPairs[i];
        const string& key = sdp.first;
        if (dstToSrcHashTbl.find(key) == dstToSrcHashTbl.end()) {
            // Journey source found, key in map which is not in reverse map
            src = key;
            break;
        }
    }

    // Commence from the journey source, and use it to find intermediate
    // points on the path using srcToDstHashTbl successively; till journey
    // destination is hit (a key which is not found in main map)
    string path;
    while (srcToDstHashTbl.find(src) != srcToDstHashTbl.end()) {
        string dst = srcToDstHashTbl[src];
        path += src + "->" + dst + ", "; // Add src-> dst pair to path
        src = dst; // Update src to move along the path
    }

    return path;
}
