#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// Using declarations
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::sort;

bool
compare(const string& x1, const string& x2) {
    return x1.size() < x2.size();
}

int
main() {
    // Read all the words and store in into a vector
    vector<string> words;
    string x;
    // Invariant : words vector has all the words read so far
    while (cin >> x) {
        words.push_back(x);
    } 

    // Error in case no words seen
    if (!words.size()) {
        cout << "Error! No words entered! Exiting...!" << endl;
        return 1;
    }

    // Sort the vector of words
    sort(words.begin(), words.end(), compare);

    // First entry of sorted vector will be the smallest word
    // and last entry would be the longest word
    cout << endl;
    cout << "Shortest word is " << words[0] << " of length " <<
         words[0].size() << endl;
    cout << "Longest word is " << words[words.size() - 1] << " of length " <<
         words[words.size() - 1].size() << endl;

    return 0;
}
