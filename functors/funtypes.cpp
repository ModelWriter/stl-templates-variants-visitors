// Illustrate use of global function types

#include <iostream>

// Define myfun to be a function with signature long int (&) (double, int&).
long int(myfun)(double d, int& k) { return (k += 2.5 * d); }

// Define type name "myFunType".
typedef long int(myFunType)(double, int&);

// Use type name "myFunType" to define an alias "myfun2" for "myfun".
myFunType& myfun2 = myfun;

// Define alias myfun3 using an explicit type expression
long int (&myfun3)(double, int&) = myfun;

// -----------------------------------------------------------------------------
// Show that both aliases work
int main() {
    int k = 5;
    std::cout << "myfun2() returns " << myfun2(1.0, k) << std::endl;
    std::cout << "k=" << k << std::endl;

    std::cout << "myfun3() returns " << myfun3(5.5, k) << std::endl;
    std::cout << "k=" << k << std::endl;
}
