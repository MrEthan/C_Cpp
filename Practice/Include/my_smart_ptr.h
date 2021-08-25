//
// Created by wxm_e on 2021/6/4.
//

#ifndef C_CPP_MY_SMART_PTR_H
#define C_CPP_MY_SMART_PTR_H
#include <iostream>

namespace practice {

class Report {
  public:
    Report(const std::string s) : str(s)
    {
        std::cout << "Object created" << std::endl;
    }
    ~Report()
    {
        std::cout << "Object deleted" << std::endl;
    }
    void comment() const
    {
        std::cout << str << std::endl;
    }

  private:
    std::string str;
};

int smart_ptr();

} // namespace practice

#endif // C_CPP_MY_SMART_PTR_H
