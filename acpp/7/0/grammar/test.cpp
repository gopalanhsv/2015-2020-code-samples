// System includes
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

// Local includes
#include "sentenceGenerator.h"

// Using declarations
using std::string;
using std::vector;
using std::ostream;
using std::domain_error;
using std::cin;
using std::cout;
using std::endl;

void
displayVec(ostream& os, const vector<string>& v) {
    if (!os) {
        throw domain_error("Error! Errored o/p stream! Exiting...!");
    }

    if (v.empty()) {
        throw domain_error("Error! Empty sentence generated! Exiting...!");
    }

    vector<string>::const_iterator iter = v.begin();
    os << endl << *iter;
    ++iter;
    for (; iter != v.end(); ++iter) {
        os << " " << *iter;
    }
    os << endl;
}

int
main() {
    initSentenceGenerator();
    try {
        GrammarT g = readGrammar(cin, cout);

        vector<string> v;
        try {
            v = genSentence(g);
        } catch (domain_error e) {
            cout << e.what() << endl;
            return 1;
        }

        try {
            displayVec(cout, v);
        } catch (domain_error e) {
            cout << e.what() << endl;
            return 1;
        }

    } catch (domain_error e) {
        cout << e.what() << endl;
        return 1;
    }

}
