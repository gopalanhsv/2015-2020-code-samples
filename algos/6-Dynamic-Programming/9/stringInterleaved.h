#ifndef _STRING_INTERLEAVED_H_
#define _STRING_INTERLEAVED_H_

// System headers
#include <string>

// Local includes

// Using declarations

// Statics, typedefs, globals

// Find if the string 'strToChk' is formed by interleaving characters
// in order from the component strings 's1' and 's2'
bool
isStringFormedByInterleavingBruteForce(const std::string& s1,
    const std::string& s2, const std::string& strToChk);

// Find if the string 'strToChk' is formed by interleaving characters
// in order from the component strings 's1' and 's2'
bool
isStringFormedByInterleavingDPMemoization(const std::string& s1,
    const std::string& s2, const std::string& strToChk);

// Find if the string 'strToChk' is formed by interleaving characters
// in order from the component strings 's1' and 's2'
bool
isStringFormedByInterleavingDPTabulation(const std::string& s1,
    const std::string& s2, const std::string& strToChk);

// Find if the string 'strToChk' is formed by interleaving characters
// in order from the component strings 's1' and 's2'
bool
isStringFormedByInterleavingDPOptimized(const std::string& s1,
    const std::string& s2, const std::string& strToChk);

#endif /* _STRING_INTERLEAVED_H_ */
