//
// Created by wxm_e on 2021/9/2.
//

#include "6_33_avoid_hiding_inherited_names.h"
#include <iostream>

using namespace std;

namespace avoid_hiding_inherited_names {
void Base::mf1()
{
    cout << "base mf1()" << endl;
}

void Base::mf1(int i)
{
    cout << "base mf1(int)" << i << endl;
}

void Base::mf2()
{
    cout << "base mf2()" << endl;
}

void Base::mf3()
{
    cout << "base mf3()" << endl;
}

void Base::mf3(double i)
{
    cout << "base mf3(double)" << i << endl;
}

void Derived::mf1()
{
    cout << "Derived mf1()" << endl;
}

void Derived::mf3()
{
    cout << "Derived mf3()" << endl;
}

void Derived::mf4()
{
    cout << "Derived mf4()" << endl;
}

void test()
{
    Derived d;
    int x    = 9;
    double y = 0.1;

    d.mf1();  // Derived mf1()
    d.mf1(x); // 调用Base::mf1(int),因为使用了using使得Base的成员函数在Derived中可见
    d.mf2();  // base mf2()
    d.mf3();  // Derived mf3()
    // d.mf3(y); // 编译错误，因为Derived::mf3遮掩了Base::mf3
    d.mf4(); // Derived mf4()
}
}; // namespace avoid_hiding_inherited_names
