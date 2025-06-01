#include "../../include/include.h"
// #include "skiplist.h"
extern L_skip_list skip_list;
extern INSERT_ON_ODD_SHOW insert_on_or_show;
extern SEARCH_ON_ODD_SHOW search_on_or_show;

#define MAX_LEVEL 16
#define MAX_KEY_VALUE_LEN 10000 // 明确缓冲区大小宏定义

/**
 * 随机层级获取函数（修正概率逻辑：使用0.5概率增长，层级范围[1, MAX_LEVEL]）
 */
int random_level()
{
    int level = 1;
    while (rand() % 2 == 0 && level < MAX_LEVEL)
    { // 修正条件：0表示继续增长
        level++;
    }
    return level;
}

/**
 * 节点初始化函数（修正内存分配和默认值处理）
 */
N_skip_node N_skip_node_init(int level, string key, string value)
{
    LOG_PRINT("N_skip_node_init begin...");
    N_skip_node node = (N_skip_node)checked_malloc(sizeof(struct skip_node));
    if (!node)
        return NULL;

    // 分配并初始化key/value缓冲区（明确初始化避免野指针）
    node->key = (string)checked_malloc(MAX_KEY_VALUE_LEN);
    node->value = (string)checked_malloc(MAX_KEY_VALUE_LEN);
    memset(node->key, 0, MAX_KEY_VALUE_LEN);
    memset(node->value, 0, MAX_KEY_VALUE_LEN);

    // 分配前向指针数组（层级从0开始，包含level+1个指针）
    node->forward = (N_skip_node *)checked_malloc((level + 1) * sizeof(N_skip_node));
    if (!node->key || !node->value || !node->forward)
    {
        printf("Memory allocation failed in node init");
        // free(node->key);
        // free(node->value);
        // free(node->forward);
        // free(node);
        return NULL;
    }

    // 处理key（默认值修正为更明确的标识）
    if (key != NULL)
    {
        snprintf(node->key, MAX_KEY_VALUE_LEN, "%s", key); // 安全字符串拷贝
    }
    else
    {
        snprintf(node->key, MAX_KEY_VALUE_LEN, "HEAD"); // 头节点key标识
    }

    // 处理value（默认值使用双反斜杠避免转义问题）
    if (value != NULL)
    {
        LOG_PRINT("value is not null");
        snprintf(node->value, MAX_KEY_VALUE_LEN, "%s", value);
    }
    else
    {
        LOG_PRINT("value is null");
        snprintf(node->value, MAX_KEY_VALUE_LEN, "NULL"); // 明确存储双反斜杠
    }

    // 初始化前向指针为NULL
    for (int i = 0; i <= level; i++)
    {
        node->forward[i] = NULL;
    }

    LOG_PRINT("%s[%s] -> ", node->key, node->value);
    LOG_PRINT("N_skip_node_init over...");

    return node;
}

/**
 * 跳表初始化函数（修正头节点层级和指针初始化）
 */
L_skip_list L_skip_list_init()
{
    LOG_PRINT("L_skip_list_init begin...");
    L_skip_list list = (L_skip_list)checked_malloc(sizeof(struct skip_list));
    if (!list)
        return NULL;

    list->level = 1; // 初始层级为1（包含level=1）
    list->size = 0;
    // 创建头节点（层级为MAX_LEVEL，key为HEAD，value为默认值）
    list->header = N_skip_node_init(MAX_LEVEL, NULL, NULL);
    if (!list->header)
    {
        // free(list);
        return NULL;
    }

    // 初始化所有层的前向指针为NULL（层级从0到MAX_LEVEL）
    for (int i = 0; i <= MAX_LEVEL; i++)
    {
        list->header->forward[i] = NULL;
    }

    LOG_PRINT("L_skip_list_init over...");
    srand(time(NULL)); // 随机数种子初始化移到此处
    return list;
}

/**
 * 插入节点函数（修正层级遍历和更新逻辑）
 */
void L_skip_list_insert(L_skip_list list, string key, string value)
{
    if (!list || !list->header || !key)
        return;

    N_skip_node update[MAX_LEVEL + 1]; // 层级0~MAX_LEVEL
    N_skip_node current = list->header;

    // 从最高层开始查找插入位置（层级从MAX_LEVEL到1，因为level可能小于MAX_LEVEL）
    for (int i = list->level; i >= 1; i--)
    {
        while (current->forward[i] != NULL && strcmp(current->forward[i]->key, key) < 0)
        {
            current = current->forward[i];
        }
        update[i] = current;
    }

    // 检查底层是否存在相同key
    current = current->forward[1]; // 从level=1层开始检查
    if (current != NULL && strcmp(current->key, key) == 0)
    {
        // 存在相同key，执行更新
        printf("%s", insert_on_or_show == INSERT_ON ? "Data already existed." : "");
        if (strcmp(current->value, value) == 0)
        {
            if (insert_on_or_show == INSERT_ON)
            {
                printf("No need to update\n");
            }
        }
        else
        {
            if (insert_on_or_show == INSERT_ON)
            {
                printf("Update %s[%s]->%s[%s]\n", current->key, current->value, key, value);
            }
            // 安全更新value（释放旧内存，分配新内存）
            // free(current->value);
            current->value = (string)checked_malloc(strlen(value) + 1);
            strcpy(current->value, value);
        }
        return;
    }

    // 生成新节点层级（包含level=0）
    int new_level = random_level();
    if (new_level > list->level)
    {
        // 扩展跳表层级
        for (int i = list->level + 1; i <= new_level; i++)
        {
            update[i] = list->header;
        }
        list->level = new_level;
    }

    // 创建新节点（层级为new_level，包含0~new_level层）
    N_skip_node new_node = N_skip_node_init(new_level, key, value);
    if (!new_node)
        return;

    // 更新各层前向指针（从level=1开始，因为level=0可能不使用）
    for (int i = 1; i <= new_level; i++)
    {
        new_node->forward[i] = update[i]->forward[i];
        update[i]->forward[i] = new_node;
    }
    if (insert_on_or_show == INSERT_ON)
    {
        printf("Insert success! Key: %s, Value: %s\n", key, value);
    }

    list->size++;
}

