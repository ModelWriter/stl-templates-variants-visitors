//  ----------------------------------------------------------------------------
//  Header file for the HowTo class.                                   HowTo.cpp
//  Created by Ferhat Erata <ferhat.erata@yale.edu> on November 15, 2019.
//  Copyright (c) 2019 Yale University. All rights reserved.
// -----------------------------------------------------------------------------

#include <iostream>
using namespace std;

class Item {
  public:
    Item() { cout << "Item constructor" << endl; }
    ~Item() { cout << "Item destructor" << endl; }
};

class Base {
  public:
    Base() { cout << "Base constructor" << endl; }
    virtual ~Base() { cout << "Base destructor" << endl; }
};

class Deriv : public Base {
  private:
    Item val;

  public:
    Deriv() { cout << "Deriv constructor" << endl; }
    ~Deriv() override { cout << "Deriv destructor" << endl; }
};

int main() {
    cout << "-----" << endl;
    Base* bp = new Deriv;
    cout << "-----" << endl;
    delete bp;
}
