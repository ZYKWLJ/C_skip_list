#include "delist.h"
#include "utils.h"

int main()
{
    srand(time(NULL));
    LOG_PRINT("test main......");
    D_delist delist = D_init_list(NULL);

    D_insert(delist, "xidian");
    D_insert(delist, "university");
    D_insert(delist, "Ethan");
    D_search(delist, "yankang");
    LOG_PRINT("1 passed!");
    D_print_list(delist);
    D_insert(delist, "xidian");
    D_search(delist, "xidian");
    LOG_PRINT("2 passed!");
    D_print_list(delist);
    {
        for (int i = 1; i < 10; i++)
        {
            char dest[100];
            sprintf(dest, "value-%d", i);
            // LOG_PRINT("%s",dest);
            D_insert(delist, strdup(dest)); // 注意这里需要使用单独开辟的字符地址,因为传入的是地址，防止指向相同
        }
    }
    D_print_list(delist);
    LOG_PRINT("3 passed!\n\n\n");

    /*test delete*/
    {
        D_delist delist1 = D_init_list(NULL);
        D_insert(delist1, "xidian");
        D_insert(delist1, "university");
        D_insert(delist1, "Ethan");
        D_insert(delist1, "xidian");
        D_print_list(delist1);
        D_delete(delist1, "xidian");
        D_print_list(delist1);
    }
    return 0;
}