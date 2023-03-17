#ifndef _MEDIAN_H_
#define _MEDIAN_H_

// System headers
#include <vector>
#include <stdexcept>

// Local includes

// Using declarations


template <typename RandIter, typename T>
void
median(RandIter b, RandIter e, T& med) {
    if (b == e) {
        throw std::domain_error("Median of empty range");
    }

    using std::vector;
    vector<T> v(b, e);
    std::sort(v.begin(), v.end());

    typedef typename vector<T>::size_type vecSzT;
    vecSzT size = v.size();
    vecSzT mid = size / 2;
    med = (0 == size % 2) ? (v[mid - 1] + v[mid]) / 2: v[mid];
}

#endif /* _MEDIAN_H_ */
