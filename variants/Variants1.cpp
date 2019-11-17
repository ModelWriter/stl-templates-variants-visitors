//  ----------------------------------------------------------------------------
//  Header file for the Variants class.        Variants.cpp
//  Created by Ferhat Erata <ferhat.erata@yale.edu> on November 11, 2019.
//  Copyright (c) 2019 Yale University. All rights reserved.
// -----------------------------------------------------------------------------

#include <iostream>
#include <variant>

template <typename... Fs> struct overload : Fs... { using Fs::operator()...; };

template <typename... Fs> overload(Fs... fs)->overload<Fs...>;

int main() {

    std::variant<bool, int, std::string> v = 5;

    std::visit(overload{[](bool b) { std::cout << "got bool: " << b << "\n"; },
                        [](int n) { std::cout << "got int: " << n << "\n"; },
                        [](const std::string& s) {
                            std::cout << "got string: " << s << "\n";
                        }},
               v);

    return 0;
}