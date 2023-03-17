#ifndef _PTR_H_
#define _PTR_H_

// System headers
#include <cctype>
#include <stdexcept>

// Local includes

// Using declarations

// Static, globals and typedefs

template<typename T>
class Ptr {
public:
    // Interface
    // Constructors
    Ptr();
    Ptr(T*);
    Ptr(const Ptr&);

    // Destructors
    ~Ptr();

    // Operators
    Ptr& operator=(const Ptr&);
    T& operator*() const;
    T* operator->() const;
    operator bool() const;

    void makeUnique();

private:
    // Data members
    T* p;
    std::size_t* refCntP;
};

template<typename T>
Ptr<T>::Ptr() : p(NULL), refCntP(new std::size_t(1)) {
}

template<typename T>
Ptr<T>::Ptr(T* t) : p(t), refCntP(new std::size_t(1)) {
}

template<typename T>
Ptr<T>::Ptr(const Ptr& ptr) : p(ptr.p), refCntP(ptr.refCntP) {
    ++(*refCntP);
}

template<typename T>
Ptr<T>::~Ptr() {
    if (0 == --(*refCntP)) {
        delete p;
        delete refCntP;
    }
    p = NULL;
    refCntP = NULL;
}

template<typename T>
Ptr<T>&
Ptr<T>::operator=(const Ptr& rhs) {
    ++(*rhs.refCntP);
    if (0 == --(*refCntP)) {
        delete p;
        delete refCntP;
    }
    p = rhs.p;
    refCntP = rhs.refCntP;
}

template<typename T>
T&
Ptr<T>::operator*() const {
    if (p) {
        return *p;
    } else {
        throw std::runtime_error("Error! Unbound ptr in operator*()");
    }
}

template<typename T>
T*
Ptr<T>::operator->() const {
    if (p) {
        return p;
    } else {
        throw std::runtime_error("Error! Unbound ptr in operator->()");
    }
}

template<typename T>
Ptr<T>::operator bool() const {
    return p;
}

template<typename T>
T*
clone(T* p) {
    return p ? p->clone() : NULL;
}

template<typename T>
void
Ptr<T>::makeUnique() {
    if (1 != *refCntP) {
        --(*refCntP);
        refCntP = new std::size_t(1);
        p = clone(p);
    }
}

#endif /* _PTR_H_ */
