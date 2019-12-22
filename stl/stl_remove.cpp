//  ----------------------------------------------------------------------------
//  Header file for the main class.                                     main.cpp
//  Created by Ferhat Erata <ferhat.erata@yale.edu> on December 21, 2019.
//  Copyright (c) 2019 Yale University. All rights reserved.
// -----------------------------------------------------------------------------

#include "stl.hpp"
#include "utility.hpp"
#include <iostream>
#include <vector>

int main() {

    std::string str1 = "Text with some   spaces";
    str1.erase(my::remove(str1.begin(), str1.end(), ' '), str1.end());
    std::cout << str1 << '\n';
    // Textwithsomespaces

    std::string str2 = "Text\n with\tsome \t  whitespaces\n\n";
    str2.erase(my::remove_if(str2.begin(), str2.end(),
                             [](unsigned char x) { return std::isspace(x); }),
               str2.end());
    std::cout << str2 << '\n';
    // Textwithsomewhitespaces

    // -------------------------------------------------------------------------
    std::cout << "\n" << utility::separator();
    // -------------------------------------------------------------------------

    int my_ints[] = {10, 20, 30, 30, 20, 10, 10, 20};
    // 10 20 30 30 20 10 10 20

    // bounds of range:
    int* p_begin = my_ints;
    // ^
    int* p_end = my_ints + sizeof(my_ints) / sizeof(int);
    // ^                       ^

    p_end = my::remove(p_begin, p_end, 20);
    // 10 30 30 10 10 ?  ?  ?
    // ^              ^

    std::cout << "range contains:";
    for (int* p = p_begin; p != p_end; ++p)
        std::cout << ' ' << *p;
    std::cout << '\n';
    // range contains: 10 30 30 10 10

    // -------------------------------------------------------------------------
    std::cout << "\n" << utility::separator();
    // -------------------------------------------------------------------------

    int myints[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    // 1 2 3 4 5 6 7 8 9

    // bounds of range:
    int* pbegin = myints;
    // 1 2 3 4 5 6 7 8 9
    // ^
    int* pend = myints + sizeof(myints) / sizeof(int);
    // 1 2 3 4 5 6 7 8 9
    // ^                 ^

    pend = my::remove_if(pbegin, pend, [](int i) { return i % 2 == 1; });
    // 2 4 6 8 ? ? ? ? ?
    // ^       ^

    std::cout << "the range contains:";
    for (int* p = pbegin; p != pend; ++p)
        std::cout << ' ' << *p;
    std::cout << '\n';
    // the range contains: 2 4 6 8

    return 0;
}