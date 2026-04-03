#include <stdio.h>

int switch_case_test()
{
    int outer = 1;
    int inner = 10;

    switch (outer) {
    case 1:
        printf("進入外層 case 1\n");

        switch (inner) {
        case 10:
            printf("  進入內層 case 10\n");
            break; // 【重點】只跳出內層 switch
        case 20:
            printf("  進入內層 case 20\n");
            break;
        }

        printf("回到外層 case 1 (內層 break 後的代碼)\n");
        break; // 跳出外層 switch

    case 2:
        printf("進入外層 case 2\n");
        break;
    }

    return 0;
}
