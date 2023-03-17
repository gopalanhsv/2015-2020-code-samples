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
    using std::sort;
    using std::vector;
    using std::domain_error;
    typedef typename vector<T>::size_type vecSzT;

    if (v.empty()) {
        throw domain_error("Median of empty vector");
    }

    sort(v.begin(), v.end());
    vecSzT size = v.size();

    vecSzT mid = size / 2;
    return (0 == size % 2) ? (v[mid - 1] + v[mid]) / 2 : v[mid];
}

#endif /* _MEDIAN_H_ */
