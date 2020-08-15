//  ----------------------------------------------------------------------------
//  Header file for the insert_sorted class.        insert_sorted.cpp
//  Created by Ferhat Erata <ferhat.erata@yale.edu> on January 03, 2020.
//  Copyright (c) 2020 Yale University. All rights reserved.
// -----------------------------------------------------------------------------

#include "../stl.hpp"
#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

void insert_sorted(std::vector<std::string>& v, const std::string& word) {
    const auto insert_pos(lower_bound(begin(v), end(v), word));
    v.insert(insert_pos, word);
}

int main() {
    std::vector<std::string> v{"some",  "random", "words", "without",
                               "order", "aaa",    "yyy"};
    assert(!my::is_sorted(begin(v), end(v)));
    std::sort(begin(v), end(v));
    assert(std::is_sorted(begin(v), end(v)));

    insert_sorted(v, "foobar");
    insert_sorted(v, "zzz");

    for (const auto& w : v) {
        std::cout << w << " ";
    }
    std::cout << '\n';
}