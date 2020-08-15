// ============================================================================
// Name: Bracket-matching example of stack usage                File: stack.cpp
// Author:  Michael and Alice Fischer                   Copyright: January 2009
// Modified February 2016
// ============================================================================
#include "stack.hpp"
//-----------------------------------------------------------------------
ostream& Stack::print(ostream& out) const {
    T* p = s; // Scanner & end pointer for data
    T* pend = s + top;
    out << "The stack " << name << " contains: Bottom~~ ";
    for (; p < pend; ++p)
        cout << ' ' << *p;
    return out << " ~~Top" << endl;
}

//-----------------------------------------------------------------------------
void Stack::push(T&& c) {
    if (top == max) { // If stack is full, allocate more space.
        say("-Doubling stack length-");
        T* temp = s;         // grab old array.
        s = new T[max *= 2]; // make bigger one,
        for (int k = 0; k < top; ++k)
            s[k] = move(temp[k]); // move over old data
        delete[] temp;            // free old array.
    }
    s[top++] = move(c); // Store data in array, prepare for next push.
}
