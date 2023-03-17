// System headers
#include <vector>
#include <string>
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

vector<string::size_type>
String::findAnagrams(const string& s, const string& pattern) {
    if (s.empty()) {
        throw domain_error("Error! Empty input string!");
    }
    if (pattern.empty()) {
        throw domain_error("Error! Empty input pattern!");
    }
    if (pattern.size() > s.size()) {
        throw domain_error("Error! Pattern is larger than string!");
    }

    // Populate hash table maintaining frequency count
    // of each char of search pattern
    unordered_map<char, int> patternCharFreqTbl;
    for (auto c : pattern) {
        patternCharFreqTbl[c]++;
    }

    // Vector holding all start locations of anagrams of
    // pattern in the given string
    vector<strSzT> anagramLocV;

    // Search for pattern in string by using a sliding window.
    strSzT winStart = 0;
    // Counter which is incremented only if all occurences of a
    // pattern character are matched
    unsigned patternCharMatchCnt = 0;
    // Examine if the pattern exists in the sliding window
    // range [winStart, winEnd]. Extend sliding window to the
    // right by one step in each iteration
    for (strSzT winEnd = 0; winEnd != s.size(); ++winEnd) {
        // Right most char of sliding window
        char rtMostChar = s[winEnd];

        // Right most char if present in search pattern
        if (patternCharFreqTbl.find(rtMostChar) != patternCharFreqTbl.end()) {
            // Decrement frequency count to account for presence of
            // char in search pattern
            patternCharFreqTbl[rtMostChar]--;

            if (patternCharFreqTbl[rtMostChar] == 0) {
                // All occurences of righmost char are matched to search
                // pattern character within current window/substring 
                ++patternCharMatchCnt;
                // All occurences of all chars of pattern are matched
                // to characters within the current window
                if (patternCharMatchCnt == patternCharFreqTbl.size()) {
                    // Complete match, current window is permutation/anagram
                    // of search pattern
                    anagramLocV.push_back(winStart);
                }
            }

            // Window size computation
            strSzT winSize = winEnd - winStart + 1;

            // Shrink sliding window by one character from left if its size
            // exceeds/equals search pattern size
            if (winSize >= pattern.size()) {
                // Left most char moved out of sliding window
                char leftMostChar = s[winStart++];
                // Check for left most char presence in search pattern
                if (patternCharFreqTbl.find(leftMostChar) !=
                    patternCharFreqTbl.end()) {
                    // Left most character present in pattern

                    // Account for mismatch between leftmost char occurence
                    // in sliding window and search pattern
                    if (patternCharFreqTbl[leftMostChar] == 0) {
                        --patternCharMatchCnt;
                    }
                    // Update left most frequency count to account for it
                    // being moved out of window
                    patternCharFreqTbl[leftMostChar]++;
                }
            }

        } else {
            // Righmost char not present in pattern. Shrink window to 0 size
            // as anagram cannot exist in window due to non matching char.
            while (winStart <= winEnd) {
                // Left most char moved out of sliding window
                char leftMostChar = s[winStart++];
                // Check for left most char presence in search pattern
                if (patternCharFreqTbl.find(leftMostChar) !=
                    patternCharFreqTbl.end()) {
                    // Left most character present in pattern

                    // Account for mismatch between leftmost char occurence
                    // in sliding window and search pattern
                    if (patternCharFreqTbl[leftMostChar] == 0) {
                        --patternCharMatchCnt;
                    }
                    // Update left most frequency count to account for it
                    // being moved out of window
                    patternCharFreqTbl[leftMostChar]++;
                }
            }
        }
    }

    return anagramLocV;
}
