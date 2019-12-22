//  ----------------------------------------------------------------------------
//  Header file for the main class.        main.cpp
//  Created by Ferhat Erata <ferhat.erata@yale.edu> on December 21, 2019.
//  Copyright (c) 2019 Yale University. All rights reserved.
// -----------------------------------------------------------------------------

#include "stl.hpp"
#include "utility.hpp"
#include <iostream>
#include <vector>

bool comp_case_insensitive(char c1, char c2) {
    return (std::tolower(c1) == std::tolower(c2));
}

int main() {

    std::vector<int> v{0, 2, 3, 25, 5};
    std::vector<int> t{3, 19, 10, 2};

    auto result = my::find_first_of(v.begin(), v.end(), t.begin(), t.end());

    if (result == v.end()) {
        std::cout << "no elements of v were equal to 3, 19, 10 or 2\n";
    } else {
        std::cout << "found a match at " << std::distance(v.begin(), result)
                  << "\n";
    }

    // -------------------------------------------------------------------------
    std::cout << "\n" << utility::separator();
    // -------------------------------------------------------------------------

    int my_chars[] = {'a', 'b', 'c', 'A', 'B', 'C'};
    std::vector<char> haystack(my_chars, my_chars + 6);
    std::vector<char>::iterator it;

    int needle[] = {'A', 'B', 'C'};

    // using default comparison:
    it =
        my::find_first_of(haystack.begin(), haystack.end(), needle, needle + 3);

    if (it != haystack.end())
        std::cout << "The first match is: " << *it << '\n';

    // using predicate comparison:
    it = my::find_first_of(haystack.begin(), haystack.end(), needle, needle + 3,
                           comp_case_insensitive);

    if (it != haystack.end())
        std::cout << "The first match is: " << *it << '\n';

    return 0;
}