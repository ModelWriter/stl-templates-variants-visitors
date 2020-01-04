//  ----------------------------------------------------------------------------
//  Header file for the insert_sorted class.        insert_sorted.cpp
//  Created by Ferhat Erata <ferhat.erata@yale.edu> on January 03, 2020.
//  Copyright (c) 2020 Yale University. All rights reserved.
// -----------------------------------------------------------------------------

#include "../stl.hpp"
#include <algorithm>
#include <cassert>
#include <string>
#include <vector>

int main() {
    std::vector<std::string> v{"some",  "random", "words", "without",
                               "order", "aaa",    "yyy"};
    assert(!my::is_sorted(begin(v), end(v)));
    std::sort(begin(v), end(v));
    assert(std::is_sorted(begin(v), end(v)));
}