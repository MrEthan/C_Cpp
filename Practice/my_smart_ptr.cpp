//
// Created by wxm_e on 2021/6/4.
//
#include "my_smart_ptr.h"
#include <memory>
#include <string>
using namespace std;
namespace practice {
int smart_ptr()
{
    std::shared_ptr<Report> ps(new Report("using shared_ptr"));
    ps->comment();

    std::unique_ptr<Report> ps(new Report("using unique_ptr"));
    ps->comment();

    return 0;
}
} // namespace practice