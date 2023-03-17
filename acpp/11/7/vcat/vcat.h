#ifndef _VCAT_H_
#define _VCAT_H_

// System headers
#include <string>

// Local includes
#include "../Vec/Vec.h"

// Returns a character picture with the top vector of strings
// stacked above the bottom vector
Vec<std::string>
vcat(const Vec<std::string>&, const Vec<std::string>&);

#endif /* _VCAT_H_ */
