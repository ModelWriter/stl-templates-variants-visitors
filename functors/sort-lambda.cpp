#include <algorithm>
#include <iostream>
#include <vector>

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
    std::vector<int> myvector(myints, myints + 8);
    // 32 71 12 45 26 80 53 33

    // Sort descending using lambda expression comparator
    std::sort(myvector.begin(), myvector.end(),
              [](int i, int j) { return (i > j); });
    print(myvector);

    // Sort ascending using lambda expression comparator
    std::sort(myvector.begin(), myvector.end(),
              [](int i, int j) { return (i < j); });
    print(myvector);
}
