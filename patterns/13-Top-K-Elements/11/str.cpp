// System headers
#include <string>
#include <unordered_map>
#include <queue>
#include <vector>
#include <stdexcept>
#include <utility>

// Local includes
#include "str.h"

// Using declarations
using std::string;
using std::unordered_map;
using std::priority_queue;
using std::vector;
using std::pair;
using std::domain_error;

// Statics, typedefs, globals

string
Str::rearrangeWithNoSameAdjacentChars(const string& s) {
    if (s.empty()) {
        throw domain_error("Error! Empty input string!");
    }

    // Frequency table mapping each character of input string
    // to its occurrence count
    unordered_map<char, unsigned long> strCharFrequencyTbl;
    for (auto c : s) {
        strCharFrequencyTbl[c]++;
    }

    typedef pair<char, unsigned long> strCharOccurrenceCntT;
    struct strCharOccurrenceCntCmp {
        bool operator() (
            const strCharOccurrenceCntT& p1,
            const strCharOccurrenceCntT& p2) const {
            return p1.second < p2.second;
        }
    };
 
    // PQ/max heap maintaining string character->occurence count tuples
    // for input string, with most frequent characters at top and
    // least frequent characters at bottom. Constructed using above
    // character frequency table
    priority_queue<strCharOccurrenceCntT,
        vector<strCharOccurrenceCntT>, strCharOccurrenceCntCmp> maxHeap;
    for (auto e : strCharFrequencyTbl) {
        maxHeap.push(e);
    }

    // Attempt to construct input string rearranged in such a fashion
    // that adjacent characters or not same. Use above max heap/PQ
    // for same
    // 1 Pop off & get most frequently occurring char from heap top
    // 2 Use a character from it to add to rearranged string
    // 3 Pop off & get next most frequently occurring char from heap top
    // 4 Use a character from it to add to rearranged string (so that
    //   adjacent chars are not same)
    // 5 If the most frequently occuring character (from step 1), has
    //   some instances unused), push it back to heap with updated
    //   occurence count
    // 6. Go to step 1
    string rearrangedStr;
    strCharOccurrenceCntT prevPoppedEntry(0, 0);
    while (!maxHeap.empty()) {
        // Get most frequently occuring char in heap
        auto mostFreqHeapEntry = maxHeap.top();
        maxHeap.pop();
        // Add most frequently occuring char in heap to rearranged string
        rearrangedStr += mostFreqHeapEntry.first;
        // Update occurrence count of most frequently occuring char
        --(mostFreqHeapEntry.second);

        // Previous iteration most frequent occuring heap entry still
        // has some chars, add it back to heap
        if (prevPoppedEntry.second > 0) {
            maxHeap.push(prevPoppedEntry);
        }
        // Store the currently popped most frequently occuring heap entry
        prevPoppedEntry = mostFreqHeapEntry;
    }

    // Rearranged str with no adjacent same chars possible from original 
    if (rearrangedStr.size() == s.size()) {
        return rearrangedStr;
    }
    // Rearranged str with no adjacent same chars not possible from original 
    return "";
}
