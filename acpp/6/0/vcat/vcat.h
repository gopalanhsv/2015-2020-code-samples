#ifndef _VCAT_H_
#define _VCAT_H_

// System includes
#include <string>
#include <vector>

// Local includes

// Vertically concatenate the given two pictures (vectors of strings)
// by stacking one of top of the other
std::vector<std::string>
vcat(const std::vector<std::string>&, const std::vector<std::string>&);

#endif /* _VCAT_H_ */
