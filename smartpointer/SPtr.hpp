
#ifndef SPTR_HPP_
#define SPTR_HPP_

#include <exception>
#include <iostream>
#include <utility>

#include "Serial.hpp"
using namespace std;

// ----------------------------------------------------------------------------
// Smart pointer exception class
class SPexception : std::exception {
  private:
    std::string s;

  public:
    explicit SPexception(std::string s) : s(std::move(s)) {}
    [[nodiscard]] const char* what() const noexcept override {
        return s.data();
    }
};

// ----------------------------------------------------------------------------
// Smart pointer class
template <typename T> class SPtr {
  private:
    unsigned* count = nullptr; // shared object among all SPtr with same target
    T* target = nullptr;       // shared target object
    const int my_id = Serial::newID(); // assign unique ID to each instance

  public:
    // Default constructor
    SPtr();
    // Construct an SPtr to manage p
    explicit SPtr(T* p);
    // Copy constructor
    SPtr(const SPtr& sp);
    // Copy assignment
    SPtr& operator=(const SPtr& sp);
    // Move constructor
    SPtr(SPtr&& sp) noexcept;
    // Move assignment
    SPtr& operator=(SPtr&& sp);
    // Destructor
    ~SPtr() {
        cout << "  Destructor called for SPtr " << id() << endl;
        reset();
    }

    [[nodiscard]] bool empty() const { return count == nullptr; };
    void reset();
    [[nodiscard]] int id() const { return my_id; }

    // Follow operator.
    T& operator*() {
        if (!empty())
            return *target;
        else
            throw SPexception("Can't follow empty SPtr");
    }
};

// Default constructor
template <typename T> SPtr<T>::SPtr() : count(nullptr), target(nullptr) {
    cout << "  Default constructor called for Sptr " << id() << endl;
}

// Construct an SPtr to manage p
template <typename T> SPtr<T>::SPtr(T* p) : count(new unsigned(1)), target(p) {
    cout << "  SPtr(T*) constructor called for Sptr " << id() << endl;
}
//------------------------------------------------------------------------------
// Copy constructor
template <typename T>
SPtr<T>::SPtr(const SPtr& sp) : count(sp.count), target(sp.target) {
    ++*count;
    cout << "  Copy constructor from Sptr " << sp.id() << " to " << id()
         << endl;
}

//------------------------------------------------------------------------------
// Copy assignment
template <typename T> SPtr<T>& SPtr<T>::operator=(const SPtr& sp) {
    reset();
    count = sp.count;
    target = sp.target; // copy pointer
    ++*count;
    cout << "  Copy assignment from Sptr " << sp.id() << " to " << id() << endl;
    return *this;
}

//------------------------------------------------------------------------------
// Move constructor
template <typename T>
SPtr<T>::SPtr(SPtr&& sp) noexcept : count(sp.count), target(sp.target) {
    sp.count = nullptr;
    sp.target = nullptr;
    cout << "  Move constructor from Sptr " << sp.id() << " to " << id()
         << endl;
}

//------------------------------------------------------------------------------
// Move assignment
template <typename T> SPtr<T>& SPtr<T>::operator=(SPtr&& sp) {
    reset();
    count = sp.count;
    target = sp.target;
    sp.count = nullptr;
    sp.target = nullptr;
    cout << "  Move assignment from Sptr " << sp.id() << " to " << id() << endl;
    return *this;
}

//------------------------------------------------------------------------------
// Unmanage target if currently being managed and adjust count.
// If count falls to 0, delete count and target.
// Afterwards, *this is back in its default empty state.
template <typename T> void SPtr<T>::reset() {
    if (empty())
        return; // already empty; nothing to do
    // Unmanage target pointer
    if (--*count > 0)
        return;
    // No other references, so release managed storage
    cout << "  Releasing storage managed by Sptr " << id() << endl;
    delete count;
    delete target;
    count = nullptr;
    target = nullptr;
}

#endif /* SPTR_HPP_ */
