// System headers
#include <string>
#include <vector>
#include <unordered_map>
#include <stdexcept>

// Local includes
#include "expression.h"

// Using declarations
using std::string;
using std::vector;
using std::unordered_map;
using std::domain_error;

// Statics, typedefs, globals

// Hash table maintaining mapping of expression string to its
// computed outputs (for use in DP memoization table)
unordered_map<string, vector<long> > dpMemoizationTbl;

bool
checkExprValidity(const string& exprStr) {
    for (auto ch : exprStr) {
        if (isdigit(ch) || '+' == ch || '-' == ch || '*' == ch) {
            continue;
        }
        return false;
    }
    // Avoid operators at expression ends
    if (!isdigit(exprStr[0]) || !isdigit(exprStr[exprStr.size() - 1])) {
        return false;
    }
    return true;
}

vector<long>
Expression::computeAllPossibleOutputs(const string& exprStr) {
    if (exprStr.empty()) {
        throw domain_error("Error! Empty input expression string!");
    }
    if (!checkExprValidity(exprStr)) {
        throw domain_error("Error! Invalid input expression!");
    }

    return computeAllPossibleOutputsRecursive(exprStr);
}

vector<long>
Expression::computeAllPossibleOutputsRecursive(const string& exprStr) {
    vector<long> exprOutputV;
    // Recursion termination case : Expression string is a/has reduced to
    // a number (i.e. has no operation chars)
    if (exprStr.find('+') == string::npos &&
        exprStr.find('-') == string::npos &&
        exprStr.find('*') == string::npos) {
        exprOutputV.push_back(stol(exprStr));
        return exprOutputV;
    }

    // Iterate over the expression string characters sequentially till all
    // are processed
    typedef string::size_type strSzT;
    for (strSzT i = 0; i != exprStr.size(); ++i) {
        char ch = exprStr[i];
        if (!isdigit(ch)) {
            // An operator is encountered, split expression into
            // two parts/substrings around the operator -
            // part 1 commencing from string beginning upto the
            // character prior to operator
            // part 2 commencing from character immediately after
            // operator till string ending
            string expr1stPart = exprStr.substr(0, i);
            string expr2ndPart = exprStr.substr(i + 1);

            // Recursively evaluate each of sub-expressions formed by splitting
            // the expression around the current operator to determine the
            // possible outputs produced by both of the sub-expressions
            vector<long> subExpr1OutVec =
                computeAllPossibleOutputsRecursive(expr1stPart);
            vector<long> subExpr2OutVec =
                computeAllPossibleOutputsRecursive(expr2ndPart);

            // Apply the current operator on all possible combinations of
            // outputs formed by the 2 sub-expressions into which the expression
            // string is split in this iteration to compute possible outputs
            // and append the results to output vector
            for (auto opPart1 : subExpr1OutVec) {
                for (auto opPart2 : subExpr2OutVec) {
                    switch (ch) {
                        case '+':
                            exprOutputV.push_back(opPart1 + opPart2);
                            break;
                        case '-':
                            exprOutputV.push_back(opPart1 - opPart2);
                            break;
                        case '*':
                            exprOutputV.push_back(opPart1 * opPart2);
                            break;
                    }
                }
            }
        }
    }

    return exprOutputV;
}

vector<long>
Expression::computeAllPossibleOutputsDP(const string& exprStr) {
    if (exprStr.empty()) {
        throw domain_error("Error! Empty input expression string!");
    }
    if (!checkExprValidity(exprStr)) {
        throw domain_error("Error! Invalid input expression!");
    }

    return computeAllPossibleOutputsRecursiveDP(exprStr);
}

vector<long>
Expression::computeAllPossibleOutputsRecursiveDP(const string& exprStr) {

    // Check if the expression outputs are already in the DP memoization
    // table from earlier sub-expression computations. If yes, return value
    if (dpMemoizationTbl.find(exprStr) != dpMemoizationTbl.end()) {
        return dpMemoizationTbl[exprStr];
    }

    vector<long> exprOutputV;
    // Recursion termination case : Expression string is a/has reduced to
    // a number (i.e. has no operation chars)
    if (exprStr.find('+') == string::npos &&
        exprStr.find('-') == string::npos &&
        exprStr.find('*') == string::npos) {
        exprOutputV.push_back(stol(exprStr));
        return exprOutputV;
    }

    // Iterate over the expression string characters sequentially till all
    // are processed
    typedef string::size_type strSzT;
    for (strSzT i = 0; i != exprStr.size(); ++i) {
        char ch = exprStr[i];
        if (!isdigit(ch)) {
            // An operator is encountered, split expression into
            // two parts/substrings around the operator -
            // part 1 commencing from string beginning upto the
            // character prior to operator
            // part 2 commencing from character immediately after
            // operator till string ending
            string expr1stPart = exprStr.substr(0, i);
            string expr2ndPart = exprStr.substr(i + 1);

            // Recursively evaluate each of sub-expressions formed by splitting
            // the expression around the current operator to determine the
            // possible outputs produced by both of the sub-expressions
            vector<long> subExpr1OutVec =
                computeAllPossibleOutputsRecursiveDP(expr1stPart);
            vector<long> subExpr2OutVec =
                computeAllPossibleOutputsRecursiveDP(expr2ndPart);

            // Apply the current operator on all possible combinations of
            // outputs formed by the 2 sub-expressions into which the expression
            // string is split in this iteration to compute possible outputs
            // and append the results to output vector
            for (auto opPart1 : subExpr1OutVec) {
                for (auto opPart2 : subExpr2OutVec) {
                    switch (ch) {
                        case '+':
                            exprOutputV.push_back(opPart1 + opPart2);
                            break;
                        case '-':
                            exprOutputV.push_back(opPart1 - opPart2);
                            break;
                        case '*':
                            exprOutputV.push_back(opPart1 * opPart2);
                            break;
                    }
                }
            }
        }
    }

    // Add computed expression outputs to memoization table
    dpMemoizationTbl[exprStr] = exprOutputV;
    return dpMemoizationTbl[exprStr];
}
