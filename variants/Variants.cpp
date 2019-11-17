//  ----------------------------------------------------------------------------
//  Header file for the Variants class.        Variants.cpp
//  Created by Ferhat Erata <ferhat.erata@yale.edu> on November 11, 2019.
//  Copyright (c) 2019 Yale University. All rights reserved.
// -----------------------------------------------------------------------------

#include <iostream>
#include <variant>

struct Fluid {};
struct LightItem {};
struct HeavyItem {};
struct FragileItem {};

struct VisitPackage {
    void operator()(Fluid&) { std::cout << "fluid\n"; }
    void operator()(LightItem&) { std::cout << "light item\n"; }
    void operator()(HeavyItem&) { std::cout << "heavy item\n"; }
    void operator()(FragileItem&) { std::cout << "fragile\n"; }
};

int main() {
    std::variant<Fluid, LightItem, HeavyItem, FragileItem> package{
        FragileItem()};

    std::visit(VisitPackage(), package);

    return 0;
}