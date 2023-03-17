// System includes
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <stdexcept>
#include <iterator>

// Local includes
#include "sentenceGenerator.h"

// Using declarations
using std::string;
using std::vector;
using std::list;
using std::ostream;
using std::domain_error;
using std::cin;
using std::cout;
using std::endl;

template<typename T>
void
displaySentence(ostream& os, const T& s) {
    if (!os) {
        throw domain_error("Error! Errored o/p stream! Exiting...!");
    }

    if (s.empty()) {
        throw domain_error("Error! Empty sentence generated! Exiting...!");
    }

    os << endl;
    copy(s.begin(), s.end(), std::ostream_iterator<string>(os, " "));
    os << endl;
}

int
main() {
    initSentenceGenerator();
    try {
        GrammarT g = readGrammar(cin, cout);

#ifdef USE_LIST
        list<string> v;
#elif USE_VECTOR
        vector<string> v;
#else
        #error "Define either -DUSE_LIST or -DUSE_VECTOR during compilation"
#endif

        try {
            genSentence(g, v);
        } catch (domain_error e) {
            cout << e.what() << endl;
            return 1;
        }

        try {
            displaySentence(cout, v);
        } catch (domain_error e) {
            cout << e.what() << endl;
            return 1;
        }

    } catch (domain_error e) {
        cout << e.what() << endl;
        return 1;
    }

}
