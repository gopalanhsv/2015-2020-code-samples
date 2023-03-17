#ifndef _HANDLE_H_
#define _HANDLE_H_

// System headers

// Local includes

// Using declarations

// Statics, Globals, Typedefs

template<typename T>
class Handle {
public:
    // Constructors
    Handle() : p(NULL) {}
    Handle(const Handle&);
    Handle(T* ptr) { p = ptr; }

    // Destructor
    ~Handle() { delete p; }

    // Operators
    operator bool() const { return p; }
    Handle& operator=(const Handle&);
    T& operator*() const;
    T* operator->() const;

private:
    T* p;
};

template<typename T>
Handle<T>::Handle(const Handle& h) : p(NULL) {
    p = (h.p) ? h.p->clone() : NULL;
}

template<typename T>
Handle<T>&
Handle<T>::operator=(const Handle& rhs) {
    if (this != &rhs) {
        delete p;
        p = (rhs.p) ? rhs.p->clone() : NULL;
    }
    return *this;
}

template<typename T>
T&
Handle<T>::operator*() const {
    if (p) {
        return *p;
    } else {
        std::runtime_error("Error! Unbound handle at operator*() !"); 
    }
}

template<typename T>
T*
Handle<T>::operator->() const {
    if (p) {
        return p;
    } else {
        std::runtime_error("Error! Unbound handle at operator->() !");
    }
}

#endif /* */
