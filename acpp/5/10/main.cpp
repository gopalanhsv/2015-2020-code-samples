#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

#include "palindrome.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

int
main() {
    // Read a line of characters
    string s;
    getline(cin, s);
    if (0 == s.size()) {
        cout << "Empty input string" << endl;
        return 1;
    }
    if (isPalindrome(s)) {
        cout << s << " is a palindrome" << endl;
    } else {
        cout << s << " is not a palindrome" << endl;
    }
    return 0;
}
