#ifndef _SENTENCE_GENERATOR_H_
#define _SENTENCE_GENERATOR_H_

// System headers
#include <string>
#include <vector>
#include <map>
#include <iostream>

// Local includes

// Using declarations

// Typedefs, globals
typedef std::vector<std::string> RuleT;
typedef std::vector<RuleT> RuleCollectionT;
typedef std::map<std::string, RuleCollectionT> GrammarT;

// Reads input lines and generates a grammar table
GrammarT readGrammar(std::istream&, std::ostream&);

// Checks if given string is bracketed (i.e. is a Rule)
// and needs to be checked in grammar table for expansion
bool bracketed(const std::string&);

// Generates a random number in the range [0, n)
unsigned long nrand(unsigned long);

template<class OutIter>
void
genAux(const GrammarT& g, const std::string& word, OutIter sentenceIter) {
    if (!bracketed(word)) {
        // Given word not a rule/category; so added to sentence
        // without any expansion
        *sentenceIter++ = word;
    } else {
        // Given word is a rule/category; so requires lookup
        // in grammar table followed by rule/category expansion
        GrammarT::const_iterator iter = g.find(word);

        // Rule lookup failure handling
        if (iter == g.end()) {
            using std::logic_error;
            throw logic_error("Error! Rule not found in grammar! Exiting...!");
        }

        // Lookup the collection of rules associated with
        // the category in the grammar
        const RuleCollectionT& rc = iter->second;
        // Select a rule randomly from rule collection 
        const RuleT& r = rc[nrand(rc.size())];
        // Recursively perform rule expansion for the selected rule
        for (RuleT::const_iterator rIter = r.begin(); rIter != r.end(); ++rIter) {
            genAux(g, *rIter, sentenceIter);
        }
    }
}

// Generates a sentence using the given grammar table
template<class T>
void
genSentence(const GrammarT& g, T& sentence) {
    genAux(g, "<sentence>", std::back_inserter(sentence));
}

void initSentenceGenerator();

#endif /* _SENTENCE_GENERATOR_H_ */
