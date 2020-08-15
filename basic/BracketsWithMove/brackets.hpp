// ============================================================================
// Name: Bracket-matching example of stack usage             File: brackets.hpp
// Author:  Michael and Alice Fischer                   Copyright: January 2009
// Modified February 2016
// ============================================================================
#ifndef BRACKETS_H
#define BRACKETS_H

#include "stack.hpp"
#include "token.hpp"
#include "tools.hpp"

class Brackets {
  private:
    Stack* stk;
    Token toptok;
    int lineno;

  public:
    Brackets() {
        stk = new Stack("brackets");
        lineno = 1;
    }
    ~Brackets() { delete stk; }

    void analyze(istream& in); // Check bracket nesting and matching in file.
    void mismatch(const char* msg, const Token& tok,
                  bool eofile); // Handle errors.
};
#endif
