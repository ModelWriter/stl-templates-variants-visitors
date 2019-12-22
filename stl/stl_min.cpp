//  ----------------------------------------------------------------------------
//  Header file for the main class.                                     main.cpp
//  Created by Ferhat Erata <ferhat.erata@yale.edu> on December 21, 2019.
//  Copyright (c) 2019 Yale University. All rights reserved.
// -----------------------------------------------------------------------------

#include "stl.hpp"
#include "utility.hpp"
#include <iostream>
#include <vector>

int main() {

    std::cout << "smaller of 1 and 9999: " << my::min(1, 9999) << '\n'
              << "smaller of 'a', and 'b': " << my::min('a', 'b') << '\n'
              << R"(shortest of "foo", "bar", and "hello": )"
              << my::min({"foo", "bar", "hello"},
                         [](const std::string& s1, const std::string& s2) {
                             return s1.size() < s2.size();
                         })
              << '\n';

    // -------------------------------------------------------------------------
    std::cout << "\n" << utility::separator();
    // -------------------------------------------------------------------------

    std::cout << "min(1,2)==" << my::min(1, 2) << '\n';
    std::cout << "min(2,1)==" << my::min(2, 1) << '\n';
    std::cout << "min('a','z')==" << my::min('a', 'z') << '\n';
    std::cout << "min(3.14,2.72)==" << my::min(3.14, 2.72) << '\n';

    return 0;
}