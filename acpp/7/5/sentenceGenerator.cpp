// System headers
#include <string>
#include <vector>
#include <list>
#include <map>
#include <algorithm>
#include <stdexcept>
#include <cstdlib>
#include <ctime>

// Local includes
#include "split.h"
#include "sentenceGenerator.h"

// Using declarations
using std::string;
using std::vector;
using std::list;
using std::map;
using std::domain_error;
using std::logic_error;
using std::istream;
using std::ostream;
using std::endl;
using std::rand;

// Typedefs, globals

// Checks if given string is bracketed (i.e. is a Rule)
// and needs to be checked in grammar table for expansion
bool
bracketed(const string& s) {
    return s.size() > 2 && s[0] == '<' && s[s.size() - 1] == '>';
}

// Reads input lines and generates a grammar table
GrammarT
readGrammar(istream& is, ostream& os) {
    if (!is) {
        throw domain_error("Error! Errored i/p stream! Exiting...!");
    }

    GrammarT grammar;

    // Read input lines
    string line;
    while (getline(is, line)) {
        // Split the line into words
        vector<string> entry = split(line);
        // Skip blank lines
        if (!entry.empty()) {
            // Category word for grammar table from line
            const string& category = entry[0];
            if (!bracketed(category)) {
                os << category << " in input line " << line <<
                    " not bracketed<>" << endl;
                throw logic_error("Error! Invalid input! Exiting...!");
            }
            // Associate the rule(s) with read line category in grammar
            grammar[category].push_back(RuleT(entry.begin() + 1, entry.end()));
        }
    }

    return grammar;
}

// Generates a random number in the range [0, n)
unsigned long
nrand(unsigned long n) {
    if (0 == n || n > RAND_MAX) {
        throw domain_error("Error! Out of range input to nrand! Exiting...!");
    }

    const unsigned long bucketSize = RAND_MAX / n;
    unsigned long r;
    do {
        r = rand() / bucketSize;
    } while (r >= n);
    return r;
}

void
genAux(const GrammarT& g, const string& word, list<string>& sentence) {
    if (!bracketed(word)) {
        // Given word not a rule/category; so added to sentence
        // without any expansion
        sentence.push_back(word);
    } else {
        // Given word is a rule/category; so requires lookup
        // in grammar table followed by rule/category expansion
        GrammarT::const_iterator iter = g.find(word);

        // Rule lookup failure handling
        if (iter == g.end()) {
            throw logic_error("Error! Rule not found in grammar! Exiting...!");
        }

        // Lookup the collection of rules associated with
        // the category in the grammar
        const RuleCollectionT& rc = iter->second;
        // Select a rule randomly from rule collection 
        const RuleT& r = rc[nrand(rc.size())];
        // Recursively perform rule expansion for the selected rule
        for (RuleT::const_iterator rIter = r.begin(); rIter != r.end(); ++rIter) {
            genAux(g, *rIter, sentence);
        }
    }
}

// Generates a sentence using the given grammar table
list<string>
genSentence(const GrammarT& g) {
    list<string> sentence;
    genAux(g, "<sentence>", sentence);
    return sentence;
}

void
initSentenceGenerator() {
    // Set a seed for the random number generator
    srand(time(NULL));
}
