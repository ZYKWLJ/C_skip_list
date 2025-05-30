#include "delist.h"
#include "utils.h"

int main()
{
    LOG_PRINT("test main......");
    D_delist delist = D_init_list(NULL);
    D_print_list(delist);
    D_insert(delist, 1);
    D_insert(delist, 3);
    D_insert(delist, 5);
    D_search(delist, 5);
    D_print_list(delist);
    D_insert(delist, 5);
    D_search(delist, 5);
    D_print_list(delist);
    {
        for(int i=1;i<1000;i++){
            D_insert(delist,i);
        }
    }
    D_print_list(delist);
    return 0;
}