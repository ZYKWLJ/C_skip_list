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

void help_find()
{
    printf("HoneyDB provides explicit and implicit data operations. "
           "Explicit operations refer to manipulating data through keys, "
           "while implicit operations refer to manipulating data through values.\n");
    printf("In data lookup operations:\n");
    printf("The format for explicit operations is as follows, where `-k` can be omitted:\n");
    printf("`hd \\ -k key`\n");
    printf("The format for implicit operations is as follows:\n");
    printf("`hd \\ -v value`\n");
}
void help_modify()
{
    printf("HoneyDB provides explicit and implicit data operations. "
           "Explicit operations manipulate data via keys, "
           "while implicit operations manipulate data via values. "
           "Since implicit operations are not meaningful here, "
           "only explicit operations are provided for data modification.\n");
    printf("In data modification operations:\n");
    printf("The format for explicit operations is as follows, where `-k` can be omitted:\n");
    printf("hd / -k key value\n");
}

void help_delete()
{
    printf("HoneyDB provides explicit and implicit data operations. "
           "Explicit operations manipulate data via keys, "
           "while implicit operations manipulate data via values.\n");
    printf("In data deletion operations:\n");
    printf("The format for explicit operations is as follows, where `-k` can be omitted:\n");
    printf("hd - -k key\n");
    printf("The format for implicit operations is as follows:\n");
    printf("hd - -v value\n");
}
void help_add()
{

    printf("HoneyDB provides explicit and implicit data operations. "
           "Explicit operations manipulate data via keys, "
           "while implicit operations manipulate data via values.\n");
    printf("In data insertion operations:\n");
    printf("The format for explicit operations is as follows, where `-k` can be omitted:\n");
    printf("hd + -k key\n");
    printf("The format for implicit operations is as follows:\n");
    printf("hd + -v value\n");
}
void param_optional()
{
    printf("  []:must\n");
    printf("  ():optional\n");
    printf("  | :or\n");
}
void print_help_curd()
{

    char *name[] = {"Operations", "Add data:", "Delete data:", "Query data:", "Modify data:", NULL};
    char *instructions[] = {"Commands", "hd + [(-k)|-v] [key value|value]", "hd - [(-k)|-v] [key|value]", "hd \\ [(-k)|-v] [key|value]", "hd / [(-k)] [key value]", NULL};
    char **columns[] = {name, instructions};
    // text_print_head0_blank0(columns, sizeof(columns) / sizeof(columns[0]));
    text_print_head1_blank0(columns, sizeof(columns) / sizeof(columns[0]));
    // print_help_curd();
    // printf("Help manual: \nhd ?\n");
    // printf("\n");
    param_optional();
}

#define AUTHOR "Author: EthanYankang"
#define WECHAT "Wechat: 2126483838"
#define GITHUB "Github: https://github.com/ZYKWLJ/C_skip_list"
#define LINK "HelpRefence: https://blog.csdn.net/m0_68657832/article/details/147869804"
/*
  ____
 /    \
/      \
\      /
 \____/
 /    \
/      \
\      /
 \____/

*/
/*
  ___
 /   \
 \___/
 /   \
 \___/
 /   \
 \___/
*/
void author()
{
    printf("\n");
    printf("%s\n", AUTHOR);
    printf("%s\n", WECHAT);
    printf("%s\n", GITHUB);
    printf("%s\n", LINK);
}

