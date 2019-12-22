//  ----------------------------------------------------------------------------
//  Header file for the main class.        main.cpp
//  Created by Ferhat Erata <ferhat.erata@yale.edu> on December 21, 2019.
//  Copyright (c) 2019 Yale University. All rights reserved.
// -----------------------------------------------------------------------------

#include "stl.hpp"
#include "utility.hpp"
#include <cctype>
#include <iostream>
#include <string>
#include <vector>

int op_increase(int i) { return ++i; }

int main() {
    std::string s("hello");
    my::transform(
        s.begin(), s.end(), s.begin(),
        [](unsigned char c) -> unsigned char { return std::toupper(c); });

    std::vector<std::size_t> ordinals;
    my::transform(s.begin(), s.end(), std::back_inserter(ordinals),
                  [](unsigned char c) -> std::size_t { return c; });

    std::cout << s << ':';
    for (auto ord : ordinals) {
        std::cout << ' ' << ord;
    }

    std::cout << "\n" << utility::separator();
    // -------------------------------------------------------------------------

    std::vector<int> foo;
    std::vector<int> bar;

    // set some values:
    for (int i = 1; i < 6; i++)
        foo.push_back(i * 10); // foo: 10 20 30 40 50

    bar.resize(foo.size()); // allocate space

    my::transform(foo.begin(), foo.end(), bar.begin(), op_increase);
    // bar: 11 21 31 41 51

    // std::plus adds together its two arguments:
    my::transform(foo.begin(), foo.end(), bar.begin(), foo.begin(),
                  std::plus<>());
    // foo: 21 41 61 81 101

    std::cout << "foo contains:";
    for (auto it = foo.begin(); it != foo.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';

    return 0;
}