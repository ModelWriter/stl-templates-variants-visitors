#include <iostream>
#include <memory>
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
    T() : x(0), a(nullptr) { cout << "  T::Null constructor" << endl; }

    // Destructor
    virtual ~T() {
        delete[] a;
        cout << "  T::Destructor" << endl;
    }

    // Constructor from an int
    explicit T(int x) : x(x) {
        cout << "  T::Explicit constructor T(" << x << ")" << endl;
    }

    // Copy constructor
    T(const T& rhs) : x(rhs.x), a(rhs.a) {
        cout << "  T::Copy constructor" << endl;
    }

    // Move constructor
    T(T&& rhs) noexcept : x(rhs.x), a(rhs.a) {
        if (this != &rhs)
            rhs.a = nullptr;
        cout << "  T::Move constructor" << endl;
    }

    // Copy assignment
    T& operator=(const T& rhs) {
        x = rhs.x;
        a = rhs.a;
        cout << "  T::Copy assignment" << endl;
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
        cout << "  T::Move assignment" << endl;
        return *this;
    }
    ostream& print(ostream& out) const {
        return out << "T(" << x << ", " << a << ")";
    }

    virtual void bar() { std::cout << "T::bar()\n"; }
};

//--------------------------------------------------------------------
// Extend operator<<() to type T objects
inline ostream& operator<<(ostream& out, T& val) { return val.print(out); }

// T Factory
T makeT() {
    T t(22);
    return t;
}

// T Factory from const T
T makeT(const T& t) {
    T temp(t);
    return temp;
}

class R : public T {
    R() { std::cout << "D::D\n"; }
    ~R() override { std::cout << "D::~D\n"; }
    void bar() override { std::cout << "R::bar()\n"; }
};

//--------------------------------------------------------------------
int main(void) {
    v(T a;) cout << "  " << p(a) << endl;
    //  v( T b = 17; )   // error because of explicit keyword
    v(T b(17);) // okay, we're explicitly calling constructor
        cout
        << "  " << p(b) << endl;
    //
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

    v(T m = makeT();) cout << "  " << p(m) << endl;
    //    v(T n = makeT(k);) cout << "  " << p(n) << endl;
    v(auto up1 = std::make_unique<T>();) cout << "  " << p(*up1) << endl;
    v(auto up2 = std::make_unique<T>(1);) cout << "  " << p(*up2) << endl;
    v(std::unique_ptr<T> up3(new T);) cout << "  " << p(*up3) << endl;
    v(std::unique_ptr<T> up5 = std::make_unique<T>(std::move(*up3));) cout
        << "  " << p(*up5) << endl;

    cout << endl;
    return 0;
}
