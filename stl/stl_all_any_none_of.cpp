//  ----------------------------------------------------------------------------
//  Header file for the main class.                                     main.cpp
//  Created by Ferhat Erata <ferhat.erata@yale.edu> on December 21, 2019.
//  Copyright (c) 2019 Yale University. All rights reserved.
// -----------------------------------------------------------------------------

#include "stl.hpp"
#include "utility.hpp"
#include <functional>
#include <iostream>
#include <numeric>
#include <vector>

struct DivisibleBy {
    const int divider{};
    explicit DivisibleBy(int d) : divider(d) {}
    bool operator()(int n) const { return n % divider == 0; }
};

int main() {

    std::vector<int> vector(10, 2);
    std::partial_sum(vector.cbegin(), vector.cend(), vector.begin());
    std::cout << "Among the numbers: ";
    std::copy(vector.cbegin(), vector.cend(),
              std::ostream_iterator<int>(std::cout, " "));
    std::cout << '\n';
    // Among the numbers: 2 4 6 8 10 12 14 16 18 20

    if (my::all_of(vector.cbegin(), vector.cend(),
                   [](int i) { return i % 2 == 0; })) {
        std::cout << "All numbers are even\n";
    }
    //  All numbers are even
    if (my::none_of(vector.cbegin(), vector.cend(),
                    std::bind(std::modulus<>(), std::placeholders::_1, 2))) {
        std::cout << "None of them are odd\n";
    }
    // None of them are odd
    if (my::any_of(vector.cbegin(), vector.cend(), DivisibleBy(7))) {
        std::cout << "At least one number is divisible by 7\n";
    }
    // At least one number is divisible by 7

    // -------------------------------------------------------------------------
    std::cout << "\n" << utility::separator();
    // -------------------------------------------------------------------------

    return 0;
}