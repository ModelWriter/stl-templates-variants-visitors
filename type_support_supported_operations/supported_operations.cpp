//  ----------------------------------------------------------------------------
//  Header file for the is_copy_constructible class. is_copy_constructible.hpp
//  Created by Ferhat Erata <ferhat.erata@yale.edu> on December 29, 2019.
//  Copyright (c) 2019 Yale University. All rights reserved.
//  https://en.cppreference.com/w/cpp/types/is_copy_constructible
//  https://en.cppreference.com/w/cpp/types/is_constructible
//  https://en.cppreference.com/w/cpp/types/is_move_constructible
//
//  https://en.cppreference.com/w/cpp/types/is_assignable
// -----------------------------------------------------------------------------

#include "../utility.hpp"
#include <iostream>
#include <type_traits>

int main() {

    struct Ex1 {
        std::string str; // member has a non-trivial copy ctor
    };
    struct Ex2 {
        int n;
        Ex2(const Ex2&) = default; // trivial and non-throwing
    };

    std::cout << std::boolalpha << "Ex1 is copy-constructible? "
              << std::is_copy_constructible<Ex1>::value << '\n'
              << "Ex1 is trivially copy-constructible? "
              << std::is_trivially_copy_constructible<Ex1>::value << '\n'
              << "Ex2 is trivially copy-constructible? "
              << std::is_trivially_copy_constructible<Ex2>::value << '\n'
              << "Ex2 is nothrow copy-constructible? "
              << std::is_nothrow_copy_constructible<Ex2>::value << '\n';

    // -------------------------------------------------------------------------
    std::cout << "\n" << utility::separator();
    // -------------------------------------------------------------------------

    class Foo {
        int v1;
        double v2;

      public:
        Foo(int n) : v1(n), v2() {}
        Foo(int n, double f) noexcept : v1(n), v2(f) {}
    };

    std::cout << "Foo is ...\n"
              << std::boolalpha << "\tTrivially-constructible from const Foo&? "
              << std::is_trivially_constructible<Foo, const Foo&>::value << '\n'
              << "\tTrivially-constructible from int? "
              << std::is_trivially_constructible<Foo, int>::value << '\n'
              << "\tConstructible from int? "
              << std::is_constructible<Foo, int>::value << '\n'
              << "\tNothrow-constructible from int? "
              << std::is_nothrow_constructible<Foo, int>::value << '\n'
              << "\tNothrow-constructible from int and double? "
              << std::is_nothrow_constructible<Foo, int, double>::value << '\n';

    // -------------------------------------------------------------------------
    std::cout << "\n" << utility::separator();
    // -------------------------------------------------------------------------

    struct NoMove {
        // prevents implicit declaration of default move constructor
        // however, the class is still move-constructible because its
        // copy constructor can bind to an rvalue argument
        NoMove(const NoMove&) {}
    };

    std::cout << std::boolalpha << "Ex1 is move-constructible? "
              << std::is_move_constructible<Ex1>::value << '\n'
              << "Ex1 is trivially move-constructible? "
              << std::is_trivially_move_constructible<Ex1>::value << '\n'
              << "Ex1 is nothrow move-constructible? "
              << std::is_nothrow_move_constructible<Ex1>::value << '\n'
              << "Ex2 is trivially move-constructible? "
              << std::is_trivially_move_constructible<Ex2>::value << '\n'
              << "Ex2 is nothrow move-constructible? "
              << std::is_nothrow_move_constructible<Ex2>::value << '\n';

    std::cout << std::boolalpha << "NoMove is move-constructible? "
              << std::is_move_constructible<NoMove>::value << '\n'
              << "NoMove is nothrow move-constructible? "
              << std::is_nothrow_move_constructible<NoMove>::value << '\n';

    // -------------------------------------------------------------------------
    std::cout << "\n" << utility::separator();
    // -------------------------------------------------------------------------

    std::cout << std::boolalpha << "int is assignable from int? "
              << std::is_assignable<int, int>::value
              << '\n' // 1 = 1; wouldn't compile
              << "int& is assignable from int? "
              << std::is_assignable<int&, int>::value
              << '\n' // int a; a = 1; works
              << "int is assignable from double? "
              << std::is_assignable<int, double>::value << '\n'
              << "int& is nothrow assignable from double? "
              << std::is_nothrow_assignable<int&, double>::value << '\n'
              << "string is assignable from double? "
              << std::is_assignable<std::string, double>::value << '\n'
              << "Ex1& is trivially assignable from const Ex1&? "
              << std::is_trivially_assignable<Ex1&, const Ex1&>::value << '\n';
}