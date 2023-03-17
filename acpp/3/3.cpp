#include <iostream>
#include <string>
#include <vector>

// Using declarations
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int
main() {

    // Maintain 2 vectors one of which stores the word - wordVec and
    // other which maintains count of the word stored in wordVec at the
    // same index
    vector<string> wordVec;
    vector<int> wordCount;

    // Read each word from the input till eof encountered
    typedef vector<string>::size_type strVecSzT;
    typedef vector<int>::size_type intVecSzT;
    string x;
    // Invariant : wordVec contains all distinct words seen so far and
    // wordCount has the count of the words seen at identical index
    while (cin >> x) {
        bool found = false;
        // Search for the read word in wordVec
        strVecSzT i;
        intVecSzT j;
        for (i = 0, j = 0; i != wordVec.size(); ++i, ++j) {
        //for (strVecSzT i = 0, intVecSzT j = 0; i != wordVec.size(); ++i, ++j) {
            // Word found. Increment corresponding entry in wordCount
            if (x == wordVec[i]) {
                wordCount[j] += 1;
                found = true;
                break;
            }
        }
        // If word not found in wordVec (i.e first occurence of word), add the word
        // to wordVec and set count in wordCount
        if (!found) {
            wordVec.push_back(x);
            wordCount.push_back(1);
        }
    }

    // Separate the input and output
    cout << endl;

    // Output words with the correspond counts
    strVecSzT i;
    intVecSzT j;
    for (i = 0, j = 0; i != wordVec.size(); ++i, ++j) {
        cout << wordVec[i] << "    " << wordCount[j] << endl;
    }

    return 0;
}
