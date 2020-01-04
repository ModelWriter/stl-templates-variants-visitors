//  ----------------------------------------------------------------------------
//  Header file for the delete class.        delete-quick.cpp
//  Created by Ferhat Erata <ferhat.erata@yale.edu> on January 03, 2020.
//  Copyright (c) 2020 Yale University. All rights reserved.
// -----------------------------------------------------------------------------

#include "utility.hpp"
#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

template <typename T> void quick_remove_at(std::vector<T>& v, std::size_t idx) {
    if (idx < v.size()) {
        v[idx] = std::move(v.back());
        v.pop_back();
    }
}

template <typename T>
void quick_remove_at(std::vector<T>& v, typename std::vector<T>::iterator it) {
    if (it != std::end(v)) {
        *it = std::move(v.back());
        v.pop_back();
    }
}

int main() {
    std::vector<int> v{123, 456, 789, 100, 200};

    // The next step is to delete the value at index 2 (counting from zero of
    // course, so it's the third number 789).
    quick_remove_at(v, 2);
    for (int i : v) {
        std::cout << i << ", ";
    }
    std::cout << '\n';

    // It will be the value 123, and let's say we don't know its index.
    // Therefore, we will use the std::find function, which accepts a range (the
    // vector), and a value, and then searches for the value's position.
    quick_remove_at(v, std::find(std::begin(v), std::end(v), 123));
    for (int i : v) {
        std::cout << i << ", ";
    }
    std::cout << '\n';

    // -------------------------------------------------------------------------
    std::cout << "\n" << utility::separator();
    // -------------------------------------------------------------------------
}