//
// Created by wxm_e on 2021/8/25.
//

#include "my_smart_ptr.h"

void outOfMem()
{
    std::cerr << "lack of memory" << std::endl;
    std::abort();
}

int main(int argc, char **argv)
{
    std::set_new_handler(outOfMem);
    practice::smart_ptr();
    int *pBigDataArray = new int[100000000000000000L];
    return 0;
}
