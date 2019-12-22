//  ----------------------------------------------------------------------------
//  Header file for the main class.        main.cpp
//  Created by Ferhat Erata <ferhat.erata@yale.edu> on December 21, 2019.
//  Copyright (c) 2019 Yale University. All rights reserved.
// -----------------------------------------------------------------------------

#include "stl.hpp"
#include "utility.hpp"
#include <array>
#include <iostream>
#include <string>
#include <vector>

bool IsOdd(int i) { return ((i % 2) == 1); }

int main() {

    int n1 = 3;
    int n2 = 5;

    std::vector<int> v{0, 1, 2, 3, 4};

    auto result1 = my::find(std::begin(v), std::end(v), n1);
    auto result2 = my::find(std::begin(v), std::end(v), n2);

    if (result1 != std::end(v)) {
        std::cout << "v contains: " << n1 << '\n';
    } else {
        std::cout << "v does not contain: " << n1 << '\n';
    }

    if (result2 != std::end(v)) {
        std::cout << "v contains: " << n2 << '\n';
    } else {
        std::cout << "v does not contain: " << n2 << '\n';
    }

    // -------------------------------------------------------------------------
    std::cout << "\n" << utility::separator();
    // -------------------------------------------------------------------------

    // using std::find with array and pointer:
    int my_ints[] = {10, 20, 30, 40};
    int* p;

    p = my::find(my_ints, my_ints + 4, 30);
    if (p != my_ints + 4)
        std::cout << "Element found in my ints: " << *p << '\n';
    else
        std::cout << "Element not found in my ints\n";

    // using std::find with vector and iterator:
    std::vector<int> my_vector(my_ints, my_ints + 4);
    std::vector<int>::iterator iter1;

    iter1 = my::find(my_vector.begin(), my_vector.end(), 30);
    if (iter1 != my_vector.end())
        std::cout << "Element found in my vector: " << *iter1 << '\n';
    else
        std::cout << "Element not found in my vector\n";

    // -------------------------------------------------------------------------
    std::cout << "\n" << utility::separator();
    // -------------------------------------------------------------------------

    std::vector<int> my_vector_1;

    my_vector_1.push_back(10);
    my_vector_1.push_back(25);
    my_vector_1.push_back(40);
    my_vector_1.push_back(55);

    auto iter2 = my::find_if(my_vector_1.begin(), my_vector_1.end(), IsOdd);
    std::cout << "The first odd value is " << *iter2 << '\n';

    // -------------------------------------------------------------------------
    std::cout << "\n" << utility::separator();
    // -------------------------------------------------------------------------

    std::array<int, 5> foo = {1, 2, 3, 4, 5};

    auto iter =
        my::find_if_not(foo.begin(), foo.end(), [](int i) { return i % 2; });

    std::cout << "The first even value is " << *iter << '\n';

    return 0;
}