void logo()
{
#if 0
    {
        // 硬编码方式打印蜂窝图案
        printf("  ___  ___  ___ \n");
        printf(" /   \\/   \\/   \\\n");
        printf(" \\___/\\___/\\___/ \n");
        // printf("  ___   ___   ___ \n");
        printf(" /   \\/   \\/   \\ \n");
        printf(" \\___/\\___/\\___/ \n");
        // printf("  ___   ___   ___  \n");
        printf(" /   \\/   \\/   \\ \n");
        printf(" \\___/\\___/\\___/  \n");
    }
#endif

    {
        // 硬编码方式打印蜂窝图案
        printf("  _____  _____  _____  \n");
        printf(" /     \\/     \\/     \\ \n");
        printf(" \\_____/\\_____/\\_____/  \n");
        // printf("  _____   _____   _____   \n");
        printf(" /     \\/     \\/     \\  \n");
        printf(" \\_____/\\_____/\\_____/ \n");
        // printf("  _____   _____   _____   \n");
        printf(" /     \\/     \\/     \\  \n");
        printf(" \\_____/\\_____/\\_____/  \n");
    }

    {
        // // 硬编码方式打印蜂窝图案
        // printf("  __________     __________     __________  \n");
        // printf(" /          \\  /          \\  /          \\ \n");
        // printf("/            \\/            \\/            \\ \n");
        // printf("\\            /             /             /\n");
        // printf(" \\__________/  __________/  __________/\n");
        // printf(" /          \\  /          \\  /          \\ \n");
        // printf("/            \\/            \\/            \\ \n");
        // printf("\\            /             /             /\n");
        // printf(" \\___________/  __________/  __________/\n");
        // printf("  __________   __________   __________   \n");
        //  printf("/            \\/            \\/            \\ \n");
        // printf("\\            /             /             /\n");
        // printf(" \\___________/  __________/  __________/\n");
        // 硬编码方式打印蜂窝图案
    printf("    __________    __________    __________    \n");
    printf("   /          \\  /          \\  /          \\   \n");
    printf("  /            \\/            \\/            \\  \n");
    printf("  \\            /\\            /\\            /  \n");
    printf("   \\__________/  \\__________/  \\__________/   \n");
    // printf("    __________    __________    __________    \n");
    printf("   /          \\  /          \\  /          \\   \n");
    printf("  /            \\/            \\/            \\  \n");
    printf("  \\            /\\            /\\            /  \n");
    printf("   \\__________/  \\__________/  \\__________/   \n");
    // printf("    __________    __________    __________    \n");
    printf("   /          \\  /          \\  /          \\   \n");
    printf("  /            \\/            \\/            \\  \n");
    printf("  \\            /\\            /\\            /  \n");
    printf("   \\__________/  \\__________/  \\__________/   \n");

    }
}

// void honeydb()
// {
//     {
//         printf("  _    _                        _____  ____  \n");
//         printf(" | |  | |                      |  __ \\|  _ \\ \n");
//         printf(" | |__| | ___  _ __   ___ _   _| |  | | |_) |\n");
//         printf(" |  __  |/ _ \\| '_ \\ / _ \\ | | | |  | |  _ < \n");
//         printf(" | |  | | (_) | | | |  __/ |_| | |__| | |_) |\n");
//         printf(" |_|  |_|\\___/|_| |_|\\___|\\__, |_____/|____/ \n");
//         printf("                           __/ |             \n");
//         printf("                          |___/              \n");
//     }
// }
void honeydb()
{
    {
        printf("                                               _    _                        _____  ____  \n");
        printf("                                              | |  | |                      |  __ \\|  _ \\ \n");
        printf("                                              | |__| | ___  _ __   ___ _   _| |  | | |_) |\n");
        printf("                                              |  __  |/ _ \\| '_ \\ / _ \\ | | | |  | |  _ < \n");
        printf("                                              | |  | | (_) | | | |  __/ |_| | |__| | |_) |\n");
        printf("                                              |_|  |_|\\___/|_| |_|\\___|\\__, |_____/|____/ \n");
        printf("                                                                        __/ |             \n");
        printf("                                                                       |___/              \n");
    }
}
void menu()
{
    logo();
    printf("");
    // printf("%40s\n", "HoneyDB");
    honeydb();
    // printf("MUNE\n\n");
    // honeydb是一个轻量级键值数据库，使用跳表作为默认内核，可以实现log2(n)的时间复杂度查询。
    // 内置如下命令，如下：
    // 帮助手册：hd ?
    printf("HoneyDB is a lightweight key-value database that uses a skip list as its default kernel, enabling query time complexity of log(n).\n");
    printf("The built-in commands are as follows:\n");
    char *name[] = {"Operations", "Add data:", "Delete data:", "Query data:", "Modify data:", "Help manual:", NULL};
    char *instructions[] = {"Commands", "hd + [(-k)|-v] [key value|value]", "hd - [(-k)|-v] [key|value]", "hd \\ [(-k)|-v] [key|value]", "hd / [(-k)] [key value]", "hd ?", NULL};
    char **columns[] = {name, instructions};
    // text_print_head0_blank0(columns, sizeof(columns) / sizeof(columns[0]));
    text_print_head1_blank0(columns, sizeof(columns) / sizeof(columns[0]));
    // print_help_curd();
    // printf("Help manual: \nhd ?\n");

    //  printf("\n");
    param_optional();
    author();
}

