//
// Created by wxm_e on 2021/6/23.
//

#ifndef C_CPP_MY_NON_MEMBER_H
#define C_CPP_MY_NON_MEMBER_H

namespace practice {
class Rational {
  public:
    Rational(int numerator = 0, int denominator = 1);
    int numerator() const;
    int denominator() const;
    void printValue(Rational &lhs);

  private:
    int n;
    int d;
};

Rational operator*(const Rational &lhs, const Rational &rhs);
void printValue(Rational &lhs);

int non_member_test();
} // namespace Practice

#endif // C_CPP_MY_NON_MEMBER_H
