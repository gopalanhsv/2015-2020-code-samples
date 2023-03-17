#ifndef _PARANTHESIS_H_
#define _PARANTHESIS_H_

// System headers
#include <string>
#include <vector>

// Local includes
// Using declarations
// Statics, typedefs, globals

class ParanthesisStr {
public:
    // Constructor
    ParanthesisStr(const std::string& ps, unsigned int oc, unsigned int cc) :
        _paranthesisStr(ps), _openCnt(oc), _closedCnt(cc) {}

    // Accessors
    inline std::string paraStr() const { return _paranthesisStr; }
    inline unsigned int openCnt() const { return _openCnt; }
    inline unsigned int closedCnt() const { return _closedCnt; }
    inline bool balanced() const {
        return _openCnt == _closedCnt;
    }

private:
    ParanthesisStr();

    // Data members
    std::string _paranthesisStr;
    unsigned int _openCnt;
    unsigned int _closedCnt;
};

class Permutations {
public:
    static std::vector<std::string>
        generateBalancedParanthesisPairs(unsigned int nPairs);

    static std::vector<std::string>
        generateBalancedParanthesisPairsViaRecursion(unsigned int nPairs);
private:
    static void generateBalancedParanthesisPairsViaRecursion(
        unsigned int nPairs, const ParanthesisStr& intermediateParaStr,
        std::vector<std::string>& finalPermutationsV);
};

#endif /* _PARANTHESIS_H_ */
