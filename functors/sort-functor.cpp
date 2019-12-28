#include <algorithm>
#include <iostream>
#include <vector>

// -----------------------------------------------------------------------------
bool descendingOrder(int i, int j) { return (j < i); }
bool ascendingOrder(int i, int j) { return (i < j); }

// -----------------------------------------------------------------------------
void print(std::vector<int>& vec) {
    std::cout << "myvector contains:";
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';
}

// -----------------------------------------------------------------------------
class descending {
  public:
    bool operator()(int i, int j) { return (i > j); }
};

// -----------------------------------------------------------------------------
class ascending {
  public:
    bool operator()(int i, int j) { return (i < j); }
};

// -----------------------------------------------------------------------------
int main() {

    int myints[] = {32, 71, 12, 45, 26, 80, 53, 33};
    std::vector<int> myvector(myints, myints + 8);
    // 32 71 12 45 26 80 53 33

    sort(myvector.begin(), myvector.end(), descending());
    print(myvector);

    sort(myvector.begin(), myvector.end(), ascending());
    print(myvector);
}
