//  ----------------------------------------------------------------------------
//  Header file for the main class.                                     main.cpp
//  Created by Ferhat Erata <ferhat.erata@yale.edu> on December 21, 2019.
//  Copyright (c) 2019 Yale University. All rights reserved.
// -----------------------------------------------------------------------------

#include "stl.hpp"
#include "utility.hpp"
#include <array>
#include <iostream>
#include <vector>

static bool abs_compare(int a, int b) { return (std::abs(a) < std::abs(b)); }

int main() {

    const auto v = {3, 9, 1, 4, 2, 5, -9};
    const auto [min, max] = my::minmax_element(begin(v), end(v), abs_compare);

    std::cout << "min = " << *min << ", max = " << *max << '\n';
    // min = 1, max = 9

    // -------------------------------------------------------------------------
    std::cout << "\n" << utility::separator();
    // -------------------------------------------------------------------------

    std::array<int, 7> foo{3, 7, 2, 9, 5, 8, 6};

    auto result = my::minmax_element(foo.begin(), foo.end());

    // print result:
    std::cout << "min is " << *result.first;
    std::cout << ", at position " << (result.first - foo.begin()) << '\n';
    std::cout << "max is " << *result.second;
    std::cout << ", at position " << (result.second - foo.begin()) << '\n';

    // min is 2, at position 2
    // max is 9, at position 3

    return 0;
}