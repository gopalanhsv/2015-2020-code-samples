#include <string>
#include <vector>
#include <cctype>

#include "lowerupper.h"

using std::string;
using std::vector;
using std::string;

bool
lowerCaseOnly(const string& s) {
    for (string::size_type i = 0; i != s.size(); ++i) {
        if (isupper(s[i]))
            return false;
    }
    return true;
}

vector<string>
lcaseFollowedByUcase(const vector<string>& words) {
    vector<string> lowercase;
    vector<string> nonlowercase;
    vector<string>::const_iterator iter = words.begin();
    vector<string>::const_iterator endIter = words.end();
    for (; iter != endIter; ++iter) {
        if (lowerCaseOnly(*iter)) {
            lowercase.push_back(*iter);
        } else {
            nonlowercase.push_back(*iter);
        }
    }

    lowercase.insert(
        lowercase.end(), nonlowercase.begin(), nonlowercase.end());
    return lowercase;
}
