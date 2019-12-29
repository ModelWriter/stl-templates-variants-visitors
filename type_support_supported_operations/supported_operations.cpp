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

    std::cout << "\n" << utility::separator();
    std::cout
        << "    struct Ex1 {\n"
           "        std::string str; // member has a non-trivial copy ctor\n"
           "    };\n"
           "    struct Ex2 {\n"
           "        int n;\n"
           "        Ex2(const Ex2&) = default; // trivial and non-throwing\n"
           "    };"
        << std::endl;
    std::cout << "\n" << utility::separator();

    std::cout << std::boolalpha << "Ex1 is copy-constructible? "
              << std::is_copy_constructible<Ex1>::value << '\n'
              << "Ex1 is trivially copy-constructible? "
              << std::is_trivially_copy_constructible<Ex1>::value << '\n'
              << "Ex2 is trivially copy-constructible? "
              << std::is_trivially_copy_constructible<Ex2>::value << '\n'
              << "Ex2 is nothrow copy-constructible? "
              << std::is_nothrow_copy_constructible<Ex2>::value << '\n';

    // -------------------------------------------------------------------------

    class Foo {
        int v1;
        double v2;

      public:
        Foo(int n) : v1(n), v2() {}
        Foo(int n, double f) noexcept : v1(n), v2(f) {}
    };

    std::cout << "\n" << utility::separator();
    std::cout << "    class Foo {\n"
                 "        int v1;\n"
                 "        double v2;\n"
                 "\n"
                 "      public:\n"
                 "        Foo(int n) : v1(n), v2() {}\n"
                 "        Foo(int n, double f) noexcept : v1(n), v2(f) {}\n"
                 "    };"
              << std::endl;
    std::cout << "\n" << utility::separator();

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

    struct NoMove {
        // prevents implicit declaration of default move constructor
        // however, the class is still move-constructible because its
        // copy constructor can bind to an rvalue argument
        NoMove(const NoMove&) {}
    };

    std::cout << "\n" << utility::separator();
    std::cout << "    struct NoMove {\n"
                 "        // prevents implicit declaration of default move "
                 "constructor\n"
                 "        // however, the class is still move-constructible "
                 "because its\n"
                 "        // copy constructor can bind to an rvalue argument\n"
                 "        NoMove(const NoMove&) {}\n"
                 "    };"
              << std::endl;
    std::cout << "\n" << utility::separator();

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

    struct Ex3 {
        int n;
    };

    std::cout << "\n" << utility::separator();
    std::cout << "    struct Ex3 {\n"
                 "        int n;\n"
                 "    };"
              << std::endl;
    std::cout << "\n" << utility::separator();

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
              << "Ex3& is trivially assignable from const Ex3&? "
              << std::is_trivially_assignable<Ex3&, const Ex3&>::value << '\n';

    // -------------------------------------------------------------------------

    struct Foo1 {
        int n;
    };

    std::cout << "\n" << utility::separator();
    std::cout << "    struct Foo1 {\n"
                 "        int n;\n"
                 "    };"
              << std::endl;
    std::cout << "\n" << utility::separator();

    std::cout << std::boolalpha << "Foo1 is trivially copy-assignable? "
              << std::is_trivially_copy_assignable<Foo1>::value << '\n'
              << "int[2] is copy-assignable? "
              << std::is_copy_assignable<int[2]>::value << '\n'
              << "int is nothrow copy-assignable? "
              << std::is_nothrow_copy_assignable<int>::value << '\n';

    // -------------------------------------------------------------------------

    struct Foo2 {
        int n;
    };
    struct NoMove1 {
        // prevents implicit declaration of default move assignment operator
        // however, the class is still move-assignable because its
        // copy assignment operator can bind to an rvalue argument
        NoMove1& operator=(const NoMove1&) { return *this; }
    };

    std::cout << "\n" << utility::separator();
    std::cout
        << "    struct Foo2 {\n"
           "        int n;\n"
           "    };\n"
           "    struct NoMove1 {\n"
           "        // prevents implicit declaration of default move "
           "assignment operator\n"
           "        // however, the class is still move-assignable because "
           "its\n"
           "        // copy assignment operator can bind to an rvalue "
           "argument\n"
           "        NoMove1& operator=(const NoMove1&) { return *this; }\n"
           "    };"
        << std::endl;
    std::cout << "\n" << utility::separator();

    std::cout << std::boolalpha << "std::string is nothrow move-assignable? "
              << std::is_nothrow_move_assignable<std::string>::value << '\n'
              << "int[2] is move-assignable? "
              << std::is_move_assignable<int[2]>::value << '\n'
              << "Foo2 is trivially move-assignable? "
              << std::is_trivially_move_assignable<Foo2>::value << '\n';

    std::cout << std::boolalpha << "NoMove1 is move-assignable? "
              << std::is_move_assignable<NoMove1>::value << '\n'
              << "NoMove1 is nothrow move-assignable? "
              << std::is_nothrow_move_assignable<NoMove1>::value << '\n';

    // -------------------------------------------------------------------------

    struct Foo2 {
        std::string str;
        ~Foo2() noexcept {};
    };
    struct Bar {
        ~Bar() = default;
    };

    std::cout << "\n" << utility::separator();
    std::cout << "    struct Foo2 {\n"
                 "        std::string str;\n"
                 "        ~Foo2() noexcept {};\n"
                 "    };\n"
                 "    struct Bar {\n"
                 "        ~Bar() = default;\n"
                 "    };"
              << std::endl;
    std::cout << "\n" << utility::separator();

    std::cout << std::boolalpha << "std::string is destructible? "
              << std::is_destructible<std::string>::value << '\n'
              << "Foo2 is nothrow destructible? "
              << std::is_nothrow_destructible<Foo2>::value << '\n'
              << "Bar is trivially destructible? "
              << std::is_trivially_destructible<Bar>::value << '\n';
}