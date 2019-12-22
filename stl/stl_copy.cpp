//  ----------------------------------------------------------------------------
//  Header file for the main class.                                     main.cpp
//  Created by Ferhat Erata <ferhat.erata@yale.edu> on December 21, 2019.
//  Copyright (c) 2019 Yale University. All rights reserved.
// -----------------------------------------------------------------------------

#include "stl.hpp"
#include "utility.hpp"
#include <iostream>
#include <numeric>
#include <vector>

int main() {

    std::vector<int> from_vector(10);
    std::iota(from_vector.begin(), from_vector.end(), 0);

    std::vector<int> to_vector;
    my::copy(from_vector.begin(), from_vector.end(),
             std::back_inserter(to_vector));

    std::cout << "to_vector contains: ";

    my::copy(to_vector.begin(), to_vector.end(),
             std::ostream_iterator<int>(std::cout, " "));
    std::cout << '\n';
    // to_vector contains: 0 1 2 3 4 5 6 7 8 9

    // -------------------------------------------------------------------------
    std::cout << "\n" << utility::separator();
    // -------------------------------------------------------------------------
    std::vector<int> foo = {25, 15, 5, -5, -15};
    std::vector<int> bar(foo.size());

    // copy only positive numbers:
    auto it = my::copy_if(foo.begin(), foo.end(), bar.begin(),
                          [](int i) { return i >= 0; });
    bar.resize(std::distance(bar.begin(), it)); // shrink container to new size

    std::cout << "bar contains:";
    for (auto& x : bar)
        std::cout << ' ' << x;
    std::cout << '\n';
    // bar contains: 25 15 5

    return 0;
}