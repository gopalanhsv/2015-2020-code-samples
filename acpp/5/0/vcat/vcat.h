#ifndef _VCAT_H_
#define _VCAT_H_

#include <string>
#include <vector>

// Returns a character picture with the top vector of strings
// stacked above the bottom vector
std::vector<std::string>
vcat(const std::vector<std::string>&, const std::vector<std::string>&);

#endif /* _VCAT_H_ */
