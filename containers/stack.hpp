//  ----------------------------------------------------------------------------
//  Template class definition for a stack of T objects          file: stackT.hpp
//  Alice E. Fischer  June 10, 2000
//  Modified by Ferhat Erata <ferhat.erata@yale.edu> on December 21, 2019.
//  ----------------------------------------------------------------------------

#ifndef STL_STACK_HPP
#define STL_STACK_HPP

#include "array.hpp"
#include <iostream>

namespace my {

// -----------------------------------------------------------------------------
template <class T> class Stack : FlexArray<T> {
  protected:
    const char* Name{};

  public:
    explicit Stack(const char* nm, int sz = 4) : FlexArray<T>(sz), Name(nm) {
        std::cout << " Create " << Name << "  ";
    }

    Stack(const Stack<T>& s) {
        throw Fatal(" Can't shallow-copy stack %s", s.Name);
    }

    ~Stack() { std::cout << " Delete " << Name << "  "; }

    void push(T& c) { this->put(c); };

    T pop() { return empty() ? (T)0 : FlexArray<T>::store[--FlexArray<T>::n]; }

    T top() const {
        return empty() ? (T)0 : FlexArray<T>::store[FlexArray<T>::n - 1];
    }
    [[nodiscard]] bool empty() const { return FlexArray<T>::n == 0; }
    [[nodiscard]] int depth() const { return FlexArray<T>::n; }

    std::ostream& print(std::ostream& out) const;
};

// -----------------------------------------------------------------------------
template <class T> std::ostream& Stack<T>::print(std::ostream& out) const {
    out << "\nStack has " << depth() << " items: bottom<[";
    FlexArray<T>::print(out);
    out << " ]>top\n";
    return out;
}

// -----------------------------------------------------------------------------
template <class T>
inline std::ostream& operator<<(std::ostream& out, Stack<T>& s) {
    return s.print(out);
}

} // namespace my

#endif // STL_STACK_HPP