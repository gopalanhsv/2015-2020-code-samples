#ifndef _LOCAL_STRING_H_
#define _LOCAL_STRING_H_

// System headers
#include <string>
#include <vector>

class String {
public:
    static std::vector<std::string::size_type>
        locateWordConcatPermutations(const std::string& s,
            const std::vector<std::string>& words);
private:
};

#endif /* _LOCAL_STRING_H_ */
