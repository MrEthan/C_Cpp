//
// Created by wxm_e on 2021/9/2.
//

#ifndef C_CPP_6_33_AVOID_HIDING_INHERITED_NAMES_H
#define C_CPP_6_33_AVOID_HIDING_INHERITED_NAMES_H

namespace avoid_hiding_inherited_names
{
    class Base {
      public:
        virtual void mf1() = 0;
        virtual void mf1(int);
        virtual void mf2();
        void mf3();
        void mf3(double );

      private:
        int x;
    };

class Derived:public Base{
  public:
    using Base::mf1;
    virtual void mf1();
    void mf3(); // 遮掩了Base中的mf3()和mf3(double)
    void mf4();
};

void test();

}; // namespace 6_33_inherited_names

#endif // C_CPP_6_33_AVOID_HIDING_INHERITED_NAMES_H
