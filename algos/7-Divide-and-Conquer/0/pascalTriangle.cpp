// System headers
#include <vector>
#include <stdexcept>

// Local includes
#include "pascalTriangle.h"

// Using declarations
using std::vector;
using std::domain_error;

// Statics, typedefs, globals

vector<unsigned int>
pascalTriangleIterative(unsigned int line) {
    if (!line) {
        throw domain_error("Error! Invalid line id!");
    }

    // Vector holding Pascal triangle nos for current line and the
    // previous line; as current line values are always built
    // up using the previous line values
    vector<unsigned int> prevLine(line, 0);
    vector<unsigned int> currLine(line, 0);

    // Iteratively go from the first line to specified line to be computed
    for (unsigned int lId = 1; lId <= line; ++lId) {
        // First and last numbers of each line are always 1
        currLine[0] = 1;
        currLine[lId - 1] = 1;
        // Compute the pascal triangle values for each line (except
        // 1st and last values) using the previous line values
        for (unsigned int i = 1; i < lId; ++i) {
            unsigned int prevLineLtCoeff, prevLineRtCoeff;
            prevLineLtCoeff = prevLine[i - 1];
            prevLineRtCoeff = prevLine[i];
            currLine[i] = prevLineLtCoeff + prevLineRtCoeff;
        }

        // Update the previous line value to current line
        prevLine = currLine;
    }

    return currLine;
}
