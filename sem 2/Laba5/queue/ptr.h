#ifndef PTR_H
#define PTR_H

template <typename T>
class Ptr
{
private:
    T* ptr;
public:
    Ptr(T* obj = nullptr) : ptr(obj) {}
    Ptr(const Ptr& sp) : ptr(sp.ptr) {}

    ~Ptr() { delete ptr; }

    T& operator*() const { return *ptr; }
    T* operator->() const { return ptr; }

    Ptr& operator=(const Ptr& rhs) {
        if (this != &rhs) {
            delete ptr;
            ptr = rhs.ptr;
        }
        return *this;
    }
};

#endif // PTR_H
