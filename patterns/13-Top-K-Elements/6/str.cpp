// System headers
#include <string>
#include <unordered_map>
#include <queue>
#include <vector>
#include <utility>

// Local includes
#include "str.h"

// Using declarations
using std::string;
using std::unordered_map;
using std::vector;
using std::priority_queue;
using std::domain_error;
using std::pair;

// Statics, typedefs, globals

string
Str::sortStrInOrderOfCharFrequency(const string& s) {
    if (0 == s.size()) {
        throw domain_error("Error! Empty input string!");
    }

    // Create a hash table which maintains an occurrence
    // frequency count for each character in input string
    unordered_map<char, unsigned int> strChrFreqCntTbl;
    for (auto c : s) {
        strChrFreqCntTbl[c]++;
    }

    // Since input string needs to be sorted in the descending order of its
    // character frequency count, insert the string characters (from its
    // frequency table) to a priority queue which maintains the
    // [character, frequency count] tuple in the order of decreasing
    // frequency count - i.e. max heap
    typedef pair<char, unsigned int> chrFreqCntPairT;
    struct ChrFreqCntCmp {
        bool operator() (const chrFreqCntPairT& p1, const chrFreqCntPairT& p2) {
            return p1.second < p2.second;
        }
    };
    priority_queue<chrFreqCntPairT,
        vector<chrFreqCntPairT>, ChrFreqCntCmp> maxHeap;
    for (auto chrFreqCntPair : strChrFreqCntTbl) {
        maxHeap.push(chrFreqCntPair);
    }

    // Now pop off the [character, frequency count] tuple entries from the max
    // heap and use it to build the sorted string in order of descending char
    // frequency count
    string sortedStr;
    while (!maxHeap.empty()) {
        auto chrFreqCntPair = maxHeap.top();
        maxHeap.pop();
        sortedStr += string(chrFreqCntPair.second, chrFreqCntPair.first);
    }

    return sortedStr;
}
