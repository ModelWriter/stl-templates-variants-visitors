//==========================================================================
// Bargraph of Exam Scores: An introduction to class interactions.
// Read scores from a user-specified file; display them as a bar graph.
// A. Fischer, September 30, 2000                             file: main.cpp
// Modified M. & A. Fischer, September 17, 2009, 2019
//==========================================================================
#include "graph.hpp"
#include "tools.hpp"

// Static function prototype
static void run();

//-----------------------------------------------------------------------------
int main(int argc, char* argv[]) {
    banner();
    if (NESTED == 1)
        cout << "Nested inner class version" << endl;
    else
        cout << "Outer class friend version" << endl;
    run();
    bye();
}

//-----------------------------------------------------------------------------
void run() {
    Graph::instructions(); // Call of static class method
    string fname;
    cout << "Name of data file: ";
    cin >> fname; // *** IRRESPONSIBLE CODE ***
    if (!cin.good())
        fatal("Can't read file name from standard input");
    ifstream infile(fname); // Declare and open input stream
    if (!infile)
        fatal("Cannot open %s for input - aborting!!\n", fname.data());
    else
        cout << "File is open and ready to read.\n";

    Graph curve(infile); // Declare and construct a Graph object.
                         // Realizes data structure from a file
    cout << curve;       // Print the graph.
                         // OR: curve.print( cout );		// Print the graph.

    // Storage belonging to curve will be freed by destructors at this time.
}
