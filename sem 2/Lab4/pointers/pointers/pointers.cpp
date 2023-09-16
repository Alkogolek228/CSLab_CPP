#include <iostream>

template<typename T>
class Shared_Ptr 
{
public:
    Shared_Ptr() : ptr(nullptr), ref_count(nullptr) {}
    Shared_Ptr(T* ptr) : ptr(ptr), ref_count(new int(1)) {}

    Shared_Ptr(const Shared_Ptr<T>& other) : ptr(other.ptr), ref_count(other.ref_count) 
    {
        if (ref_count) 
        {
            ++(*ref_count);
        }
    }

    Shared_Ptr<T>& operator=(const Shared_Ptr<T>& other) 
    {
        if (this != &other) 
        {
            release();
            ptr = other.ptr;
            ref_count = other.ref_count;
            if (ref_count) 
            {
                ++(*ref_count);
            }
        }
        return *this;
    }
    ~Shared_Ptr() 
    {
        release();
    }

    T& operator*() const 
    {
        return *ptr;
    }
    T* operator->() const 
    {
        return ptr;
    }
    operator bool() const 
    {
        return ptr != nullptr;
    }

    T* get() const 
    {
        return ptr;
    }
    int use_count() const 
    {
        return ref_count ? *ref_count : 0;
    }

private:
    T* ptr;
    int* ref_count;

    void release() 
    {
        if (ref_count) 
        {
            --(*ref_count);
            if (*ref_count == 0) 
            {
                delete ptr;
                delete ref_count;
                ptr = nullptr;
                ref_count = nullptr;
            }
        }
    }
};

template<typename T>
class MyUniquePtr {
public:
    MyUniquePtr() : ptr_(nullptr) {}
    explicit MyUniquePtr(T* ptr) : ptr_(ptr) {}
    ~MyUniquePtr() { delete ptr_; }

    MyUniquePtr(const MyUniquePtr&) = delete;
    MyUniquePtr& operator=(const MyUniquePtr&) = delete;

    MyUniquePtr(MyUniquePtr&& other) noexcept {
        move(std::move(other));
    }
    MyUniquePtr& operator=(MyUniquePtr&& other) noexcept {
        if (this != &other) {
            reset();
            move(std::move(other));
        }
        return *this;
    }

    T& operator*() const { return *ptr_; }
    T* operator->() const { return ptr_; }
    T* get() const { return ptr_; }

    void reset() noexcept {
        delete ptr_;
        ptr_ = nullptr;
    }
    void reset(T* ptr) noexcept {
        reset();
        ptr_ = ptr;
    }

private:
    void move(MyUniquePtr&& other) noexcept {
        ptr_ = other.ptr_;
        other.ptr_ = nullptr;
    }

private:
    T* ptr_;
};



int main()
{
    Shared_Ptr<int> ptr(new int(42));
    std::cout << *ptr << std::endl; // Выведет "42"
    MyUniquePtr<int> ptr1(new int(42));
    MyUniquePtr<int> ptr2;
    ptr2 = std::move(ptr1);
    std::cout << *ptr2 << std::endl;
    ptr2.reset();
  

}