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
            D_insert(delist, strdup(dest));//注意这里需要使用单独开辟的字符地址,因为传入的是地址，防止指向相同
        }
    }
    LOG_PRINT("3 passed!");

    D_print_list(delist);
    return 0;
}