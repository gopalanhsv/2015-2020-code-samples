#ifndef _VEC_H_
#define _VEC_H_

// System headers
#include <cstddef>
#include <memory>
#include <algorithm>

// Local includes

// Using declarations

// Typedefs

template<typename T>
class Vec {
public:
    // Interface

    // Typedefs
    typedef T* iterator;
    typedef const T* const_iterator;
    typedef size_t size_type;
    typedef T value_type;
    typedef T& reference;
    typedef const T& const_reference;
    typedef std::ptrdiff_t difference_type;

    // Constructors
    Vec() { create(); }
    explicit Vec(size_type n, const_reference val = T()) { create(n, val); }
    template<typename InputIterator> Vec(InputIterator b, InputIterator e);
    // Copy constructor
    Vec(const Vec& v) { create(v.begin(), v.end()); };

    // Assignment operator
    Vec& operator=(const Vec&);

    // Destructor
    ~Vec() { uncreate(); };

    // Iterators
    iterator begin() { return data; };
    const_iterator begin() const { return data; };
    iterator end() { return avail; };
    const_iterator end() const { return avail; };

    // Subscript operator
    T& operator[](size_type i) { return data[i]; }
    const T& operator[](size_type i) const { return data[i]; }

    // Push back
    void push_back(const T& v);

    // Returns the number of elements in Vec
    inline size_type size() const { return avail - data; }

    // Returns true if the Vec is empty
    inline bool empty() const { return !(avail - data); };

    // Removes the element at given position from the vector
    // and returns an iterator to the next valid element
    iterator erase(iterator i);

    // Removes all the elements from the vector
    void clear() { uncreate(); };

    // Inserts the elements in the range [b, e) into the vector
    // from the iterator location starting at i
    template<typename InputIterator>
    void insert(iterator i, InputIterator b, InputIterator e);

private:

    // Implementation
    // Vector implemented as an array of objects
    // first element in Vec
    iterator data;
    // (one beyond) the last constructed element in Vec
    // (or the first available element)
    iterator avail;
    // (one beyond) the allocated memory for Vec
    iterator limit;

    // Facilities for managing memory occupied by underlying array

    // Allocator object for managing the memory
    std::allocator<T> alloc;

    // Support functions for constructors and assignment operator
    // Allocate and initialize the underlying array
    void create();
    void create(size_type n, const_reference val);
    void create(const_iterator b, const_iterator e);
    template<typename InputIterator>
    void append(InputIterator b, InputIterator e);

    // Support functions for destructor and assignment operator
    // Destroy the elements in array and free the allocated memory
    void uncreate();

    // Support functions for appending an object to vec, i.e push_back
    void grow();
    void unchecked_append(const_reference v);
};

// Constructor which takes in 2 input iterators
template<typename T>
template<typename InputIterator>
Vec<T>::Vec(InputIterator b, InputIterator e) {
    create();
    append(b, e);
}

template<typename T>
Vec<T>&
Vec<T>::operator=(const Vec& rhs) {
    if (this != &rhs) { // self-assignment check
        // Destroy all the elements in current Vec
        uncreate();

        // Create and initialize elements in current Vec from
        // the Vec rhs
        create(rhs.begin(), rhs.end());
    }
    return *this;
}

template<typename T>
typename Vec<T>::iterator
Vec<T>::erase(iterator i) {
    iterator old = i;
    // Destroy the element at specified location
    alloc.destroy(i);
    // Shift all the elements one space to left in array
    uninitialized_copy(i + 1, avail, i);
    // Update the avail pointer
    --avail;

    return old;
}

template<typename T>
void
Vec<T>::push_back(const T& v) {
    // Array is full, need to alloc more space
    if (avail == limit) {
        grow();
    }
    unchecked_append(v);
}

template<typename T>
void
Vec<T>::create() {
    data = avail = limit = NULL;
}

template<typename T>
void
Vec<T>::create(size_type n, const_reference val) {
    data = alloc.allocate(n);
    avail = limit = data + n;
    std::uninitialized_fill(data, avail, val);
}

template<typename T>
void
Vec<T>::create(const_iterator b, const_iterator e) {
    data = alloc.allocate(e - b);
    avail = limit = std::uninitialized_copy(b, e, data);
}

template<typename T>
template<typename InputIterator>
void
Vec<T>::append(InputIterator b, InputIterator e) {
    while (b != e) {
        // Array is full, need to alloc more space
        if (avail == limit) {
            grow();
        }
        unchecked_append(*b);
        ++b;
    }
}

template<typename T>
void
Vec<T>::uncreate() {
    if (data) {
        // Destroy all elements contructed in underlying array
        // in reverse order of construction
        while (avail != data) {
            alloc.destroy(--avail);
        }

        // Release all the allocated memory
        alloc.deallocate(data, limit - data);
    }

    // Reset the underlying pointers to indicate that Vec is empty
    data = avail = limit = 0;
}

template<typename T>
void
Vec<T>::grow() {
    // Alloc twice as much space as earlier while expanding the Vec
    size_type new_size = std::max(2 * (avail - data), ptrdiff_t(1));

    // Allocate memory as per the expanded requirements and initialize
    // it with elements by copying
    iterator new_data = alloc.allocate(new_size);
    iterator new_limit = new_data + new_size;
    iterator new_avail = std::uninitialized_copy(data, avail, new_data);

    // Destroy and free up the older memory space
    uncreate();

    // Update internal data pointers to newly created memory
    data = new_data;
    limit = new_limit;
    avail = new_avail;
}

template<typename T>
void
Vec<T>::unchecked_append(const_reference v) {
    alloc.construct(avail++, v);
}

template<typename T>
template<typename InputIterator>
void
Vec<T>::insert(iterator i, InputIterator b, InputIterator e) {
    // Compute the offset from beginning of array from where
    // new elements in [b, e) are to be inserted. Also compute
    // the number of elements in the array after the offset
    // which will have to be moved to accomodate new elements
    size_type insertOffset = i - data;
    size_type nElemsAfterInsertPos = avail - i;

    // Alloc a temporary memory and copy the pre-existing elements
    // to be moved to the temporary space
    iterator tmpMemBeg = alloc.allocate(nElemsAfterInsertPos);
    iterator tmpMemEnd = std::uninitialized_copy(i, avail, tmpMemBeg);

    // Adjust the iterators of the underlying array to
    // account for pre-existing elements movement
    avail = i;

    // Append the new elements to inserted from [b,e) to the end of array
    append(b, e);

    // Append all the older pre-existing elements from
    // temporary memory to the end of array
    append(tmpMemBeg, tmpMemEnd);

    // Free up the temporary memory
    alloc.deallocate(tmpMemBeg, nElemsAfterInsertPos);
}

#endif /* _VEC_H_ */
