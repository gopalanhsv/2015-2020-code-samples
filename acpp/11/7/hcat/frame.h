#ifndef _FRAME_H_
#define _FRAME_H_

// System headers
#include <string>

// Local includes
#include "../Vec/Vec.h"

// Returns the length of longest string in vector
std::string::size_type
width(const Vec<std::string>&); 

// Returns a vector framing the given vector
Vec<std::string>
frame(const Vec<std::string>&);

#endif /* _FRAME_H_ */
