//  ----------------------------------------------------------------------------
//  Header file for the main class.        main.cpp
//  Created by Ferhat Erata <ferhat.erata@yale.edu> on December 21, 2019.
//  Copyright (c) 2019 Yale University. All rights reserved.
// -----------------------------------------------------------------------------

#include "stl.hpp"
#include <iostream>
#include <vector>

struct Sum {
    int sum;
    Sum() : sum{0} {}
    void operator()(int n) { sum += n; }
};

int main() {
    std::vector<int> nums{3, 4, 2, 8, 15, 267};

    auto print = [](const int& n) { std::cout << " " << n; };

    std::cout << "before:";
    my::for_each(nums.begin(), nums.end(), print);
    std::cout << '\n';

    my::for_each(nums.begin(), nums.end(), [](int& n) { n++; });

    // calls Sum::operator() for each number
    Sum s = my::for_each(nums.begin(), nums.end(), Sum());

    std::cout << "after: ";
    my::for_each(nums.begin(), nums.end(), print);
    std::cout << '\n';
    std::cout << "sum: " << s.sum << '\n';
}