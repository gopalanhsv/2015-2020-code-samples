// System headers
#include <vector>

// Local includes
#include "searchInSortedMatrix.h"

// Using includes
using std::vector;

// Statics, globals, typedefs

bool
searchSortedMatrix(const vector<vector<int> >& matrix, int key) {
    // Empty matrix
    if (matrix.empty()) {
        return false;
    }

    typedef vector<vector<int> >::size_type vecSzRowsT;
    typedef vector<int>::size_type vecSzColsT;
    vecSzRowsT nRows = matrix.size();
    vecSzColsT nCols = matrix[0].size();

    vecSzRowsT keyRow;
    if (1 == matrix.size()) {
        // Single row case
        keyRow = 0;
    } else {
        // Exec Binary search to find the possible matrix row
        // holding the key
        vecSzRowsT rLo = 0;
        vecSzRowsT rHi = nRows - 1;
        while (rLo <= rHi) {
            // Compute mid row
            vecSzRowsT mid = rLo + (rHi - rLo) / 2;
            if (key < matrix[mid][0]) {
                // Key is lesser than smallest element in mid row,
                // implies that key may only be in lower rows
                if (mid == 0) {
                    // Special case when mid is first row
                    // Then key is out of range
                    return false;
                }
                rHi = mid - 1;
            } else if (key > matrix[mid][nCols - 1]) {
                // Key is more than largest element in mid row,
                // implies that key may only be in higher rows
                if (mid == nRows - 1) {
                    // Special case when mid is last row
                    // Then key is out of range
                    return false;
                }
                rLo = mid + 1;
            } else {
                // Key may likely be in mid row
                keyRow = mid;
                break;
            }
        }
    }

    // Exec binary search to find column number of search key
    // at the potential row number
    vecSzColsT cLo = 0;
    vecSzColsT cHi = nCols - 1;
    while (cLo <= cHi) {
        // Compute mid column
        vecSzColsT mid = cLo + (cHi - cLo) / 2;
        if (key == matrix[keyRow][mid]) {
            // Key found
            return true;
        } else if (key > matrix[keyRow][mid]) {
            // Key is more than mid col element
            // implies that key may only be in higher cols
            cLo = mid + 1;
        } else {
            // Key is lesser than mid col element
            // implies that key may only be in lower cols
            if (mid == 0) { // To avoid rollover
                break;
            }
            cHi = mid - 1;
        }
    }

    return false;
}
