#ifndef _EXPRESSION_H_
#define _EXPRESSION_H_

// System headers
#include <string>
#include <vector>

// Local includes
// Using declarations
// Statics, typedefs, globals

class Expression {
public:
    static std::vector<long>
        computeAllPossibleOutputs(const std::string& exprStr);
    static std::vector<long>
        computeAllPossibleOutputsDP(const std::string& exprStr);

private:
    static std::vector<long>
        computeAllPossibleOutputsRecursive(const std::string& exprStr);
    static std::vector<long>
        computeAllPossibleOutputsRecursiveDP(const std::string& exprStr);
};

#endif /* _EXPRESSION_H_ */
