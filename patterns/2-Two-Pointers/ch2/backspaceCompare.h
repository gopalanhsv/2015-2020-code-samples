#ifndef _BACKSPACE_COMPARE_H_
#define _BACKSPACE_COMPARE_H_

// System headers
#include <string>

// Statics, typedefs, globals

class BackspaceCompare {
public:
    static bool compare(const std::string& s1, const std::string& s2);
private:
    static std::string::size_type getPreviousCharIdxAfterBackspace(
        const std::string& s, std::string::size_type currIdx);
};

#endif /* _BACKSPACE_COMPARE_H_ */
