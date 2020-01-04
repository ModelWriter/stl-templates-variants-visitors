//  ----------------------------------------------------------------------------
//  Header file for the distance class.        distance.cpp
//  Created by Ferhat Erata <ferhat.erata@yale.edu> on January 03, 2020.
//  Copyright (c) 2020 Yale University. All rights reserved.
// -----------------------------------------------------------------------------

#include "stl.hpp"  // my::distance
#include <iostream> // std::cout
#include <list>     // std::list

int main() {
    std::list<int> list;
    for (int i = 0; i < 10; i++)
        list.push_back(i * 10);

    auto first = list.begin();
    auto last = list.end();

    std::cout << "The distance is: " << my::distance(first, last) << '\n';

    return 0;
}