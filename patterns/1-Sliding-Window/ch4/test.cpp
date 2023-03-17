// System headers
#include <vector>
#include <string>
#include <iostream>
#include <stdexcept>
#include <iterator>
#include <algorithm>

// Local includes
#include "locString.h"

// Using declarations
using std::cin;
using std::cout;
using std::endl;
using std::domain_error;
using std::string;
using std::vector;
using std::istream_iterator;
using std::ostream_iterator;
using std::back_inserter;
using std::copy;

// Statics, typedefs, globals

template <typename T>
T
readInput(const string& s) {
    T x;
    while (1) {
        cout << s;
        if (cin >> x) {
            break;
        }
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Try again!!!" << endl;
    }
    return x;
}

void
readVec(vector<string>& vs) {
    vs.clear();
    copy(istream_iterator<string>(cin), istream_iterator<string>(),
        back_inserter(vs));
}

template<typename T>
void
printVec(const vector<T>& vs) {
    cout << endl;
    copy(vs.begin(), vs.end(), ostream_iterator<T>(cout, " "));
    cout << endl;
}

void
test() {
    string s = readInput<string>("Enter input string : ");
    vector<string> words;
    cout << "Enter words of same len which will be "
        << "concatenated and searched for : " << endl;
    readVec(words);

    cout << "Input string is " << s << endl;
    cout << "Input words whose concatenations are to be searched for are : ";
    printVec(words);

    try {
        vector<string::size_type> wordLocV =
            String::locateWordConcatPermutations(s, words);
        if (wordLocV.empty()) {
            cout << "Word concatenations not found in string!" << endl;
        } else {
            cout << "Word concatenations are found in string at : ";
            printVec(wordLocV);
        }
    } catch (domain_error& e) {
        throw e;
    }
}

int
main() {
    try {
        test();
    } catch (domain_error& e) {
        cout << e.what() << endl;
        return 1;
    }
    return 0;
}