void argc1()
{
    menu();
    // return OK;
    exit(EXIT_SUCCESS);
}
void argc2()
{
    printf("HELP REFERENCE\n");
    // printf("The use of the four manuals is shown, and here are only four commands and commands for further help viewing\n");
    // honeydb指令如下：
    // hd + [(-k)|-v] [key value|value] 添加数据
    // hd - [(-k)|-v] [key|value] 删除数据
    // hd \ [(-k)|-v] [key|value] 查找数据
    // hd / [(-k)] [key value] 修改数据
    printf("HoneyDB data operation commands are as follows:\n");
    print_help_curd();
    // return OK;
    exit(EXIT_SUCCESS);
}
void argc3(C_command command, O_OPERATION_NODE operation_node)
{
    if (strcmp(command->argv[1], "?") == 0)
    {
        LOG_PRINT("parser....?");

        if (strcmp(command->argv[2], "\\") == 0)
        {
            TODO_PRINT("help find operation...");
            // honeydb提供显隐数据操作,显式操作即通过key来操作数据，隐式操作即通过value来操作数据。
            // 在查找数据操作中：
            // 显式操作格式如下，其中-k可以省略：
            // hd \ -k key
            // 隐式操作格式如下：
            // hd \ -v value
            help_find();
            // return OK;
            exit(EXIT_SUCCESS);
        }
        else if (strcmp(command->argv[2], "/") == 0)
        {
            TODO_PRINT("help modifiy operation...");
            // honeydb提供显隐数据操作,显式操作即通过key来操作数据，隐式操作即通过value来操作数据。因为隐式操作在此没有意义，修改数据仅仅提供显式操作。
            // 在修改数据操作中：
            // 显式操作格式如下，其中-k可以省略：
            // hd / -k key value
            help_modify();
            // return OK;
            exit(EXIT_SUCCESS);
        }
        else if (strcmp(command->argv[2], "+") == 0)
        {
            // honeydb提供显隐数据操作,显式操作即通过key来操作数据，隐式操作即通过value来操作数据。
            // 在插入数据操作中：
            // 显式操作格式如下，其中-k可以省略：
            // hd + -k key
            // 隐式操作格式如下：
            // hd + -v value
            TODO_PRINT("help add operation...");
            help_add();
            // return OK;
            exit(EXIT_SUCCESS);
        }
        else if (strcmp(command->argv[2], "-") == 0)
        {
            // honeydb提供显隐数据操作,显式操作即通过key来操作数据，隐式操作即通过value来操作数据。
            // 在删除数据操作中：
            // 显式操作格式如下，其中-k可以省略：
            // hd - -k key
            // 隐式操作格式如下：
            // hd - -v value

            TODO_PRINT("help delete operation...");
            help_delete();
            // return OK;
            exit(EXIT_SUCCESS);
        }
        else
        {
            COMMAND_ERROR(command, "--Error input, enter \"hd ?\" to get help\n");
            exit(EXIT_FAILURE);
        }
    }
    /**
     * data descp: 查找k ，hd \ xidian
     */
    else if (strcmp(command->argv[1], "\\") == 0)
    {
        TODO_PRINT("find k-v operation...");
        LOG_PRINT("Just set type to: %d\n", operation_node->operation_node_type);
        LOG_PRINT("passed1");
        operation_node->operation_node_type = K;
        operation_node->operation_node_data = (union node_data *)checked_malloc(sizeof(union node_data));
        operation_node->operation_node_data->operation_type_key = (OPERATION_TYPE_KEY)checked_malloc(sizeof(struct operation_type_key));
        LOG_PRINT("passed2");
        sprintf(operation_node->operation_node_data->operation_type_key->operation_key_data.find_key_data.key, "%s", command->argv[2]);
        LOG_PRINT("find key:%s", operation_node->operation_node_data->operation_type_key->operation_key_data.find_key_data.key);

        operation_node->operation_node_data->operation_type_key->operation_key = FIND_KEY;
        LOG_PRINT("Just set type to: %d\n", operation_node->operation_node_data->operation_type_key->operation_key);
        return OK;
    }
    /**
     * data descp: 删除k，hd - xidian
     */
    else if (strcmp(command->argv[1], "-") == 0)
    {
        TODO_PRINT("delete k-v operation...");
        LOG_PRINT("passed1");
        operation_node->operation_node_data = (union node_data *)checked_malloc(sizeof(union node_data));
        operation_node->operation_node_data->operation_type_key = (OPERATION_TYPE_KEY)checked_malloc(sizeof(struct operation_type_key));
        operation_node->operation_node_data->operation_type_key->operation_key = DELETE_KEY;
        LOG_PRINT("passed2");

        sprintf(operation_node->operation_node_data->operation_type_key->operation_key_data.find_key_data.key, "%s", command->argv[2]);
        LOG_PRINT("delete key:%s", operation_node->operation_node_data->operation_type_key->operation_key_data.delete_key_data.key);
        operation_node->operation_node_type = K;
        return OK;
    }
    else if (strcmp(command->argv[1], "+") == 0)
    {
        TODO_PRINT("hd \\ -v value");
        operation_node->operation_node_type = V;
        LOG_PRINT("passed1");
        operation_node->operation_node_data = (union node_data *)checked_malloc(sizeof(union node_data));
        operation_node->operation_node_data->operation_type_value = (OPERATION_TYPE_VALUE)checked_malloc(sizeof(struct operation_type_value));
        operation_node->operation_node_data->operation_type_value->operation_value = INSERT_KEY;
        LOG_PRINT("passed2");
        sprintf(operation_node->operation_node_data->operation_type_value->operation_value_data.insert_value_data.value, "%s", command->argv[2]);
        LOG_PRINT("insert value:%s", operation_node->operation_node_data->operation_type_value->operation_value_data.insert_value_data.value);
        return OK;
    }
    else
    {
        COMMAND_ERROR(command, "--Error input, enter \"hd ?\" to get help\n");
        exit(EXIT_FAILURE);
    }
}

