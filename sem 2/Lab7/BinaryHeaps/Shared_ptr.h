#ifndef SHARED_PTR_H
#define SHARED_PTR_H
#include <memory>

template<typename T>
class Shared_ptr {
private:
    struct ControlBlock {
        T* ptr;
        size_t* refCount;
        size_t* weakCount;
    };

    ControlBlock* controlBlock;

public:
    Shared_ptr() : controlBlock(nullptr) {}

    explicit Shared_ptr(T* ptr) {
        if (ptr) {
            controlBlock = new ControlBlock;
            controlBlock->ptr = ptr;
            controlBlock->refCount = new size_t(1);
            controlBlock->weakCount = new size_t(0);
        }
        else {
            controlBlock = nullptr;
        }
    }

    Shared_ptr(const Shared_ptr& other) : controlBlock(other.controlBlock) {
        if (controlBlock) {
            ++(*controlBlock->refCount);
        }
    }

    Shared_ptr& operator=(const Shared_ptr& other) {
        if (this != &other) {
            release();

            controlBlock = other.controlBlock;
            if (controlBlock) {
                ++(*controlBlock->refCount);
            }
        }
        return *this;
    }

    ~Shared_ptr() {
        release();
    }

    T& operator*() const {
        return *(controlBlock->ptr);
    }

    T* operator->() const {
        return controlBlock->ptr;
    }

    operator bool() const {
        return controlBlock && controlBlock->ptr;
    }

private:
    void release() {
        if (controlBlock) {
            if (--(*controlBlock->refCount) == 0) {
                delete controlBlock->ptr;
                delete controlBlock->refCount;
                if (*controlBlock->weakCount == 0) {
                    delete controlBlock->weakCount;
                    delete controlBlock;
                }
                else {
                    --(*controlBlock->weakCount);
                }
            }
        }
    }
};

#endif // SHARED_PTR_H
