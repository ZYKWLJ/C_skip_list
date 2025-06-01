#include "../../include/include.h"
#define MAX_LINE_LENGTH 1024
extern INSERT_ON_ODD_SHOW insert_on_or_show;
void read_data_from_disk(char *file_path, L_skip_list skiplist)
{
    if (!file_path || !skiplist)
    {
        printf("Invalid parameters\n");
        return;
    }

    FILE *fp = fopen(file_path, "r");
    if (fp == NULL)
    {
        printf("Failed to open file for reading: %s\n", file_path);
        return;
    }

    char line[MAX_LINE_LENGTH];
    int count = 0;

    while (fgets(line, sizeof(line), fp) != NULL)
    {
        // 移除换行符
        line[strcspn(line, "\n")] = '\0';
        LOG_PRINT("FIND first `:` position");
        // 查找第一个冒号位置
        char *colon = strchr(line, ':');
        if (!colon)
        {
            continue; // 跳过格式错误的行
        }

        // 分割key和value
        *colon = '\0';
        char *key = line;
        char *value = colon + 1;
        LOG_PRINT("key:%s\tvalue:%s\n", key, value);

        if (strlen(key) > 0 && strlen(value) > 0)
        {
            // 需要复制字符串，因为strtok返回的是指向原缓冲区的指针
            char *key_copy = strdup(key);
            char *value_copy = strdup(value);

            if (key_copy && value_copy)
            {
                L_skip_list_insert(skiplist, key_copy, value_copy);
                count++;
                LOG_PRINT("read_disk:%s:%s\n", key_copy, value_copy);
            }
            else
            {
                free(key_copy);
                free(value_copy);
            }
        }
    }

    fclose(fp);
    LOG_PRINT("Successfully loaded %d items from disk\n", count);
}