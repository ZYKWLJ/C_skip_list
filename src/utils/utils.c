#include "../../include/include.h"

/**
 * func descp: 命令行解析模块
 */
C_command C_command_init(C_command c, int argc, char **argv)
{
    C_command command = (C_command)checked_malloc(sizeof(*c));
    command->argc = argc;
    command->argv = argv;
    return command;
}
void C_command_print(C_command command)
{
    printf("argc: %d\n", command->argc);
    for (int i = 0; i < command->argc; i++)
    {
        printf("argv[%d]: %s\n", i, command->argv[i]);
    }
}

void COMMAND_ERROR(C_command command, const char *format, ...)
{
    printf("\"");
    printf("hd");
    for (int i = 1 /*直接从第一个开始，兼容性*/; i < command->argc; i++)
    {
        printf(" %s", command->argv[i]);
    }
    printf("\"");

    // }

    va_list args;
    va_start(args, format);

    // 输出格式化的错误信息
    vprintf(format, args);

    printf("\n");

    va_end(args);
}

/**
 * func descp: 内存分配模块
 */
void *checked_malloc(size_t len)
{
    void *p = calloc(1, len); // 分配len这么大小的空间，并初始化为0
    if (!p)
    {
        fprintf(stderr, "failed to calloc\n");
        exit(EXIT_FAILURE);
    }
    return p;
}
