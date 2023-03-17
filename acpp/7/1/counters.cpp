// System includes
#include <map>
#include <vector>
#include <string>
#include <iostream>

// Local includes


// Using declarations
using std::string;
using std::map;
using std::vector;
using std::cin;
using std::cout;
using std::endl;


map<int, vector<string> >
computeCountToWordsTbl(const map<string, int>& wcTbl) {
    map<int, vector<string> > cntToWordsTbl;
    typedef map<string, int>::const_iterator mapIterT;
    for (mapIterT iter = wcTbl.begin(); iter != wcTbl.end(); ++iter) {
        const string& word = iter->first;
        int count = iter->second;
        cntToWordsTbl[count].push_back(word);
    }
    return cntToWordsTbl;
}

int
main() {
    // Map from word to its occurence count
    map<string, int> counters;
    // Read each word from input & update the
    // occurence count
    string s;
    while (cin >> s) {
        ++counters[s];
    }

    // Map from occurence count to words with that
    // respective occurence count
    map<int, vector<string> > cntToWordsTbl = computeCountToWordsTbl(counters);

    // Output the ocurrence count with words showing the same
    typedef map<int, vector<string> >::const_iterator mapIterT;
    for (mapIterT mIter = cntToWordsTbl.begin();
            mIter != cntToWordsTbl.end(); ++mIter) {
        cout << endl;
        cout << "Occurence Count : " << mIter->first << endl;

        const vector<string>& vec = mIter->second;
        typedef vector<string>::const_iterator vecIterT;
        vecIterT vIter = vec.begin();
        cout << *vIter;
        ++vIter;
        for (; vIter != vec.end(); ++vIter) {
            cout << ", " << *vIter;
        }
        cout << endl << endl;
        
    }

    return 0;
}
