#ifndef _MEDIAN_H_
#define _MEDIAN_H_

// System headers
#include <algorithm>
#include <stdexcept>

// Local includes
#include "../Vec/Vec.h"

// Using declarations

// Typedefs & globals

template<typename T>
T
median(Vec<T> v) {
    typedef typename Vec<T>::size_type VecSzT;
    VecSzT size = v.size();

    if (!size) {
        throw std::domain_error("Error! Median of empty vector!");
    }

    std::sort(v.begin(), v.end());

    VecSzT mid = size / 2;
    return (0 == size % 2) ? (v[mid - 1] + v[mid]) / 2 : v[mid];
}

#endif /* _MEDIAN_H_ */
