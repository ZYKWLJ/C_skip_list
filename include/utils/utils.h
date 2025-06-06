#ifndef UTILS_H_
#define UTILS_H_
#include <stdlib.h>
#include <stdio.h>

/**
 * filename:utils.h
 * description: 状态模块
 * author:EthanYankang
 * create time:2025/05/31 22:26:03
 */
typedef enum Status_
{
    OK,
    ERROR,
    NOT_EXIST,
} S_Status;
/**
 * filename:utils.h
 * description: 命令行解析模块
 * author:EthanYankang
 * create time:2025/05/31 16:34:31
 */
typedef struct C_command_
{
    int argc;
    char **argv;
} *C_command;

C_command C_command_init(C_command command, int argc, char **argv);
void C_command_print(C_command command);
void COMMAND_ERROR(C_command command, const char *format, ...);

/**
 * description: 日志模块
 * author:EthanYankang
 * create time:2025/05/01 14:41:31
 */
// #define LOG
#ifdef LOG
// #define LOG_PRINT(msg) printf("[LOG %s %s %s:%d] %s\n" __DATE__, __TIME__, __FILE__, __LINE__, msg)
#define LOG_PRINT(...)                                                    \
    printf("[LOG %s %s %s:%d] ", __DATE__, __TIME__, __FILE__, __LINE__); \
    printf(__VA_ARGS__);                                                  \
    printf("\n")
#else
#define LOG_PRINT(...) \
    do                 \
    {                  \
    } while (0)
#endif

/**
 * filename:util.h
 * description: TODO模块
 * author:EthanYankang
 * create time:2025/05/01 14:42:08
 */

// #define TODO
#ifdef TODO
#define TODO_PRINT(...)                                                    \
    printf("[TODO %s %s %s:%d] ", __DATE__, __TIME__, __FILE__, __LINE__); \
    printf(__VA_ARGS__);                                                   \
    printf("\n")
#else
#define TODO_PRINT(...) \
    do                  \
    {                   \
    } while (0)
#endif
/**
 * func descp: 检查颜色是否启用的函数（需要您根据实际情况实现）
 */
int color_enabled();
/**
 * func descp: 检查是否设置边框显示
 */
int border_enabled();
/**
 * func descp: 检查是否设置时间显示
 */
int time_enabled();
/**
 * func descp: 红色打印，专注于错误信息
 */
// 带颜色的打印宏
#define RED_PRINT(...)           \
    do                           \
    {                            \
        if (color_enabled())     \
        {                        \
            printf(RED);         \
            printf(__VA_ARGS__); \
            printf("%s", RESET); \
        }                        \
        else                     \
        {                        \
            printf(__VA_ARGS__); \
        }                        \
    } while (0)

/**
 * func descp: 绿色打印，专注于核心智能信息提示
 */
#define GREEN_PRINT(...)         \
    do                           \
    {                            \
        if (color_enabled())     \
        {                        \
            printf(GREEN);       \
            printf(__VA_ARGS__); \
            printf("%s", RESET); \
        }                        \
        else                     \
        {                        \
            printf(__VA_ARGS__); \
        }                        \
    } while (0)

/**
 * func descp: 黄色打印，专注于警告信息
 */
#define YELLOW_PRINT(...)        \
    do                           \
    {                            \
        if (color_enabled())     \
        {                        \
            printf(YELLOW);      \
            printf(__VA_ARGS__); \
            printf("%s", RESET); \
        }                        \
        else                     \
        {                        \
            printf(__VA_ARGS__); \
        }                        \
    } while (0)

void *checked_malloc(size_t len) /*返回了通用指针 */;

#endif