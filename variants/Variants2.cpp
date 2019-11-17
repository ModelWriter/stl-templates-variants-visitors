//  ----------------------------------------------------------------------------
//  Header file for the Variants class.        Variants.cpp
//  Created by Ferhat Erata <ferhat.erata@yale.edu> on November 11, 2019.
//  Copyright (c) 2019 Yale University. All rights reserved.
// -----------------------------------------------------------------------------

#include <iostream>
#include <variant>

template <typename... Fs> struct overload : Fs... { using Fs::operator()...; };

template <typename... Fs> overload(Fs... fs)->overload<Fs...>;

struct Quit {};
struct Move {
    int x;
    int y;
};
struct Write {
    std::string text;
};
struct ChangeColor {
    int red;
    int green;
    int blue;
};

using Message = std::variant<Quit, Move, Write, ChangeColor>;

int main() {

    Message msg = ChangeColor{0, 160, 255};
    std::visit(overload{[](const Quit&) { std::cout << "Done\n"; },
                        [](const Move& move) {
                          const auto& [x, y] = move;
                          std::cout << "Move by: " << x << ',' << y << '\n';
                        },
                        [](const Write& write) {
                          const auto& [text] = write;
                          std::cout << "Text message: " << text << '\n';
                        },
                        [](const ChangeColor& change_color) {
                          const auto& [r, g, b] = change_color;
                          std::cout << "to RGB: " << r << ',' << g << ',' << b
                                    << '\n';
                        }},
               msg);

    return 0;
}
