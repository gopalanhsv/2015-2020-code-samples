// System includes
#include <iostream>
#include <string>
#include <list>
#include <stdexcept>

// Local includes
#include "sentenceGenerator.h"

// Using declarations
using std::string;
using std::list;
using std::ostream;
using std::domain_error;
using std::cin;
using std::cout;
using std::endl;

void
displayList(ostream& os, const list<string>& l) {
    if (!os) {
        throw domain_error("Error! Errored o/p stream! Exiting...!");
    }

    if (l.empty()) {
        throw domain_error("Error! Empty sentence generated! Exiting...!");
    }

    list<string>::const_iterator iter = l.begin();
    os << endl << *iter;
    ++iter;
    for (; iter != l.end(); ++iter) {
        os << " " << *iter;
    }
    os << endl;
}

int
main() {
    initSentenceGenerator();
    try {
        GrammarT g = readGrammar(cin, cout);

        list<string> s;
        try {
            s = genSentence(g);
        } catch (domain_error e) {
            cout << e.what() << endl;
            return 1;
        }

        try {
            displayList(cout, s);
        } catch (domain_error e) {
            cout << e.what() << endl;
            return 1;
        }

    } catch (domain_error e) {
        cout << e.what() << endl;
        return 1;
    }

}
