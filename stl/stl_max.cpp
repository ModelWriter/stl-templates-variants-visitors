//  ----------------------------------------------------------------------------
//  Header file for the main class.                                     main.cpp
//  Created by Ferhat Erata <ferhat.erata@yale.edu> on December 21, 2019.
//  Copyright (c) 2019 Yale University. All rights reserved.
// -----------------------------------------------------------------------------

#include "stl.hpp"
#include "utility.hpp"
#include <iostream>

int main() {

    std::cout << "larger of 1 and 9999: " << my::max(1, 9999) << '\n'
              << "larger of 'a', and 'b': " << my::max('a', 'b') << '\n'
              << R"(longest of "foo", "bar", and "hello": )"
              << my::max({"foo", "bar", "hello"},
                         [](const std::string& s1, const std::string& s2) {
                             return s1.size() < s2.size();
                         })
              << '\n';

    // -------------------------------------------------------------------------
    std::cout << "\n" << utility::separator();
    // -------------------------------------------------------------------------

    std::cout << "max(1,2)==" << my::max(1, 2) << '\n';
    std::cout << "max(2,1)==" << my::max(2, 1) << '\n';
    std::cout << "max('a','z')==" << my::max('a', 'z') << '\n';
    std::cout << "max(3.14,2.73)==" << my::max(3.14, 2.73) << '\n';

    return 0;
}