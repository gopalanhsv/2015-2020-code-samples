#include <iostream>
#include <string>
#include <list>
#include <stdexcept>

#include "palindrome.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::list;
using std::istream;
using std::ostream;
using std::domain_error;

istream&
readLines(istream& in, list<string>& lines) {
    if (in) {
        lines.clear();
        string line;
        while (getline(in, line))
            lines.push_back(line);
        in.clear();
    }
    return in;
}

string
extractPalindromes(list<string>& lines) {
    if (0 == lines.size()) {
        throw domain_error("Error! Nil input strings! Exiting...!");
    }

    list<string>::iterator iter = lines.begin();
    list<string>::iterator endIter = lines.end();
    string longestPalindrome;
    while (iter != endIter) {
        const string& s = *iter;
        if (!isPalindrome(s)) {
            iter = lines.erase(iter);
        } else {
            if (s.size() > longestPalindrome.size()) {
                longestPalindrome = s;
            }
            ++iter;
        }
    }
    return longestPalindrome;
}

void
printList(ostream& os, const list<string>& lines) {
    if (!os) {
        throw domain_error("Error! Errored o/p stream! Exiting...!");
    }

    list<string>::const_iterator iter = lines.begin();
    list<string>::const_iterator endIter = lines.end();
    for (; iter != endIter; ++iter) {
        os << *iter << endl;
    }
}

int
main() {
    // Read all lines from input and store into list
    list<string> lines;
    readLines(cin, lines);

    // Extract all palindromes (dump all non palindromes)
    try {
        string lp = extractPalindromes(lines);
        if (0 == lines.size()) {
            cout << "No Palindrome found " << endl;
            return 0;
        } else {
            cout << "Longest Palindrome is " << endl << lp << endl;
        }
    } catch (domain_error e) {
        cout << e.what() << endl;
        return 1;
    }

    // Print all palindromes found
    try {
        printList(cout, lines);
    } catch (domain_error e) {
        cout << e.what() << endl;
        return 1;
    }

    return 0;
}
