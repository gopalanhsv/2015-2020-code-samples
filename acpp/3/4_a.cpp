#include <iostream>
#include <string>
#include <vector>

// Using declarations
using std::cin;
using std::cout;
using std::endl;
using std::string;

int
main() {
    // Read all the words
    string x, longest, shortest;
    // Read first word and init both shortest and longest
    if (cin >> x) {
        longest = shortest = x;
    }
    // Invariant : longest has longest word read so far and
    // shortest has shortest word read so far
    while (cin >> x) {
        longest = (x.size() > longest.size()) ? x : longest;
        shortest = (x.size() < shortest.size()) ? x : shortest;
    } 

    // Error in case no words seen
    if (!x.size()) {
        cout << "Error! No words entered! Exiting...!" << endl;
        return 1;
    }

    cout << endl;
    cout << "Shortest word is " << shortest << " of length " <<
        shortest.size() << endl;
    cout << "Longest word is " << longest << " of length " <<
        longest.size() << endl;

    return 0;
}
