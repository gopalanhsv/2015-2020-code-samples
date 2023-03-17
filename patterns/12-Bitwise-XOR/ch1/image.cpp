// System headers
#include <vector>
#include <stdexcept>

// Local includes
#include "image.h"

// Using declarations
using std::vector;
using std::domain_error;

// Statics, typedefs, globals

typedef std::vector<unsigned char> ImageRowT;
typedef std::vector<std::vector<unsigned char> > ImageT;
typedef std::vector<unsigned char>::size_type imgSzT;
typedef std::vector<std::vector<unsigned char> >::size_type imgRowSzT;

ImageT
Image::flipHorizontallyAndInvert(ImageT img) {
    if (img.empty()) {
        throw domain_error("Error! Empty input vector!");
    }

    // Horizontal flipping is accomplished by interchanging the 'r th' element
    // from left with the 'r th' element from right
    // Inversion is done by XOR'ing an element with 1
    // Above 2 steps are combined to yield the transformed image
    imgSzT nCols = img[0].size();
    imgRowSzT nRows = img.size();
    for (imgRowSzT r = 0; r != nRows; ++r) {
        // Flip and invert columns except mid column for odd # of columns
        for (imgSzT c = 0; c != nCols / 2; ++c) {
            unsigned char tmp = img[r][nCols - 1 - c];
            img[r][nCols - 1 - c] = img[r][c] ^ 1; // Flip & invert
            img[r][c] = tmp ^ 1; // Flip and invert
        }
        // Flip and invert mid column for odd # of columns
        if (0 != nCols % 2) {
            img[r][nCols / 2] = img[r][nCols / 2] ^ 1;
        }
    }

    return img;
}
