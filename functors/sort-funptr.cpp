#include <algorithm>
#include <iostream>
#include <vector>

//--------------------------------------------------------------------
bool descendingOrder(int i, int j) { return (i > j); }
bool ascendingOrder(int i, int j) { return (i < j); }

// -----------------------------------------------------------------------------
void print(std::vector<int>& vec) {
    std::cout << "myvector contains:";
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';
}

// -----------------------------------------------------------------------------
int main() {

    // Test vector
    int myints[] = {32, 71, 12, 45, 26, 80, 53, 33};
    std::vector<int> myvector(myints, myints + 8); // 32 71 12 45 26 80 53 33

    // Define expected type for a sort comparator
    using Comp = bool (*)(int, int);

    // Define a pointer to a comparator
    Comp cptr;

    // Set pointer and sort descending
    cptr = descendingOrder;
    std::sort(myvector.begin(), myvector.end(), cptr);
    print(myvector);

    // Set pointer and sort ascending
    cptr = ascendingOrder;
    std::sort(myvector.begin(), myvector.end(), cptr);
    print(myvector);
}
