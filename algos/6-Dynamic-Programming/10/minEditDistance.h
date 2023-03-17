#ifndef _MIN_EDIT_DISTANCE_H_
#define _MIN_EDIT_DISTANCE_H_

// System headers
#include <string>

// Local includes

// Using declarations

// Statics, typedefs, globals

// Returns the minimum edit distance (levenstein distance to convert a
// source string s to a target string t via insert, remove, substititution)
std::string::size_type
minEditDistanceBruteForce(const std::string& s, const std::string& t);

// Returns the minimum edit distance (levenstein distance to convert a
// source string s to a target string t via insert, remove, substititution)
std::string::size_type
minEditDistanceDPMemoization(const std::string& s, const std::string& t);

// Returns the minimum edit distance (levenstein distance to convert a
// source string s to a target string t via insert, remove, substititution)
std::string::size_type
minEditDistanceDPTabulation(const std::string& s, const std::string& t);

#endif /* _MIN_EDIT_DISTANCE_H_ */
