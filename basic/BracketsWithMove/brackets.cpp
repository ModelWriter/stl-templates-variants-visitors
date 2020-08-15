// ============================================================================
// Name: Bracket-matching example of stack usage             File: brackets.cpp
// Author:  Michael and Alice Fischer                   Copyright: January 2009
// Modified February 2016
// ============================================================================
#include "brackets.hpp"
//-----------------------------------------------------------------------------
void Brackets::analyze(istream& in) {
    char ch;

    for (;;) {      // Read and process the file.
        in.get(ch); // This does not skip leading whitespace.
        if (!in.good())
            break;
        if (ch == '\n')
            lineno++;
        Token curtok(ch);
        if (curtok.getType() == BKT_NONE)
            continue; // skip non-bracket characters

        switch (curtok.getSense()) {
        case SENSE_LEFT:
            stk->push(move(curtok)); // custody of curtok transferred to stk
            break;

        case SENSE_RIGHT:
            if (stk->empty())
                mismatch("Too many right brackets", curtok, false);
            toptok = stk->pop();
            if (toptok.getType() != curtok.getType())
                mismatch("Closing bracket has wrong type", curtok, false);
            break;
        }
    }
    if (!in.eof())
        throw Fatal("Failure reading input character");
    if (stk->empty())
        cout << "The brackets in this file are properly nested and matched.\n";
    else
        mismatch("Too many left brackets", toptok, true);
}

//-----------------------------------------------------------------------------
void Brackets::mismatch(const char* msg, const Token& tok, bool eofile) {
    if (eofile) {
        cout << "\nMismatch at end of file: " << msg << endl;
    } else {
        cout << "\nMismatch on line " << lineno << " : " << msg << endl;
        cout << "The current mismatching bracket is " << tok << endl;
    }
    stk->print(cout);                      // print stack contents
    throw Fatal("Brackets fail to match"); // Report failure.
}
