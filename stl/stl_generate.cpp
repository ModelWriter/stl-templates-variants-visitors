//  ----------------------------------------------------------------------------
//  Header file for the main class.                                     main.cpp
//  Created by Ferhat Erata <ferhat.erata@yale.edu> on December 21, 2019.
//  Copyright (c) 2019 Yale University. All rights reserved.
// -----------------------------------------------------------------------------

#include "stl.hpp"
#include "utility.hpp"
#include <ctime>
#include <iostream>
#include <vector>

int f() {
    static int i = 1;
    return i++;
}

// function generator:
int RandomNumber() { return std::rand() % 100; }

// class generator:
struct c_unique {
    int current;
    c_unique() { current = 0; }
    int operator()() { return ++current; }
};

int main() {

    std::vector<int> vector(5);
    my::generate(vector.begin(), vector.end(), f);

    std::cout << "vector: ";
    for (auto iv : vector) {
        std::cout << iv << " ";
    }
    std::cout << "\n";
    // v: 1 2 3 4 5

    // Initialize with default values 0,1,2,3,4 from a lambda function
    // Equivalent to std::iota(v.begin(), v.end(), 0);
    my::generate(vector.begin(), vector.end(),
                 [n = 0]() mutable { return n++; });

    std::cout << "vector: ";
    for (auto iv : vector) {
        std::cout << iv << " ";
    }
    std::cout << "\n";
    // v: 0 1 2 3 4

    // -------------------------------------------------------------------------
    std::cout << "\n" << utility::separator();
    // -------------------------------------------------------------------------

    std::srand(unsigned(std::time(nullptr)));

    std::vector<int> my_vector(8);

    my::generate(my_vector.begin(), my_vector.end(), RandomNumber);

    std::cout << "my_vector contains:";
    for (auto it = my_vector.begin(); it != my_vector.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';
    // my_vector contains: 57 87 76 66 85 54 17 15

    my::generate(my_vector.begin(), my_vector.end(), c_unique());

    std::cout << "my_vector contains:";
    for (auto it = my_vector.begin(); it != my_vector.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';
    // my_vector contains: 1 2 3 4 5 6 7 8

    return 0;
}