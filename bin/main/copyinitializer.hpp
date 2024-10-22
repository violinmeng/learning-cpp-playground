#pragma once

#include <iostream>
#include <typeinfo>

namespace CopyInitializer
{

struct A
{
    int n;
    A(int n = 1) : n(n) { std::cout << "A is init with " << n << "\n"; }
    A(const A& a) : n(a.n) { std::cout << typeid(*this).name() << " is copied." << "\n"; } // user-defined copy constructor
};

struct B : A
{
    // implicit default constructor B::B()
    // implicit copy constructor B::B(const B&)
};

struct C : B
{
    C() : B() { std::cout << "C is initialized" << "\n"; }
    C(const C&) = delete; // C++11 style
private:
    // C(const C&); // non-copyable, C++98 style
};

void testCopyConstructor()
{
    // the initializer can not mark as virtual.
    A a1(7);
    // A is init with 7
    A a2(a1); // calls the copy constructor
    // N15CopyInitializer1AE is copied.

    B b; // the default constructor's function body of derived class is the same as its base's.
    //A is init with 1
    B b2 = b;
    //N15CopyInitializer1AE is copied.
    A a3 = b; // conversion to A& and copy constructor
    //N15CopyInitializer1AE is copied.

    volatile A va(10);
    // A is init with 10

    // A a4 = va; // compile error, volatile keyword does not match with copy constructor.

    C c;
    // A is init with 1
    // C is initialized

    // C c2 = c; // compile error
}
} // namespace CopyInitializer