void argc4(C_command command, O_OPERATION_NODE operation_node)
{
    TODO_PRINT("4 level operation...");

    if (strcmp(command->argv[1], "\\") == 0)
    {
        if (strcmp(command->argv[2], "-v") == 0)
        {
            TODO_PRINT("hd \\ -v value");
            TODO_PRINT("find k-v operation...");
            operation_node->operation_node_type = V;
            LOG_PRINT("passed1");
            operation_node->operation_node_data = (union node_data *)checked_malloc(sizeof(union node_data));
            operation_node->operation_node_data->operation_type_value = (OPERATION_TYPE_VALUE)checked_malloc(sizeof(struct operation_type_value));
            operation_node->operation_node_data->operation_type_value->operation_value = FIND_KEY;
            LOG_PRINT("passed2");

            sprintf(operation_node->operation_node_data->operation_type_value->operation_value_data.find_value_data.value, "%s", command->argv[2]);
            LOG_PRINT("delete value:%s", operation_node->operation_node_data->operation_type_value->operation_value_data.find_value_data.value);
            return OK;
        }
        else if (strcmp(command->argv[2], "-k") == 0)
        {
            TODO_PRINT("hd \\ -k value");
            TODO_PRINT("find k-v operation...");
            operation_node->operation_node_type = K;
            LOG_PRINT("passed1");
            operation_node->operation_node_data = (union node_data *)checked_malloc(sizeof(union node_data));
            operation_node->operation_node_data->operation_type_key = (OPERATION_TYPE_KEY)checked_malloc(sizeof(struct operation_type_key));
            operation_node->operation_node_data->operation_type_key->operation_key = FIND_VALUE;
            LOG_PRINT("passed2");

            sprintf(operation_node->operation_node_data->operation_type_key->operation_key_data.find_key_data.key, "%s", command->argv[2]);
            LOG_PRINT("delete key:%s", operation_node->operation_node_data->operation_type_key->operation_key_data.delete_key_data.key);
            return OK;
        }
    }
    else if (strcmp(command->argv[1], "+") == 0)
    {
        if (strcmp(command->argv[2], "-v") == 0)
        {
            TODO_PRINT("hd \\ -v value");
            TODO_PRINT("find k-v operation...");
            operation_node->operation_node_type = V;
            LOG_PRINT("passed1");
            operation_node->operation_node_data = (union node_data *)checked_malloc(sizeof(union node_data));
            operation_node->operation_node_data->operation_type_value = (OPERATION_TYPE_VALUE)checked_malloc(sizeof(struct operation_type_value));
            operation_node->operation_node_data->operation_type_value->operation_value = INSERT_KEY;
            LOG_PRINT("passed2");
            sprintf(operation_node->operation_node_data->operation_type_value->operation_value_data.insert_value_data.value, "%s", command->argv[3]);
            LOG_PRINT("delete value:%s", operation_node->operation_node_data->operation_type_value->operation_value_data.insert_value_data.value);
            return OK;
        }
        else
        {
            TODO_PRINT("hd + key value");
            TODO_PRINT("add k-v operation...");
            operation_node->operation_node_type = K;
            LOG_PRINT("passed1");
            operation_node->operation_node_data = (union node_data *)checked_malloc(sizeof(union node_data));
            operation_node->operation_node_data->operation_type_key = (OPERATION_TYPE_KEY)checked_malloc(sizeof(struct operation_type_key));
            operation_node->operation_node_data->operation_type_key->operation_key = INSERT_KEY;
            LOG_PRINT("passed2");
            sprintf(operation_node->operation_node_data->operation_type_key->operation_key_data.insert_key_data.key, "%s", command->argv[2]);
            sprintf(operation_node->operation_node_data->operation_type_key->operation_key_data.insert_key_data.value, "%s", command->argv[3]);
            LOG_PRINT("insert date key:%s", operation_node->operation_node_data->operation_type_key->operation_key_data.insert_key_data.key);
            LOG_PRINT("delete data value:%s", operation_node->operation_node_data->operation_type_key->operation_key_data.insert_key_data.value);
            return OK;
        }
    }
    else if (strcmp(command->argv[1], "-") == 0)
    {
        if (strcmp(command->argv[2], "-v") == 0)
        {
            TODO_PRINT("hd \\ -v value");
            TODO_PRINT("find k-v operation...");
            operation_node->operation_node_type = V;
            LOG_PRINT("passed1");
            operation_node->operation_node_data = (union node_data *)checked_malloc(sizeof(union node_data));
            operation_node->operation_node_data->operation_type_value = (OPERATION_TYPE_VALUE)checked_malloc(sizeof(struct operation_type_value));
            operation_node->operation_node_data->operation_type_value->operation_value = DELETE_KEY;
            LOG_PRINT("passed2");
            sprintf(operation_node->operation_node_data->operation_type_value->operation_value_data.delete_value_data.value, "%s", command->argv[3]);
            LOG_PRINT("delete value:%s", operation_node->operation_node_data->operation_type_value->operation_value_data.delete_value_data.value);
            return OK;
        }
        else if (strcmp(command->argv[2], "-k") == 0)
        {
            TODO_PRINT("hd + key value");
            TODO_PRINT("add k-v operation...");
            operation_node->operation_node_type = K;
            LOG_PRINT("passed1");
            operation_node->operation_node_data = (union node_data *)checked_malloc(sizeof(union node_data));
            operation_node->operation_node_data->operation_type_key = (OPERATION_TYPE_KEY)checked_malloc(sizeof(struct operation_type_key));
            operation_node->operation_node_data->operation_type_key->operation_key = DELETE_KEY;
            LOG_PRINT("passed2");
            sprintf(operation_node->operation_node_data->operation_type_key->operation_key_data.delete_key_data.key, "%s", command->argv[2]);
            LOG_PRINT("delete date key:%s", operation_node->operation_node_data->operation_type_key->operation_key_data.delete_key_data.key);
            return OK;
        }
        else
        {
            COMMAND_ERROR(command, "--Error input, enter \"hd ?\" to get help\n");
            exit(EXIT_FAILURE);
        }
    }
    else if (strcmp(command->argv[1], "/") == 0)
    {
        TODO_PRINT("hd / key value");
        TODO_PRINT("modify k-v operation...");
        operation_node->operation_node_type = K;
        LOG_PRINT("passed1");
        operation_node->operation_node_data = (union node_data *)checked_malloc(sizeof(union node_data));
        operation_node->operation_node_data->operation_type_key = (OPERATION_TYPE_KEY)checked_malloc(sizeof(struct operation_type_key));
        operation_node->operation_node_data->operation_type_key->operation_key = UPDATE_KEY;
        LOG_PRINT("passed2");
        sprintf(operation_node->operation_node_data->operation_type_key->operation_key_data.update_key_data.key, "%s", command->argv[2]);
        LOG_PRINT("update date key:%s", operation_node->operation_node_data->operation_type_key->operation_key_data.update_key_data.key);
        return OK;
    }
    return OK;
}

