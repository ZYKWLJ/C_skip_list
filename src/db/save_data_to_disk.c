#include "../../include/include.h"
// #define MAX_LINE_LENGTH 1024

void save_data_to_disk(char *file_path, L_skip_list skiplist)
{
    if (!file_path || !skiplist || !skiplist->header)
    {
        printf("Invalid parameters\n");
        return;
    }

    FILE *fp = fopen(file_path, "w");
    if (fp == NULL)
    {
        printf("Failed to open file for writing: %s\n", file_path);
        return;
    }

    N_skip_node node = skiplist->header->forward[1];
#if 0
    LOG_PRINT("node:%p\n",node);
    LOG_PRINT("node->key:%p\n",node->key);
    LOG_PRINT("node->value:%p\n",node->value);
    LOG_PRINT("node->forward[0]:%p\n",node->forward[0]);
#endif
    while (node != NULL)
    {
        if (node->key && node->value)
        {
            // 对key和value中的特殊字符进行转义处理
            LOG_PRINT("before save");
            // L_skip_list_print(skiplist);
            fprintf(fp, "%s:%s\n", node->key, node->value);
            LOG_PRINT("save_disk:%s:%s\n", node->key, node->value);
        }
        node = node->forward[1];
    }

    fclose(fp);
    LOG_PRINT("Successfully saved %d items to disk\n", skiplist->size);
}
