#ifndef _FRAME_H_
#define _FRAME_H_

#include <string>
#include <vector>

// Returns the length of longest string in vector
std::string::size_type
width(const std::vector<std::string>&); 

// Returns a vector framing the given vector
std::vector<std::string>
frame(const std::vector<std::string>&);

#endif /* _FRAME_H_ */