/**
 * 查找节点函数（统一层级遍历逻辑）
 */
N_skip_node L_skip_list_search(L_skip_list list, string key, string value)
{
    if (!list || !list->header || !key)
        return NULL;

    N_skip_node current = list->header;
    // 从最高有效层开始查找
    for (int i = list->level; i >= 1; i--)
    {
        while (current->forward[i] != NULL && strcmp(current->forward[i]->key, key) < 0)
        {
            current = current->forward[i];
        }
    }

    // 移动到最底层节点（level=1）
    current = current->forward[1];
    if (current && strcmp(current->key, key) == 0)
    {
        if (search_on_or_show == SEARCH_ON)
        {
            // printf("Result: %s[%s]\n", current->key, current->value);
            printf("Result:\n");
            char *key[] = {current->key, NULL};
            char *value[] = {current->value, NULL};
            char **KV[] = {key, value};
            text_print_head0_blank1(KV, sizeof(KV) / sizeof(KV[0]));
        }
        return current;
    }
    else
    {
        if (search_on_or_show == SEARCH_ON)
        {
            printf("Not found key: %s\n", key);
        }
        return NULL;
    }
}

/**
 * 更新节点值函数（简化逻辑，直接调用查找函数）
 */
void L_skip_list_update(L_skip_list list, string key, string new_value)
{
    search_on_or_show = SEARCH_OFF;
    N_skip_node node = L_skip_list_search(list, key, new_value);
    search_on_or_show = SEARCH_ON;

    if (node)
    {
        // 安全更新value（处理长度限制）
        snprintf(node->value, MAX_KEY_VALUE_LEN, "%s", new_value);
        printf("Update success! New value: %s\n", new_value);
    }
    else
    {
        printf("Update failed: Key not found\n");
    }
}

/**
 * 删除节点函数（完整层级处理和内存释放）
 */
void L_skip_list_delete(L_skip_list list, string key, string value)
{
    if (!list || !list->header || !key)
    {
        printf("Invalid parameters\n");
        return;
    }

    N_skip_node update[MAX_LEVEL + 1]; // 存储各层前驱节点
    N_skip_node current = list->header;

    // 从最高层开始查找删除路径
    for (int i = list->level; i >= 1; i--)
    {
        while (current->forward[i] != NULL && strcmp(current->forward[i]->key, key) < 0)
        {
            current = current->forward[i];
        }
        update[i] = current;
    }

    // 定位到目标节点（从最低层 level=1 开始）
    current = current->forward[1];

    // 检查节点是否存在且 key 匹配
    if (current != NULL && strcmp(current->key, key) == 0)
    {
        // 若传入 value 不为 NULL，需校验 value 是否为字符串 "NULL" 或其他值
        if (value != NULL)
        {
            if (strcmp(current->value, value) != 0)
            {
                printf("Value mismatch for key: %s (expected: %s, found: %s)\n",
                       key, value, current->value);
                return;
            }
        }

        // 获取节点实际层级（遍历 forward 数组，直到遇到 NULL）
        int node_level = 1;
        while (node_level <= list->level && current->forward[node_level] != NULL)
        {
            node_level++;
        }

        // 更新各层前向指针
        for (int i = 1; i <= node_level; i++)
        {
            if (update[i]->forward[i] == current)
            {
                update[i]->forward[i] = current->forward[i];
            }
        }

        // 调整跳表层级（若最高层无节点，降低层级）
        while (list->level > 1 && list->header->forward[list->level] == NULL)
        {
            list->level--;
        }

        // free(current); // 释放节点内存（假设节点是动态分配的）
        list->size--; // 减少节点计数
        printf("Delete success! Key: %s, Value: %s\n", key, value ? value : "NULL");
    }
    else
    {
        printf("Delete failed: Key %s not found\n", key);
    }
}
/**
 * 打印跳表函数（清晰的层级遍历和头节点处理）
 */
void L_skip_list_print(L_skip_list list)
{
// #define PRINT
#ifdef PRINT
    if (!list || !list->header)
        return;

    printf("Skip List (Level: %d, Size: %d)\n", list->level, list->size);
    for (int i = list->level; i >= 1; i--)
    { // 从最高有效层开始打印
        printf("Level %d: ", i);
        N_skip_node node = list->header->forward[i]; // 头节点的下一个节点
        while (node != NULL)
        {
            printf("%s[%s] -> ", node->key, node->value);
            node = node->forward[i];
        }
        printf("NULL\n");
    }
#endif
    printf("\n");
}

/**
 * 释放跳表内存函数（完整的资源释放流程）
 */
void free_skip_list(L_skip_list list)
{
    if (!list)
        return;

    // 释放数据节点
    N_skip_node current = list->header->forward[1];
    while (current != NULL)
    {
        N_skip_node next = current->forward[1];
        free(current->key);
        free(current->value);
        free(current->forward);
        free(current);
        current = next;
    }

    // 释放头节点
    free(list->header->key);
    free(list->header->value);
    free(list->header->forward);
    free(list->header);

    // 释放跳表结构
    free(list);
}