//  ----------------------------------------------------------------------------
//  Header file for the main class.        main.cpp
//  Created by Ferhat Erata <ferhat.erata@yale.edu> on December 21, 2019.
//  Copyright (c) 2019 Yale University. All rights reserved.
// -----------------------------------------------------------------------------

#include "stl.hpp"
#include <algorithm>
#include <iostream>
#include <utility.hpp>
#include <vector>

int main() {

    int myints[] = {10, 20, 30, 5, 15};
    std::vector<int> vector(myints, myints + 5);

    std::make_heap(vector.begin(), vector.end());
    std::cout << "initial max heap   : " << vector.front() << '\n';

    std::pop_heap(vector.begin(), vector.end());
    vector.pop_back();
    std::cout << "max heap after pop : " << vector.front() << '\n';

    vector.push_back(99);
    std::push_heap(vector.begin(), vector.end());
    std::cout << "max heap after push: " << vector.front() << '\n';

    std::sort_heap(vector.begin(), vector.end());

    std::cout << "final sorted range :";
    
    for (int i : vector)
        std::cout << ' ' << i;

    std::cout << '\n';

    // -------------------------------------------------------------------------
    std::cout << "\n" << utility::separator();
    // -------------------------------------------------------------------------

    return 0;
}