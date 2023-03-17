#ifndef _ALGORITHM_H_
#define _ALGORITHM_H_

// Input iterators example
template<class In, class X>
In
find(In beg, In end, const X& x) {
    while (beg != end && *beg != x) {
        ++beg;
    }
    return beg;
}

template<class In, class X>
In
findr(In beg, In end, const X& x) {
    if (beg == end || *beg == x) {
        return beg;
    }
    ++beg;
    return findr(beg, end, x);
}

// Output iterators example
template<class In, class Out>
Out
copy(In beg, In end, Out dest) {
    while (beg != end) {
        *dest++ = *beg++;
    }
    return dest;
}

// Forward iterators example
template<class For, class X>
void
replace(For beg, For end, const X& x, const X& y) {
    while (beg != end) {
        if (*beg == x) {
            *beg = y
        }
        ++beg;
    }
}

// Bidirectional iterators example
template<class T>
void
swap(T& a, T& b) {
    T temp = b;
    b = a;
    a = temp;
}

template<class Bi>
void
reverse(Bi beg, Bi end) {
    while (beg != end) {
        --end;
        if (*beg != *end) {
            swap(*beg, *end);
        }
        ++beg;
    }
}

// Random access iterators example
template<class Ran, class X>
bool
binary_search(Ran beg, Ran end, const X& x) {
    while (beg < end) {
        // Calculate midpoint
        Ran mid = beg + (end - beg) / 2;
        // Adjust the range in which to search
        if (x > *mid) {
            beg = mid + 1;
        } else if ( x < *mid) {
            end = mid;
        } else { // x == *mid => element found
            return true;
        }
    }
    return false;
}

template<class T>
T
max(const T& x, const T& y) {
    return x > y ? x : y;
}

#endif /* _ALGORITHM_H_ */
