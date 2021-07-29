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
    std::shared_ptr<Report> ps1(new Report("using shared_ptr"));
    ps1->comment();

    std::unique_ptr<Report> ps2(new Report("using unique_ptr"));
    ps2->comment();

    return 0;
}
} // namespace practice