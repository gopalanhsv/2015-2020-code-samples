#ifndef _HCAT_H_
#define _HCAT_H_

// System headers
#include <string>

// Local includes
#include "../Vec/Vec.h"

std::string::size_type
width(const Vec<std::string>&);

Vec<std::string>
hcat(const Vec<std::string>&, const Vec<std::string>&); 

#endif /* _HCAT_H_ */
