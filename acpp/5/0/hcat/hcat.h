#ifndef _HCAT_H_
#define _HCAT_H_

#include <string>
#include <vector>

std::string::size_type
width(const std::vector<std::string>&);

std::vector<std::string>
hcat(const std::vector<std::string>&, const std::vector<std::string>&); 

#endif /* _HCAT_H_ */
