// System headers
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>

// Local includes
#include "trie.h"

// Using declarations
using std::cin;
using std::cout;
using std::endl;
using std::domain_error;
using std::string;
using std::vector;
using std::istream_iterator;
using std::ostream_iterator;
using std::copy;
using std::back_inserter;

// Statics, typedefs, globals
void
readVec(vector<string>& vs) {
    vs.clear();
    string s;
    copy(istream_iterator<string>(cin), istream_iterator<string>(),
        back_inserter(vs));
    cin.clear();
}

void
testSearch(Trie *t) {
    string x;
    cout << endl << "Enter string to search in trie : ";
    cin >> x;
    bool b = t->searchNode(x);
    cout << endl << x << " is" << (b ? "" : " not") << " present in trie";
}

void
testDelete(Trie *t) {
    string x;
    cout << endl << "Enter string to delete from trie : ";
    cin >> x;
    bool b = t->deleteNode(x);
    cout << endl << x << " is" << (b ? "" : " not") << " deleted from trie";
}

void
testInsertAndSearch() {
    cout << "Enter strings to be inserted in trie :";
    vector<string> vs;
    readVec(vs);

    Trie* t = new Trie();
    typedef vector<string>::size_type vecSzT;
    for (vecSzT i = 0; i != vs.size(); ++i) {
        t->insertNode(vs[i]);
    }

    int opt;
    cout << "Enter 1 for search, 2 for delete, 3 to exit" << endl;
    while (cin >> opt && 3 != opt) {
        switch (opt) {
            case 1:
                testSearch(t);
                break;
            case 2:
                testDelete(t);
                break;
            case 3:
                break;
        }
        cout << endl << "Enter 1 for search, 2 for delete, 3 to exit";
    }
}

int
main() {
    try {
        testInsertAndSearch();
    } catch (domain_error& e) {
        cout << e.what() << endl;
        return 1;
    }
    return 0;
}
