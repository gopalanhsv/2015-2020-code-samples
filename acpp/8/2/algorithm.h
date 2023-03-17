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
mycopy(In beg, In end, Out dest) {
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
            *beg = y;
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

template<class In, class In2>
bool
myequal(In b, In e, In2 b2) {
    while (b != e) {
        if (*b++ != *b2++)
            return false;
    }
    return true;
}

template<class In, class In2>
In
search(In b, In e, In2 b2, In2 e2) {
    while (b != e) {
        In2 tmpb2 = b2;
        In tmpb = b;
        bool found = true;
        while (tmpb2 != e2) {
            if (*tmpb2 != *tmpb || tmpb == e) {
                found = false;
                break;
            }
            ++tmpb, ++tmpb2;
        }
        if (found)
            return b;
        ++b;
    }
    return b;
}

template<class In, class Fn>
In
find_if(In b, In e, Fn p) {
    while (b != e) {
        if (p(*b))
            return b;
        ++b;
    }
    return b;
}

template<class In, class Out, class T>
void
remove_copy(In b, In e, Out d, const T& t) {
    while (b != e) {
        if (*b != t)
            *d++ = *b;
        ++b;
    }
}

template<class In, class Out, class Fn>
void
remove_copy_if(In b, In e, Out d, Fn p) {
    while (b != e) {
        if (!p(*b))
            *d++ = *b;
        ++b;
    }
}

template<class Bi, class T>
Bi
remove(Bi b, Bi e, const T& t) {
    Bi i = b;
    while (b != e) {

        while (b != e && *b != t)
            *i++ = *b++;

        Bi j = b;
        while (j != e && *j == t)
            ++j;

        if (b != j) {
            Bi x = j;
            while (b != j) {
                if (*x != t && x != e) {
                    *i++ = *x++;
                } else {
                    break;
                }
            }
            if (x == e || j == e) {
                break;
            }
            b = x;
        } else {
            break;
        } 
    }
    return i;
}

template<class In, class Out, class Fn>
void
transform(In b, In e, Out d, Fn p) {
    while (b != e) {
        *d++ = p(*b);
        ++b;
    }
}

template<class Bi, class Fn>
Bi
partition(Bi b, Bi e, Fn p) {
    while (b != e) {
        if (!p(*b)) {
            --e;
            swap(*b, *e);
        } else {
            ++b;
        }
    }
    return b;
}

template<class In, class T>
T
accumulate(In b, In e, const T& t) {
    T tmp = t;
    while (b != e)
        tmp += *b++;
    return tmp;
}

#endif /* _ALGORITHM_H_ */
