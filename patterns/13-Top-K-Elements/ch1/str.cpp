// System headers
#include <string>
#include <queue>
#include <vector>
#include <unordered_map>
#include <utility>
#include <stdexcept>

// Local includes
#include "str.h"

// Using declarations
using std::string;
using std::pair;
using std::unordered_map;
using std::priority_queue;
using std::queue;
using std::vector;
using std::domain_error;

// Statics, typedefs, globals

string
Str::reorderStrWithSameCharsKDistApart(const string& s, unsigned long k) {
    if (s.empty()) {
        throw domain_error("Error! Empty input string!");
    }
    // Base case, no reordering required
    if (0 == k) {
        return s;
    }

    // Table maintaining frequency/occurrence count of each char in input str
    unordered_map<char, unsigned long> strCharFrequencyTbl;
    for (char c : s) {
        strCharFrequencyTbl[c]++;
    }

    // Max heap maintaining input string char, occurrence count tuples ordered
    // with most frequently occurring characters at heap top; and least frequently
    // occurring chars at heap bottom
    typedef pair<char, unsigned long> strCharOccurCntT;
    struct strCharOccurCntCmp {
        bool operator() (
            const strCharOccurCntT& p1, const strCharOccurCntT& p2) {
            // Higher frequency chars have higher priority
            return p1.second < p2.second;
        }
    };
    priority_queue<strCharOccurCntT,
        vector<strCharOccurCntT>, strCharOccurCntCmp> maxHeap;
    for (auto e : strCharFrequencyTbl) {
        maxHeap.push(e);
    }

    // Stores char, frequency count tuples from heap in order to have a distance
    // of k elements between same chars in rearranged string
    queue<strCharOccurCntT> kDistQ;

    string reorderedStr;
    while (!maxHeap.empty()) {
        // Pop most frequently occurring char
        strCharOccurCntT entry = maxHeap.top();
        maxHeap.pop();
        // Add char to reordered string and update its frequency
        reorderedStr += entry.first;
        entry.second--;
        // Enqueue popped char to wait Q, so that [char, frequency cnt]
        // tuple is seen after only another k elements from heap have
        // been processed (Note that even if the tuple frequency count
        // becomes 0, as a result of all instances of same char being
        // processed; the entry is still added to Q to track that k
        // count of elements have been seen)
        kDistQ.push(entry);

        if (k == kDistQ.size()) {
            // Wait Q has "k" elements, implies k chars have elapsed
            // since the char at Q front has been seen. Pop tup at Q front
            // and add it to heap, so that it occurs after min distance k
            entry = kDistQ.front();
            kDistQ.pop();
            // Tuple added to heap only if its count is valid
            if (entry.second > 0) {
                maxHeap.push(entry);
            }
        }
    }

    // If reorder string have same size as original, it was possible to
    // reorder string with same chars k distance apart
    return (reorderedStr.size() == s.size()) ? reorderedStr : "";
}
