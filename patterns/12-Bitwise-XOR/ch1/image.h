#ifndef _IMAGE_H_
#define _IMAGE_H_

// System headers
#include <vector>

// Statics, typedefs, globals
typedef std::vector<unsigned char> ImageRowT;
typedef std::vector<std::vector<unsigned char> > ImageT;
typedef std::vector<unsigned char>::size_type imgSzT;
typedef std::vector<std::vector<unsigned char> >::size_type imgRowSzT;

class Image {
public:
    static ImageT flipHorizontallyAndInvert(ImageT img);
private:
};

#endif /* _IMAGE_H_ */
