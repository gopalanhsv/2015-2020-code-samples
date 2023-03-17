#ifndef _NUMBER_H_
#define _NUMBER_H_

// System headers
#include <vector>
#include <utility>

class Number {
public:
    static std::pair<unsigned int, unsigned int>
    findTwoUniqueNumbers(const std::vector<unsigned int>& v);
};

#endif /* _NUMBER_H_ */
