#ifndef _CENTER_H_
#define _CENTER_H_

#include <string>
#include <vector>

// Returns the length of longest string in vector
std::string::size_type
width(const std::vector<std::string>&); 

// Returns a vector framing the given vector
std::vector<std::string>
center(const std::vector<std::string>&);

#endif /* _CENTER_H_ */
