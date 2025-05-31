#include "../include/include.h"

int main(int argc, char *argv[])
{

    srand(time(NULL));
    LOG_PRINT("test main......");

#define delist1
#ifdef delist1
            
    D_delist delist = D_init_delist(NULL);
    LOG_PRINT("test delist......");
    C_command command = C_command_init(NULL, argc, argv);

    // C_command_print(command);
    O_OPERATION_NODE operation_node = O_OPERATION_NODE_init(NULL);
    LOG_PRINT("Before call: operation_node = %p\n", (void *)operation_node);

    P_parser(command, operation_node);
    LOG_PRINT("Before call: operation_node = %p\n", (void *)operation_node);

    D_E_exec(delist, operation_node);

#else
    L_skipList sklist = L_skipList_init(NULL);
    L_print_skiplist(sklist);
    LOG_PRINT("test skip list......");
    // for (int i = 1; i < 100; i++)
#endif
    return 0;
}