void argc5(C_command command, O_OPERATION_NODE operation_node)
{
    TODO_PRINT("5 level operation...");
    if (strcmp(command->argv[1], "+") == 0)
    {
        if (strcmp(command->argv[2], "-k") == 0)
        {
            TODO_PRINT("hd + -k key value");
            TODO_PRINT("insert k-v operation...");
            operation_node->operation_node_type = K;
            LOG_PRINT("passed1");
            operation_node->operation_node_data = (union node_data *)checked_malloc(sizeof(union node_data));
            operation_node->operation_node_data->operation_type_key = (OPERATION_TYPE_KEY)checked_malloc(sizeof(struct operation_type_key));
            operation_node->operation_node_data->operation_type_key->operation_key = INSERT_KEY;
            LOG_PRINT("passed2");
            sprintf(operation_node->operation_node_data->operation_type_key->operation_key_data.insert_key_data.key, "%s", command->argv[3]);
            sprintf(operation_node->operation_node_data->operation_type_key->operation_key_data.insert_key_data.value, "%s", command->argv[4]);
            LOG_PRINT("insert date key:%s", operation_node->operation_node_data->operation_type_key->operation_key_data.insert_key_data.key);
            LOG_PRINT("insert date key:%s", operation_node->operation_node_data->operation_type_key->operation_key_data.insert_key_data.value);
            return OK;
        }
        else
        {
            COMMAND_ERROR(command, "--Error input, enter \"hd ?\" to get help\n");
            exit(EXIT_FAILURE);
        }
    }
    else if (strcmp(command->argv[1], "/") == 0)
    {
        if (strcmp(command->argv[2], "-k") == 0)
        {
            TODO_PRINT("hd / key value");
            TODO_PRINT("modify k-v operation...");
            operation_node->operation_node_type = K;
            LOG_PRINT("passed1");
            operation_node->operation_node_data = (union node_data *)checked_malloc(sizeof(union node_data));
            operation_node->operation_node_data->operation_type_key = (OPERATION_TYPE_KEY)checked_malloc(sizeof(struct operation_type_key));
            operation_node->operation_node_data->operation_type_key->operation_key = UPDATE_KEY;
            LOG_PRINT("passed2");
            sprintf(operation_node->operation_node_data->operation_type_key->operation_key_data.update_key_data.key, "%s", command->argv[3]);
            sprintf(operation_node->operation_node_data->operation_type_key->operation_key_data.update_key_data.value, "%s", command->argv[4]);
            LOG_PRINT("update date key:%s", operation_node->operation_node_data->operation_type_key->operation_key_data.update_key_data.key);
            LOG_PRINT("update date key:%s", operation_node->operation_node_data->operation_type_key->operation_key_data.update_key_data.value);
            return OK;
        }
        else
        {
            COMMAND_ERROR(command, "--Error input, enter \"hd ?\" to get help\n");
            exit(EXIT_FAILURE);
        }
    }

    return OK;
}
S_Status P_parser(C_command command, O_OPERATION_NODE operation_node)
{
    LOG_PRINT("parser....");
    if (command->argc == 1)
    {
        argc1();
    }
    /**
     * data descp: 命令 hd ?
     */
    else if (command->argc == 2 && (strcmp(command->argv[1], "?") == 0))
    {
        argc2();
    }
    /**
     * data descp: 三级命令
     */
    else if (command->argc == 3)
    {
        argc3(command, operation_node);
    }
    /**
     * data descp: 四级命令
     */
    else if (command->argc == 4)
    {
        argc4(command, operation_node);
    }
    /**
     * data descp: 五级命令
     */
    else if (command->argc == 5)
    {
        argc5(command, operation_node);
    }
    else
    {

        COMMAND_ERROR(command, "--Error input, enter \"hd ?\" to get help\n");
        exit(EXIT_FAILURE);
    }
}

O_OPERATION_NODE O_OPERATION_NODE_init(O_OPERATION_NODE o_operation_node)
{
    O_OPERATION_NODE ret = (O_OPERATION_NODE)checked_malloc(sizeof(*o_operation_node));
    return ret;
}
