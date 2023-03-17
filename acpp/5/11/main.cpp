#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdexcept>
#include "ascenderDescender.h"

using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::ostream;
using std::vector;
using std::string;
using std::max;
using std::domain_error;

istream&
readWords(istream& in, vector<string>& words) {
    if (in) {
        words.clear();
        string x;
        while (in >> x) {
            words.push_back(x);
        }
        in.clear();
    }
    return in;
}

string
longestWordWithoutAscDsc(const vector<string>& words) {
    if (0 == words.size()) {
        throw domain_error("Error! No input words! Exiting...!");
    }

    string longest;
    for (vector<string>::size_type i = 0; i != words.size(); ++i) {
        const string& s = words[i];
        if (!hasAscendersOrDescenders(s)) {
            if (s.size() > longest.size()) {
                longest = s;
            }
        }
    }

    return longest;
}

void
printAscDscWords(ostream& os, const vector<string>& words) {
    if (0 == words.size()) {
        throw domain_error("Error! No input words! Exiting...!");
    }

    if (!os) {
        throw domain_error("Error! O/p stream in error state! Exiting...!");
    }

    for (vector<string>::size_type i = 0; i != words.size(); ++i) {
        if (hasAscendersOrDescenders(words[i])) {
            os << words[i] << endl;
        }
    }
}

int
main() {
    // Read words into vector from input
    vector<string> words;
    readWords(cin, words);
    // Find the longest word in input dictionary
    // w/o ascenders or descenders
    try {
        string s = longestWordWithoutAscDsc(words);
        if (0 == s.size()) {
            cout << "All words have ascenders or descenders" << endl;
        } else {
            cout << "Longest word w/o ascender or descender "
                "in dictionary is " << s << endl;
        }
        printAscDscWords(cout, words);
    } catch (domain_error e) {
        cout << e.what() << endl;
        return 1;
    }
    return 0;
}
