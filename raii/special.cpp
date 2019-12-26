#include <iostream>
using namespace std;

// Macro to print and then run a line of source code
#define v(a)                                                                   \
    cout << "\n[" #a "]" << endl;                                              \
    a

// Macro to print a variable
#define p(a) #a "=" << a

//--------------------------------------------------------------------
class T {
  private:
    int x;
    int* a = new int[3];

  public:
    // Default constructor
    T() : x(0), a(nullptr) { cout << "  Null constructor" << endl; }

    // Destructor
    ~T() {
        delete[] a;
        cout << "  Destructor" << endl;
    }

    // Constructor from an int
    explicit T(int x) : x(x) {
        cout << "  Explicit constructor T(" << x << ")" << endl;
    }

    // Copy constructor
    T(const T& rhs) : x(rhs.x), a(rhs.a) {
        cout << "  Copy constructor" << endl;
    }

    // Move constructor
    T(T&& rhs) noexcept : x(rhs.x), a(rhs.a) {
        if (this != &rhs)
            rhs.a = nullptr;
        cout << "  Move constructor" << endl;
    }

    // Copy assignment
    T& operator=(const T& rhs) {
        x = rhs.x;
        a = rhs.a;
        cout << "  Copy assignment" << endl;
        return *this;
    }

    // Move assignment
    T& operator=(T&& rhs) noexcept {
        if (this != &rhs) {
            x = rhs.x;
            delete[] a;
            a = rhs.a;
            rhs.a = nullptr;
        }
        cout << "  Move assignment" << endl;
        return *this;
    }
    ostream& print(ostream& out) const {
        return out << "(" << x << ", " << a << ")";
    }
};

//--------------------------------------------------------------------
// Extend operator<<() to type T objects
inline ostream& operator<<(ostream& out, T& val) { return val.print(out); }

//--------------------------------------------------------------------
int main() {
    v(T a;) cout << "  " << p(a) << endl;
    //  v( T b = 17; )   // error because of explicit keyword
    v(T b(17);) // okay, we're explicitly calling constructor
        cout
        << "  " << p(b) << endl;
    //    v( T c(b); )
    //    cout << "  " << p( c ) << endl;
    v(T d(move(b));) cout << "  " << p(d) << ", " << p(b) << endl;
    v(T e;)
        //    v( e = b; )
        //    cout << "  " << p( e ) << endl;
        v(T f;) v(f = move(d);) cout
        << "  " << p(f) << ", " << p(d) << endl;
    v(T g = T(41);) cout << "  " << p(g) << endl;
    v(T h;) v(h = T(89);) cout << "  " << p(h) << endl;

    v(T j{};) cout << "  " << p(j) << endl;
    v(T k{4};) cout << "  " << p(k) << endl;
    v(T l = {};) cout << "  " << p(k) << endl;

    cout << endl;
    return 0;
}
