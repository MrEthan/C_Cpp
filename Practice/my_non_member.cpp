//
// Created by wxm_e on 2021/6/23.
//

#include "my_non_member.h"
#include <iostream>
namespace practice {

Rational::Rational(int numerator, int denominator)
{
    n = numerator;
    d = denominator;
}

int Rational::numerator() const
{
    return n;
};

int Rational::denominator() const
{
    return d;
}

Rational operator*(const Rational &lhs, const Rational &rhs)
{
    return Rational(lhs.numerator() * rhs.numerator(), lhs.denominator() * rhs.denominator());
}

void printValue(Rational &lhs)
{
    std::cout << lhs.numerator() << '/' << lhs.denominator() << std::endl;
}

int non_member_test()
{
    Rational oneEighth(1, 8);
    Rational oneHalf(1, 2);
    Rational res = oneHalf * oneEighth;
    printValue(res);
    return 0;
}
} // namespace practice
