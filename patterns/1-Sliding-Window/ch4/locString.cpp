// System headers
#include <string>
#include <vector>
#include <stdexcept>
#include <unordered_map>

// Local includes
#include "locString.h"

// Using declarations
using std::string;
using std::vector;
using std::unordered_map;
using std::domain_error;

// Statics, typedefs, globals
typedef string::size_type strSzT;

vector<strSzT>
String::locateWordConcatPermutations(const string& s,
    const vector<string>& words) {
    if (s.empty() || words.empty()) {
        throw domain_error("Error! Invalid input string/word vector!");
    }

    // Populate hash table maintaining frequency count of words
    // whose different concatenations are to be located
    unordered_map<string, unsigned> wordFreqTbl;
    for (auto w : words) {
        wordFreqTbl[w]++;
    }

    // Vector with start locations of the word concatenations
    vector<strSzT> wordConcatLocationV;
    // All words are of same length
    strSzT wordLen = words[0].size();
    // Number of words
    typedef vector<string>::size_type vecSzT;
    vecSzT nWords = words.size();
    // Iterate over each character of string sequentially. At each character
    // of string, search if the next nWords of wordLen each (word concatenation
    // commencing at that character) find an exact match in the hash table
    strSzT idxOfLastCharForWordConcat = s.size() - (wordLen * nWords);
    for (strSzT strIdx = 0; strIdx <= idxOfLastCharForWordConcat; ++strIdx) {
        // Hash table of words commencing from current string location
        unordered_map<string, unsigned> locatedWordsFreqTbl;
        bool wordFreqCntMismatch = false;
        bool wordMismatch = false;
        // Iterate over all words in the concatenation and search for them
        for (vecSzT j = 0; j != nWords; ++j) {
            // Compute location of word to be searched for and find the word
            // located in the string
            strSzT wordLoc = strIdx + (j * wordLen);
            string word = s.substr(wordLoc, wordLen);
            // Search for word in word concatenation freq table
            if (wordFreqTbl.find(word) == wordFreqTbl.end()) {
                wordMismatch = true;
                break;
            }
            // Word found. Increment frequency count
            locatedWordsFreqTbl[word]++;
            // Check if word frequency count exceeds its permissible
            // value as per the word concatenation
            if (locatedWordsFreqTbl[word] > wordFreqTbl[word]) {
                wordFreqCntMismatch = true;
                break;
            }
        }

        // Word concatenation found => store start location
        if (!wordMismatch && !wordFreqCntMismatch) {
            wordConcatLocationV.push_back(strIdx);
        }
    }

    return wordConcatLocationV;
}
