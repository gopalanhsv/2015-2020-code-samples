#ifndef _REF_HANDLE_H_
#define _REF_HANDLE_H_

// System headers
#include <cctype>
#include <stdexcept>

// Local includes

// Using declarations

// Statics, globals, typedefs

template<typename T>
class RefHandle {
public:
    // Interface

    // Constructors
    RefHandle();
    RefHandle(T*);
    RefHandle(const RefHandle&);

    // Destructor
    ~RefHandle();

    // Operators
    RefHandle& operator=(const RefHandle&);
    T& operator*() const;
    T* operator->() const;
    operator bool() const;

private:
    // Data members
    T* p;
    std::size_t* refCnt;
};

// Constructors
template<typename T>
RefHandle<T>::RefHandle() : p(NULL), refCnt(new std::size_t(1)) {
}

template<typename T>
RefHandle<T>::RefHandle(T* t) : p(t), refCnt(new std::size_t(1)) {
}

template<typename T>
RefHandle<T>::RefHandle(const RefHandle& rh) : p(rh.p), refCnt(rh.refCnt) {
    ++(*refCnt);
}

// Destructor
template<typename T>
RefHandle<T>::~RefHandle() {
    if (0 == --(*refCnt)) {
        delete p;
        delete refCnt;
    }
    p = NULL;
    refCnt = NULL;
}

// Operators
template<typename T>
RefHandle<T>&
RefHandle<T>::operator=(const RefHandle& rhs) {
    ++(*(rhs.refCnt));
    if (0 == --(*refCnt)) {
        delete p;
        delete refCnt;
    }
    refCnt = rhs.refCnt;
    p = rhs.p;
    return *this;
}

template<typename T>
T&
RefHandle<T>::operator*() const {
    if (p) {
        return *p;
    } else {
        std::runtime_error("Error! Unbound ref handle in operator*()");
    }
}

template<typename T>
T*
RefHandle<T>::operator->() const {
    if (p) {
        return p;
    } else {
        std::runtime_error("Error! Unbound ref handle in operator*()");
    }
}

template<typename T>
RefHandle<T>::operator bool() const {
    return p;
}

#endif /* _REF_HANDLE_H_ */
