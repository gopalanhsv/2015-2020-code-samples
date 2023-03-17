#ifndef _ARRAY_H_
#define _ARRAY_H_

// System headers
#include <vector>

class Array {
public:
    static std::vector<int>::size_type
        longestSubarrayWithAll1sPostReplacement(
            const std::vector<int>& v, unsigned maxAllowedReplacements);
private:
};

#endif /* _ARRAY_H_ */
