//  ----------------------------------------------------------------------------
//  Header file for the main class.        main.cpp
//  Created by Ferhat Erata <ferhat.erata@yale.edu> on January 03, 2020.
//  Copyright (c) 2020 Yale University. All rights reserved.
// -----------------------------------------------------------------------------

#include <algorithm>
#include <iostream>
#include <utility.hpp>
#include <vector>

// Using the erase-remove idiom on std::vector
int main() {
    std::vector<int> v{1, 2, 3, 2, 5, 2, 6, 2, 4, 8};

    for (auto i : v) {
        std::cout << i << ", ";
    }
    std::cout << '\n';

    v.erase(std::remove(std::begin(v), std::end(v), 2), std::end(v));

    for (auto i : v) {
        std::cout << i << ", ";
    }
    std::cout << '\n';

    // -------------------------------------------------------------------------
    std::cout << "\n" << utility::separator();
    // -------------------------------------------------------------------------

    const auto odd = [](int i) { return i % 2 != 0; }; // bool (*)(int) const

    v.erase(std::remove_if(std::begin(v), std::end(v), odd), std::end(v));

    v.shrink_to_fit();

    for (auto i : v) {
        std::cout << i << ", ";
    }
    std::cout << '\n';
}