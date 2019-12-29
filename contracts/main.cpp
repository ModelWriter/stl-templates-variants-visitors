//  ----------------------------------------------------------------------------
//  Header file for the main class.        main.cpp
//  Created by Ferhat Erata <ferhat.erata@yale.edu> on December 28, 2019.
//  Copyright (c) 2019 Yale University. All rights reserved.
// -----------------------------------------------------------------------------

#include "length.hpp"
#include <iomanip>
#include <iostream>
#include <utility.hpp>

int main() {
    utility::banner();

    std::cout << std::setprecision(2) << std::fixed;

    length l{4};
    length m{5};
    auto result = calculate_perimeter(l, m);
    std::cout << result << std::endl;

    std::cout << "\nPlease enter width and length: ";
    length x;
    length y;
    std::cin >> x >> y;
    if (!std::cin.good())
        throw utility::fatal("IO Error");
    result = calculate_perimeter(x, y);
    std::cout << result << std::endl;

    utility::bye();
    return 0;
}