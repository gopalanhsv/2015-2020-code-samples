#ifndef _SCS_LEN_H_
#define _SCS_LEN_H_

// System headers
#include <string>
#include <vector>

// Local includes

// Using declarations

// Statics, typedefs, globals

// Finds the shortest common supersequence of specified 2 strings
std::string::size_type
scsLenBruteForce(const std::string& s1, const std::string& s2);

// Finds the shortest common supersequence of specified 2 strings
std::string::size_type
scsLenDPMemoization(const std::string& s1, const std::string& s2);

// Finds the shortest common supersequence of specified 2 strings
std::string::size_type
scsLenDPTabulation(const std::string& s1, const std::string& s2);

#endif /* _SCS_LEN_H_ */
