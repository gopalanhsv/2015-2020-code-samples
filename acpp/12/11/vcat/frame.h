#ifndef _FRAME_H_
#define _FRAME_H_

// System headers

// Local includes
#include "../lib/Str.h"
#include "../lib/Vec.h"

// Returns the length of longest string in vector
Str::size_type
width(const Vec<Str>&); 

// Returns a vector framing the given vector
Vec<Str>
frame(const Vec<Str>&);

#endif /* _FRAME_H_ */
