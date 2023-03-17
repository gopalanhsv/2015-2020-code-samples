#ifndef _SENTENCE_GENERATOR_H_
#define _SENTENCE_GENERATOR_H_

// System headers
#include <string>
#include <vector>
#include <list>
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

// Generates a sentence using the given grammar table
std::list<std::string> genSentence(const GrammarT&);

void initSentenceGenerator();

#endif /* _SENTENCE_GENERATOR_H_ */
