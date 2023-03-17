#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>

// Using declarations
using std::cin;
using std::cout;
using std::istream;
using std::endl;
using std::string;
using std::vector;
using std::sort;
using std::max;
using std::domain_error;

istream&
readWords(istream& in, vector<string>& strVec) {
    if (in) {
        // Init/flush the vector
        strVec.clear();
        string x;
        // Invariant : strVec contains all strings read so far
        while (in >> x) {
            strVec.push_back(x);
        }
        // Reset the input stream
        in.clear();
    }
    return in;
}

typedef struct _wordInfoT {
    string word;
    unsigned long count;
} wordInfoT;

void
countWords(vector<string>& w, vector<wordInfoT> & wiVec) {
    // No input words, error
    if (0 == w.size()) {
        throw domain_error("Error! No words present in input!");
    }

    // Clear the vector of wordInfoT
    wiVec.clear();

    // Sort the input words in alphabetical order, so that same
    // words line up beside each other
    sort(w.begin(), w.end());

    string currentWord("");
    wordInfoT wi;
    // Traverse the sorted vector of input words
    for (vector<string>::size_type i = 0; i != w.size(); ++i) {
        // Current word is different from last set of same word(s),
        // implies new set of word(s) commencing.
        // Add previous wordInfoT struct to to the wordInfoT vector
        // Form a wordInfoT struct for the new word.
        if (w[i] != currentWord) {
            if (currentWord != "") {
                wiVec.push_back(wi);
            }
            currentWord = w[i];
            wi.word = currentWord;
            wi.count = 1;
        } else {
            // Current word identical to last set of seen word(s),
            // so just increment word count in wordInfoT struct
            wi.count++;
        }
    }
    // Add wordInfoT struct for last set of word(s)
    wiVec.push_back(wi);

    return;
}

void
printWordInfoStats(const vector<wordInfoT>& wi) {
    // Determine the length of longest word
    string::size_type maxlen = 0;
    for (vector<wordInfoT>::size_type i = 0; i != wi.size(); ++i) {
        maxlen = max(maxlen, wi[i].word.size());
    }
    cout << endl;
    unsigned long nWords = 0;
    // Print the word padded out to maximum word length so that
    // all word frequencies are lined up in same column
    for (vector<wordInfoT>::size_type i = 0; i != wi.size(); ++i) {
        cout << wi[i].word << string(maxlen + 1 - wi[i].word.size(), ' ')
            << wi[i].count << endl;
        nWords += wi[i].count;
    }
    cout << endl;
    cout << "Total number of words = " << nWords << endl;
}

int
main() {
    vector<string> words;
    // Read words from input into vector
    readWords(cin, words);
    try {
        vector<wordInfoT> wordInfoVec;
        // Compute the frequency of input words
        countWords(words, wordInfoVec);
        // Display the frequency of input words
        printWordInfoStats(wordInfoVec);
    } catch (domain_error e) {
        cout << e.what() << endl;
        return 1;
    }

    return 0;
}
