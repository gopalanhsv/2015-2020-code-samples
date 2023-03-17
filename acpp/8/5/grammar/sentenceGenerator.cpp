// System headers
#include <string>
#include <vector>
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
using std::map;
using std::domain_error;
using std::logic_error;
using std::istream;
using std::ostream;
using std::endl;
using std::rand;
using std::back_inserter;

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
initSentenceGenerator() {
    // Set a seed for the random number generator
    srand(time(NULL));
}
