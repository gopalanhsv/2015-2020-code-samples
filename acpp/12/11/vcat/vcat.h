#ifndef _VCAT_H_
#define _VCAT_H_

// System headers

// Local includes
#include "../lib/Str.h"
#include "../lib/Vec.h"

// Returns a character picture with the top vector of strings
// stacked above the bottom vector
Vec<Str>
vcat(const Vec<Str>&, const Vec<Str>&);

#endif /* _VCAT_H_ */
