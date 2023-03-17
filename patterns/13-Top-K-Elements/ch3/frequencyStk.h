#ifndef _FREQUENCY_STACK_H_
#define _FREQUENCY_STACK_H_

// System headers
#include <queue>
#include <vector>
#include <unordered_map>

// Local includes
// Using namespaces
// Statics, typedefs, globals

class StkElement {
public:
    // Constructor
    StkElement(int n, unsigned long f, unsigned long sn) : 
        _n(n), _frequency(f), _seqNum(sn) {}

    // Accessors
    inline unsigned long num() const { return _n; }
    inline unsigned long frequency() const { return _frequency; }
    inline unsigned long seqNum() const { return _seqNum; }

private:
    StkElement();

    // Data members
    // Element value
    int _n;
    // Occurrence count of element
    unsigned long _frequency;
    // Time stamp of latest occurence of element
    unsigned long _seqNum;
};

class FrequencyStack {
public:
    // Constructor
    FrequencyStack() : _globalSeqNum(0) {}

    // Accessors
    void push(int n);
    int pop();
    bool empty() const;

private:
    // Elements added to frequency stack are ordered in such a way such that
    // elements with higher frequency/occurrence count are at stack top
    // (tie break in case of same frequency count, elements which got added
    // latest are at stack top)
    struct StkElemCmp {
        bool operator()
            (const StkElement& se1, const StkElement& se2) const {
            // Element with greater occurence is given higher priority
            // (is at heap top)
            if (se1.frequency() < se2.frequency()) {
                return true;
            }
            // Elements with same occurence count, that which was added
            // latest (i.e. higher sequence number) is given higher priority
            if (se1.frequency() == se2.frequency()) {
                return (se1.seqNum() < se2.seqNum());
            }
            return false;
        }
    };

    // Data members
    // Max heap to order stack elements as per frequency and sequence number
    std::priority_queue<StkElement, std::vector<StkElement>, StkElemCmp>
        _maxHeap;
    // Hash table tracking occurrence count of elements
    std::unordered_map<int, unsigned long> _frequencyCntTbl;
    // Latest global timestamp (to set sequence numbers)
    unsigned long _globalSeqNum; 
};

#endif /* _FREQUENCY_STACK_H_ */
