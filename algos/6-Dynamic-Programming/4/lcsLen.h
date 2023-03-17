#ifndef _LCS_LEN_H_
#define _LCS_LEN_H_

// System headers
#include <string>

// Local includes

// Using declarations

// Statics, typedefs, globals

// Determine the length of the longest common substring of given
// 2 strings
std::string::size_type
longestCommonSubstrLenBruteForce(
    const std::string& s1, const std::string& s2);

// Determine the length of the longest common substring of given
// 2 strings
std::string::size_type
longestCommonSubstrLenDPMemoization(
    const std::string& s1, const std::string& s2);

// Determine the length of the longest common substring of given
// 2 strings
std::string::size_type
longestCommonSubstrLenDPTabulation(
    const std::string& s1, const std::string& s2);

// Determine the length of the longest common substring of given
// 2 strings
std::string::size_type
longestCommonSubstrLenDPTabulationOptimized(
    const std::string& s1, const std::string& s2);

#endif /* _LCS_LEN_H_ */

