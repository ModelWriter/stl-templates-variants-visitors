//==============================================================================
// Project: Bracket-matching example of stack usage               File: main.cpp
// Author:  Michael and Alice Fischer                    Copyright: January 2009
// Modified February 2016
// =============================================================================
#include "brackets.hpp"
#include "tools.hpp"

// Static function prototype
static void run(int argc, char* argv[]);

//-----------------------------------------------------------------------------
int main(int argc, char* argv[]) {
    banner();
    try {
        run(argc, argv);
    } catch (Fatal& e) {
        cerr << "Catching Fatal exception\n" << e.what() << endl;
    } catch (...) {
        std::cerr << "Uncaught exception" << std::endl;
    }
    bye();
}

void run(int argc, char* argv[]) {
    say("Welcome to the bracket checker!");

    if (argc != 2)
        throw Fatal("usage: %s file", argv[0]);
    say("Checking file '%s'", argv[1]);

    ifstream in(argv[1]);
    if (!in)
        throw Fatal("can't open file '%s' for reading", argv[1]);

    Brackets b;    // Declare and initialize the application class.
    b.analyze(in); // Execute the primary application function.
    in.close();
}
