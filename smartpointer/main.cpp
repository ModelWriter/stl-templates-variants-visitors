

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
            cout << j << endl;
        }

        for (auto itr = vector.rbegin(); itr != vector.rend(); ++itr) {
            cout << (*itr) << endl;
        }

        struct E {
            int a{0};
            int b{0};
        };

        std::vector<E> vt{{1, 2}, {2, 3}, {}};

        for (auto itr = vt.rbegin(); itr != vt.rend(); ++itr) {
            auto& e = *itr;
            cout << e.a << endl;
            cout << e.b << endl;
        };

        cout << "Create smart pointer sp using default constructor" << endl;
        SPtr<double> sp;
        if (sp.empty())
            cout << "  Smart pointer " << sp.id() << " is empty" << endl;

        cout << "\nCreate new double variable xp" << endl;
        auto* xp = new double(12.345);
        cout << "  *xp = " << *xp << endl;

        cout << "\nCreate temporary smart pointer to manage xp\n"
                "  and move assign it to sp"
             << endl;
        sp = SPtr(xp); // move new SPtr to sp
        cout << "  *sp = " << *sp << endl;

        cout << "\nCreate copy of SPtr " << sp.id() << endl;
        SPtr sp2(sp); // make a copy
        cout << "  Copy is SPtr " << sp2.id() << endl;

        cout << "\nAssigning *sp2 = 67.890;" << endl;
        *sp2 = 67.890;
        cout << "  *sp = " << *sp << endl;
        cout << "  *sp2 = " << *sp2 << endl;

        cout << "\nLeaving main program" << endl;
    } catch (SPexception& e) {
        cerr << e.what() << endl;
        throw;
    }
}
