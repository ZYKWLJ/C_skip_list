#include "../../include/include.h"
// #include "operation.h"
// #include "operation.h"
// #include "operation.h"
/*
主页(hd):
显示各种功能

帮助手册(?):
hd ?
hd ? \
hd ? /
hd ? +
hd ? -

查找(\):
hd \ xidian
hd \ -v xidian
hd \ -k xidian

插入(+):
hd + xidian 211
hd + -v  xidian
hd + -k  xidian 211

删除(-):
hd - xidian
hd - -v xidian
hd - -k xidian

修改(/):
hd / xidian 211
hd / -k xidian 211
//修改就没必要说修改某个值，修改键值对才有意义
*/
S_Status parser(C_command command)
{
    if (command->argc == 1)
    {
        printf("MUNE\n\n");
        exit(EXIT_SUCCESS);
    }
    /**
     * data descp: 命令 hd ?
     */
    else if (command->argc == 2 && (strcmp(command->argv[1], "?") == 0))
    {
        printf("HELP REFERENCE\n\n");
        printf("The use of the four manuals is shown, and here are only four commands and commands for further help viewing\n");
        exit(EXIT_SUCCESS);
    }
    /**
     * data descp: 三级命令
     */
    else if (command->argc == 3)
    {
        if (strcmp(command->argv[1], "?"))
        {
            if (strcmp(command->argv[2], "\\"))
            {
                TODO_PRINT("help find operation...");
                exit(EXIT_SUCCESS);
            }
            else if (strcmp(command->argv[2], "/"))
            {
                TODO_PRINT("help modifiy operation...");
                exit(EXIT_SUCCESS);
            }
            else if (strcmp(command->argv[2], "+"))
            {
                TODO_PRINT("help add operation...");
                exit(EXIT_SUCCESS);
            }
            else if (strcmp(command->argv[2], "-"))
            {
                TODO_PRINT("help delete operation...");
                exit(EXIT_SUCCESS);
            }
        }
        /**
         * data descp: 查找k ，hd \ xidian
         */
        else if (strcmp(command->argv[1], "\\"))
        {
            TODO_PRINT("find k-v operation...");
            exit(EXIT_SUCCESS);
        }
        /**
         * data descp: 删除k，hd - xidian
         */
        else if (strcmp(command->argv[1], "-"))
        {
            TODO_PRINT("delete k-v operation...");
            exit(EXIT_SUCCESS);
        }
    }
    /**
     * data descp: 四级命令
     */
    else if (command->argc == 4)
    {
        TODO_PRINT("4 level operation...");
        exit(EXIT_SUCCESS);
    }
    /**
     * data descp: 五级命令
     */
    else if (command->argc == 5)
    {
        TODO_PRINT("5 level operation...");
        exit(EXIT_SUCCESS);
    }
    else
    {

        COMMAND_ERROR(command, "--Error input, enter \"hd ?\" to get help\n");
        exit(EXIT_FAILURE);
    }
}
S_Status get_operation_node(C_command command, O_OPERATION_NODE operation_node)
{
    parser(command);
}

O_OPERATION_NODE O_OPERATION_NODE_init(O_OPERATION_NODE o_operation_node)
{
    O_OPERATION_NODE ret = (O_OPERATION_NODE)checked_malloc(sizeof(*o_operation_node));
    return ret;
}
