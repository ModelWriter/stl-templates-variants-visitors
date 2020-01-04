//  ----------------------------------------------------------------------------
//  Header file for the is_sorted_until class.        is_sorted_until.cpp
//  Created by Ferhat Erata <ferhat.erata@yale.edu> on January 03, 2020.
//  Copyright (c) 2020 Yale University. All rights reserved.
// -----------------------------------------------------------------------------

#include "stl.hpp"
#include <algorithm>
#include <iostream>
#include <random>

int main() {
    std::random_device rd;
    std::mt19937 g(rd());
    const int N = 6;
    int nums[N] = {3, 1, 4, 1, 5, 9};

    const int min_sorted_size = 4;
    int sorted_size = 0;
    do {
        std::shuffle(nums, nums + N, g);
        int* sorted_end = my::is_sorted_until(nums, nums + N);
        sorted_size = my::distance(nums, sorted_end);

        for (auto i : nums)
            std::cout << i << ' ';
        std::cout << " : " << sorted_size << " initial sorted elements\n";
    } while (sorted_size < min_sorted_size);
}