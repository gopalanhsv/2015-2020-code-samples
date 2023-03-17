// Sytem includes
#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
#include <cctype>

// Local includes

// Using declarations
using std::string;
using std::equal;
using std::remove_copy_if;
using std::transform;
using std::back_inserter;
using std::cin;
using std::cout;
using std::endl;

bool
isNotAlpha(char c) {
    return !isalpha(c);
}

char
toUpper(char c) {
    return toupper(c);
}

bool
isPalindrome(const string& s) {
    // Generate a stripped string from original
    // string of all non-alphabetic stuff
    string ss;
    remove_copy_if(s.begin(), s.end(), back_inserter(ss), isNotAlpha);
    // Transform all characters in string to upper case
    string ssuc;
    transform(ss.begin(), ss.end(), back_inserter(ssuc), toUpper);
    // Null processed string, return non-palindrome
    if (ssuc.empty())
        return false;

    // Check for processed string equality from front
    // and back
    return equal(ssuc.begin(), ssuc.end(), ssuc.rbegin());
}

int
main() {
    string s;
    cout << "Enter a string : "; 
    getline(cin, s);

    cout << endl;
    string result = isPalindrome(s) ? " is " : " is not ";
    cout << s << result <<  "a palindrome" << endl;

    return 0;
}
