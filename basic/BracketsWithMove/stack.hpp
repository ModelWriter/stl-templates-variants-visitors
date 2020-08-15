// ============================================================================
// Name: Bracket-matching example of stack usage                File: stack.hpp
// Author:  Michael and Alice Fischer                   Copyright: January 2009
// Modified February 2016
// ============================================================================
#ifndef STACK_HPP
#define STACK_HPP

#include "token.hpp"
#include "tools.hpp"

#define INIT_DEPTH 1 // initial stack size; stack grows as needed
typedef Token T;     // T is a movable type of stack items

//--------------------------------- Type definition for stack of type T items
class Stack {
  private:
    int max;     // Number of slots in stack.
    int top;     // Stack cursor.
    T* s;        // Pointer to stack base.
    string name; // Print name of this stack.

  public:
    //-------------------------------------------------------- Constructors
    explicit Stack(const char* name) {
        s = new T[max = INIT_DEPTH];
        top = 0;
        this->name = name;
    }
    ~Stack() {
        delete[] s;
        cout << "Freeing stack " << name << endl;
    }
    //-------------------------------------------------------- Prototypes
    ostream& print(ostream& out) const;
    void push(T&& c);
    //-------------------------------------------------------- Inline functions
    T&& pop() { return move(s[--top]); }  // Pop and return top item.
    T peek() { return move(s[top - 1]); } // Return top item without popping.
    [[nodiscard]] bool empty() const {
        return top == 0;
    } // Return true iff stack is empty
    [[nodiscard]] int size() const {
        return top;
    } // Number of items on the stack.
};
#endif
