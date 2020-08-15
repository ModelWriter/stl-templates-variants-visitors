// ============================================================================
// Name: Bracket-matching example of stack usage                File: token.cpp
// Author:  Michael and Alice Fischer                   Copyright: January 2009
// Modified February 2016
// ============================================================================
#include "token.hpp"
//-----------------------------------------------------------------------------
int Token::nextID = 0;
//-----------------------------------------------------------------------------
Token::Token(char ch) {
    this->ch = ch;
    classify(ch);
    dynarray = new int[10];
    cerr << "Char constructor for token " << id << " called\n";
}

//-----------------------------------------------------------------------------
void Token::classify(char ch) {
    static const char* brackets = "[](){}<>";
    const char* p = strchr(brackets, ch);
    if (p == nullptr) {
        type = BKT_NONE;
        sense = SENSE_LEFT; // arbitrary value
    } else {
        int pos = p - brackets; // pointer difference gives subscript.
        sense = (pos % 2 == 0) ? SENSE_LEFT : SENSE_RIGHT;
        type = (BracketType)(pos / 2); // integer arithmetic, with truncation.
    }
}
