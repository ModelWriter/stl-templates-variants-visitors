//  ----------------------------------------------------------------------------
//  Header file for the main class.                                     main.cpp
//  Created by Ferhat Erata <ferhat.erata@yale.edu> on December 21, 2019.
//  Copyright (c) 2019 Yale University. All rights reserved.
// -----------------------------------------------------------------------------

#include "stl.hpp"
#include "utility.hpp"
#include <iostream>
#include <vector>

static bool abs_compare(int a, int b) { return (std::abs(a) < std::abs(b)); }
bool myfn(int i, int j) { return i < j; }

struct myclass {
    bool operator() (int i,int j) { return i<j; }
} myobj;

int main() {

    std::vector<int> v{3, 1, -14, 1, 5, 9};
    std::vector<int>::iterator result;

    result = my::max_element(v.begin(), v.end());
    std::cout << "max element at: " << std::distance(v.begin(), result) << '\n';
    // max element at: 5

    result = my::max_element(v.begin(), v.end(), abs_compare);
    std::cout << "max element (absolute) at: "
              << std::distance(v.begin(), result);
    // max element (absolute) at: 2

    // -------------------------------------------------------------------------
    std::cout << "\n" << utility::separator();
    // -------------------------------------------------------------------------

    int myints[] = {3, 7, 2, 5, 6, 4, 9};

    // using default comparison:
    std::cout << "The smallest element is "
              << *my::min_element(myints, myints + 7) << '\n';
    std::cout << "The largest element is "
              << *my::max_element(myints, myints + 7) << '\n';

    // using function myfn as comp:
    std::cout << "The smallest element is "
              << *my::min_element(myints, myints + 7, myfn) << '\n';
    std::cout << "The largest element is "
              << *my::max_element(myints, myints + 7, myfn) << '\n';

    // using object myobj as comp:
    std::cout << "The smallest element is "
              << *my::min_element(myints, myints + 7, myobj) << '\n';
    std::cout << "The largest element is "
              << *my::max_element(myints, myints + 7, myobj) << '\n';

    return 0;
}