#ifndef PTR_H
#define PTR_H

template <typename T>
class Ptr {
public:
    Ptr(T* ptr = nullptr) : m_ptr(ptr), m_counter(new int(1)) {}
    Ptr(const Ptr& other) : m_ptr(other.m_ptr), m_counter(other.m_counter) {
        ++(*m_counter);
    }
    ~Ptr() {
        if (--(*m_counter) == 0) {
            delete m_ptr;
            delete m_counter;
        }
    }
    Ptr& operator=(const Ptr& other) {
        if (this != &other) {
            if (--(*m_counter) == 0) {
                delete m_ptr;
                delete m_counter;
            }
            m_ptr = other.m_ptr;
            m_counter = other.m_counter;
            ++(*m_counter);
        }
        return *this;
    }
    T& operator*() const {
        return *m_ptr;
    }
    T* operator->() const {
        return m_ptr;
    }

    bool operator==(const Ptr& other) const {
            return m_ptr == other.m_ptr;
        }
        bool operator!=(const Ptr& other) const {
            return m_ptr != other.m_ptr;
        }
private:
    T* m_ptr;
    int* m_counter;
};

template <typename T>
class Ptr<T[]> {
public:
    Ptr(T* ptr = nullptr) : m_ptr(ptr), m_counter(new int(1)) {}
    Ptr(const Ptr& other) : m_ptr(other.m_ptr), m_counter(other.m_counter) {
        ++(*m_counter);
    }
    ~Ptr() {
        if (--(*m_counter) == 0) {
            delete []m_ptr;
            delete m_counter;
        }
    }
    Ptr& operator=(const Ptr& other) {
        if (this != &other) {
            if (--(*m_counter) == 0) {
                delete []m_ptr;
                delete m_counter;
            }
            m_ptr = other.m_ptr;
            m_counter = other.m_counter;
            ++(*m_counter);
        }
        return *this;
    }
    T& operator*() const {
        return *m_ptr;
    }
    T* operator->() const {
        return m_ptr;
    }

    bool operator==(const Ptr& other) const {
            return m_ptr == other.m_ptr;
        }
        bool operator!=(const Ptr& other) const {
            return m_ptr != other.m_ptr;
        }
private:
    T* m_ptr;
    int* m_counter;
};

#endif // PTR_H
