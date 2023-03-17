#ifndef _MEDIAN_H_
#define _MEDIAN_H_

// System headers
#include <vector>
#include <algorithm>
#include <stdexcept>

// Local includes

// Using declarations

// Typedefs

template<typename T>
T
median(std::vector<T> v) {
    if (0 == v.size()) {
        throw std::domain_error("Median of empty vector");
    }

    using std::vector;
    using std::sort;

    // Sort the vector
    sort(v.begin(), v.end());

    typedef typename vector<T>::size_type vecSzT;
    vecSzT vecSz = v.size();

    vecSzT mid = vecSz / 2;
    
    return (0 == vecSz % 2) ? (v[mid - 1] + v[mid]) / 2 : v[mid];
}

#endif /* _MEDIAN_H_ */
