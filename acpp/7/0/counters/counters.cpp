// System headers
#include <iostream>
#include <map>
#include <string>

// Local includes

// Using declarations
using std::map;
using std::string;
using std::cin;
using std::cout;
using std::endl;

int
main() {
    // Association from a word to its occurence count
    map<string, unsigned long> counters;

    // Read words from the input and increment the
    // respective occurence counts
    string word;
    while (cin >> word)
        ++counters[word];

    // Display the occurence count for each word seen
    // above
    cout << endl;
    for (map<string, unsigned long>::const_iterator iter = counters.begin();
        iter != counters.end(); ++iter) {
        cout << iter->first << " : " << iter->second << endl;
    }
    cout << endl;
  
    return 0;
}
