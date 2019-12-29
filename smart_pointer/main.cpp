

#include "SPtr.hpp"
#include <iostream>
#include <vector>

//-------------------------------------------------------
int main() {
    try {
        std::vector<int> vector{1, 2, 3, 4, 5};

        for (auto& i : vector) {
            std::cout << i << std::endl;
        }

        for (int j : vector) {
            std::cout << j << std::endl;
        }

        for (auto itr = vector.rbegin(); itr != vector.rend(); ++itr) {
            std::cout << (*itr) << std::endl;
        }

        struct E {
            int a{0};
            int b{0};
        };

        std::vector<E> vt{{1, 2}, {2, 3}, {}};

        for (auto itr = vt.rbegin(); itr != vt.rend(); ++itr) {
            auto& e = *itr;
            std::cout << e.a << std::endl;
            std::cout << e.b << std::endl;
        };

        std::cout << "Create smart pointer sp using default constructor" << std::endl;
        SPtr<double> sp;
        if (sp.empty())
            std::cout << "  Smart pointer " << sp.id() << " is empty" << std::endl;

        std::cout << "\nCreate new double variable xp" << std::endl;
        auto* xp = new double(12.345);
        std::cout << "  *xp = " << *xp << std::endl;

        std::cout << "\nCreate temporary smart pointer to manage xp\n"
                "  and move assign it to sp"
             << std::endl;
        sp = SPtr(xp); // move new SPtr to sp
        std::cout << "  *sp = " << *sp << std::endl;

        std::cout << "\nCreate copy of SPtr " << sp.id() << std::endl;
        SPtr sp2(sp); // make a copy
        std::cout << "  Copy is SPtr " << sp2.id() << std::endl;

        std::cout << "\nAssigning *sp2 = 67.890;" << std::endl;
        *sp2 = 67.890;
        std::cout << "  *sp = " << *sp << std::endl;
        std::cout << "  *sp2 = " << *sp2 << std::endl;

        std::cout << "\nLeaving main program" << std::endl;
    } catch (SPexception& e) {
        std::cerr << e.what() << std::endl;
        throw;
    }
}
