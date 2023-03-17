#ifndef _LPS_LEN_H_
#define _LPS_LEN_H_

// System headers
#include <vector>
#include <string>

// Local includes

// Using declarations
using std::vector;
using std::string;

// Statics, typedefs, globals
typedef string::size_type strSzT;

// Find the length of the longest palindromic subsequence for the
// substring s[sIdx, eIdx], i.e string delimited by indices sIdx & eIdx
strSzT lpsLenBruteForce(const std::string& s);

// Find the length of the longest palindromic subsequence for the
// substring s[sIdx, eIdx], i.e string delimited by indices sIdx & eIdx
strSzT lpsLenDpMemoization(const std::string& s);

// Find the length of the longest palindromic subsequence for the
// substring s[sIdx, eIdx], i.e string delimited by indices sIdx & eIdx
strSzT lpsLenDpTabulation(const std::string& s);

#endif /* _LPS_LEN_H_ */
