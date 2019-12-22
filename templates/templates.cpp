//  ----------------------------------------------------------------------------
//  Header file for the templates class.        templates.hpp
//  Created by Ferhat Erata <ferhat.erata@yale.edu> on December 14, 2019.
//  Copyright (c) 2019 Yale University. All rights reserved.
// -----------------------------------------------------------------------------

#ifndef DB_GEN_TEMPLATES_HPP
#define DB_GEN_TEMPLATES_HPP

#include <iostream>
#include <tuple>
#include <vector>

template <class... T_values> class relation {
  private:
    const std::string name;
    const std::vector<std::string> column_list;
    std::vector<std::tuple<T_values...>> tuple_list;

  public:
    relation(std::string name, std::initializer_list<std::string> list)
        : name(std::move(name)), column_list(list) {}

    void add(T_values... values) {
        tuple_list.push_back(std::tuple<T_values...>(values...));
    }
};

std::tuple<double, char, std::string> get_student(int id) {
    if (id == 0)
        return std::make_tuple(3.8, 'A', "Lisa Simpson");
    if (id == 1)
        return std::make_tuple(2.9, 'C', "Milhouse Van Houten");
    if (id == 2)
        return std::make_tuple(1.7, 'D', "Ralph Wiggum");
    throw std::invalid_argument("id");
}
// -----------------------------------------------------------------------------
// helper function to print a tuple of any size
template <class Tuple, std::size_t N> struct TuplePrinter {
    static void print(const Tuple& t) {
        TuplePrinter<Tuple, N - 1>::print(t);
        std::cout << ", " << std::get<N - 1>(t);
    }
};

template <class Tuple> struct TuplePrinter<Tuple, 1> {
    static void print(const Tuple& t) { std::cout << std::get<0>(t); }
};

template <class... Args> void print(const std::tuple<Args...>& t) {
    std::cout << "(";
    TuplePrinter<decltype(t), sizeof...(Args)>::print(t);
    std::cout << ")\n";
}
// end helper function
// -----------------------------------------------------------------------------
int main() {
    auto student0 = get_student(0);
    std::cout << "ID: 0, "
              << "GPA: " << std::get<0>(student0) << ", "
              << "grade: " << std::get<1>(student0) << ", "
              << "name: " << std::get<2>(student0) << '\n';

    double gpa1;
    char grade1;
    std::string name1;

    std::tie(gpa1, grade1, name1) = get_student(1);
    std::cout << "ID: 1, "
              << "GPA: " << gpa1 << ", "
              << "grade: " << grade1 << ", "
              << "name: " << name1 << '\n';

    // C++17 structured binding:
    auto [gpa2, grade2, name2] = get_student(2);
    std::cout << "ID: 2, "
              << "GPA: " << gpa2 << ", "
              << "grade: " << grade2 << ", "
              << "name: " << name2 << '\n';
    // -------------------------------------------------------------------------
    std::tuple<int, std::string, float> t1(10, "Test", 3.14);
    int n = 7;
    auto t2 =
        std::tuple_cat(t1, std::make_tuple("Foo", "bar"), t1, std::tie(n));
    n = 10;
    print(t2);

    std::vector<std::tuple<int, std::string, float>> vTuples;
    vTuples.push_back(t1);
}

#endif // DB_GEN_TEMPLATES_HPP
