// System headers
#include <iostream>
#include <vector>
#include <stdexcept>

// Local includes
#include "image.h"

// Using declarations
using std::vector;
using std::domain_error;
using std::cin;
using std::cout;
using std::endl;

// Statics, typedefs, globals

void
readImage(ImageT& img) {
    img.clear();

    unsigned int nr, nc;
    cout << "Enter #rows of image : ";
    while (!(cin >> nr));
    cout << "Enter #cols of image : ";
    while (!(cin >> nc));

    for (int r = 0; r != nr; ++r) {
        cout << endl << "Enter row " << r << " of image in 0/1 : ";
        ImageRowT imgRow;
        for (int c = 0; c != nc; ++c) {
            unsigned char x;
            while (!(cin >> x) && (x != 0 && x != 1)) {
                cout << "Try again!";
            }
            imgRow.push_back(x);
        }
        img.push_back(imgRow);
    }
}

void
displayImage(const ImageT& img) {
    cout << "Begin Image" << endl;
    for (imgSzT r = 0; r != img.size(); ++r) {
        for (imgRowSzT c = 0; c != img[0].size(); ++c) {
            cout << img[r][c] << " ";
        }
        cout << endl;
    }

    cout << "End Image" << endl;
}

void
testFn() {
    ImageT img;
    readImage(img);
    cout << "Original image is : ";
    displayImage(img);

    try {
        img = Image::flipHorizontallyAndInvert(img);
        cout << "Horizontally flipped and inverted image of original is : ";
        displayImage(img);
    } catch (domain_error& e) {
        throw e;
    }
}

int
main() {
    try {
        testFn();
    } catch (domain_error& e) {
        cout << e.what() << endl;
        return 1;
    }
    return 0;
}
