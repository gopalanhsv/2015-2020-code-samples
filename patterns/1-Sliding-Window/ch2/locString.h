#ifndef _LOC_STRING_H_
#define _LOC_STRING_H_

// System headers
#include <vector>
#include <string>

class String {
public:
    static std::vector<std::string::size_type>
        findAnagrams(const std::string& s, const std::string& pattern);
};

#endif /* _LOC_STRING_H_ */
