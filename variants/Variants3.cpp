//  ----------------------------------------------------------------------------
//  Header file for the Variants class.        Variants.cpp
//  Created by Ferhat Erata <ferhat.erata@yale.edu> on November 11, 2019.
//  Copyright (c) 2019 Yale University. All rights reserved.
// -----------------------------------------------------------------------------

#include <iostream>
#include <variant>

template <typename... Fs> struct overload : Fs... { using Fs::operator()...; };

template <typename... Fs> overload(Fs... fs)->overload<Fs...>;

struct Rgb {
    int red;
    int green;
    int blue;
};
struct Hsv {
    int hue;
    int saturation;
    int value;
};

using Color = std::variant<Rgb, Hsv>;
struct ChangeColor {
    Color color;
};

struct Quit {};
struct Move {
    int x;
    int y;
};
struct Write {
    std::string text;
};

using Message = std::variant<Quit, Move, Write, ChangeColor>;

int main() {

    Message msg = ChangeColor{Rgb{1, 160, 255}};

    std::visit( //
        overload{
            [](const Quit&) { std::cout << "Done\n"; },
            [](const Move& move) {
                const auto& [x, y] = move;
                std::cout << "Move by: " << x << ',' << y << '\n';
            },
            [](const Write& write) {
                const auto& [text] = write;
                std::cout << "Text message: " << text << '\n';
            },
            [](const ChangeColor& change_color) {
                const auto& [color] = change_color;
                std::cout << "Changing color ";
                std::visit(overload{[](const Rgb& rgb) {
                                        const auto& [r, g, b] = rgb;
                                        std::cout << "to RGB: " << r << ',' << g
                                                  << ',' << b << '\n';
                                    },
                                    [](const Hsv& hsv) {
                                        const auto& [h, s, v] = hsv;
                                        std::cout << "to HSV: " << h << ',' << s
                                                  << ',' << v << '\n';
                                    }},
                           color);
            },
        },
        msg);
    return 0;
}