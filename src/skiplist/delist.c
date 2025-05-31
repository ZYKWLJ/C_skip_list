#include "../../include/include.h"
/**
 * func descp: 两种模式，第一种是明确指定k-v(mod=0)，第二种是隐式存储v(mod=1)
 */
void N_print_node(N_node node)
{
    printf("[key:%s,val:%s]\n", node->key, node->val);
}
N_node N_init_node(N_node node, int mod)
{
    N_node ret = (N_node)checked_malloc(sizeof(*node));
    ret->key = (string)checked_malloc(sizeof(string) * 100);
    ret->val = (string)checked_malloc(sizeof(string) * 100);
    switch (mod)
    {
    case 1:
        /*指定k-v，先随便填充一个*/
        sprintf(ret->key, "%s", "\\");
        break;
    case 0:
        /*自动生成key，不会为负数的*/
        sprintf(ret->key, "%d", rand());
        break;
    }
    ret->next = NULL;
    ret->pre = NULL;
    ret->down = NULL;
    sprintf(ret->val, "default_val");
    N_print_node(ret);
    return ret;
}
/**
 * func descp: 单层初始化
 */
D_delist D_init_delist(D_delist delist)
{
    D_delist ret = (D_delist)checked_malloc(sizeof(*delist));
    ret->L = N_init_node(NULL, 0);
    ret->R = N_init_node(NULL, 0);
    ret->L->pre = NULL;
    ret->L->next = ret->R;
    ret->L->key = "HEAD"; // 首
    ret->R->pre = ret->L;
    ret->R->next = NULL;
    ret->R->key = "TAIL"; // 尾
    return ret;
}

/**
 * func descp: 单层打印
 */
void D_print_delist(D_delist delist)
{
    N_node node = delist->L->next;
    printf("begin->\n");
    while (strcmp(node->key, "TAIL"))
    {
        printf("[key:%s,val:%s]->\n", node->key, node->val);
        node = node->next;
    }
    printf("end\n");
}

/**
 * func descp: 单层搜索
 */

S_Status D_search(D_delist delist, C_command command)
{
    // hd \ -k xidian 等价于hd \ xidian
    // hd \ -v xidian
    // 提供键值搜索
    // LOG_PRINT("begin search %d", val);
    N_node node = delist->L->next;
    int pos = 0;
    if (command->argc == 3 || (command->argc == 4 && strcmp(command->argv[2], "-k") == 0))
    {
        /*删除键对应数据节点*/
        while (strcmp(node->key, "TAIL"))
        {
            pos++;
            if (strcmp(command->argv[3], node->key) == 0 /*核心点在与对比这里*/)
            {
                printf("find [key:%s,val:%s] in delist, pos:%d\n", node->key, node->val, pos);
                break;
            }
        }
    }
    else if (command->argc == 4 && strcmp(command->argv[2], "-v") == 0)
    {
        /*删除值对应数据节点*/
        while (strcmp(node->key, "TAIL"))
        {
            pos++;
            if (strcmp(command->argv[3], node->val) == 0 /*核心点在与对比这里*/)
            {
                printf("find [key:%s,val:%s] in delist, pos:%d\n", node->key, node->val, pos);
                break;
            }
        }
    }
    // LOG_PRINT("end search %d", val);
    return OK;
}

/**
 * func descp: 单层插入(注意一定是有序的!)
 */
S_Status D_insert(D_delist delist, C_command command)
{
    LOG_PRINT("beign insert...");
    // 命令：hd + xidian
    N_node new_node;
    if (command->argc == 3)
    {
        LOG_PRINT("argc=3  \t...");

        /*隐式存储,显然只有一个val*/
        new_node = N_init_node(NULL, 0);
        sprintf(new_node->val, "%s", command->argv[2]);
    }
    else
    {
        /*显示存储,有k-v，只取前两个argv[i]，后面的自动截断,并当kv个数大于2时提醒*/
        new_node = N_init_node(NULL, 1);
        sprintf(new_node->key, "%s", command->argv[2]);
        sprintf(new_node->val, "%s", command->argv[3]);
    }

    /*开始遍历找到合适的位置*/
    N_node node = delist->L->next;
    while (strcmp(node->key, "TAIL"))
    {
        /*时间局部性，先加入的很可能被访问到，所以=时，将最新的放在前面*/
        if (strcmp(node->key, command->argv[2]) >= 0)
        {
            /*说明找到了合适的位置*/
            N_node pre = node->pre;
            pre->next = new_node;
            new_node->pre = pre;
            new_node->next = node;
            node->pre = new_node;
            break;
        }
    }
    if (strcmp(node->key, "TAIL") == 0)
    {
        /*说明遍历到了尾部，直接插入尾部*/
        N_node pre = node->pre;
        pre->next = new_node;
        new_node->pre = pre;
        new_node->next = node;
        node->pre = new_node;
    }
    LOG_PRINT("end insert...");

    return OK;
}

/**
 * func descp: 单层删除
 */
S_Status D_delete(D_delist delist, C_command command)
{
    // hd - -k xidian 等价于hd - xidian
    // hd - -v xidian
    // 分别对应了删除键、删除值的情况
    // 默认为删除键
    // LOG_PRINT("begin search %d", val);

    N_node node = delist->L->next;
    int pos = 0;
    if (command->argc == 3 || (command->argc == 4 && strcmp(command->argv[2], "-k") == 0))
    {
        /*删除键对应数据节点*/
        while (strcmp(node->key, "TAIL"))
        {
            pos++;
            if (strcmp(command->argv[3], node->key) == 0 /*核心点在与对比这里*/)
            {
                printf("find in val %s in delist, pos:%d, deleted!\n", node->val, pos);
                node->pre->next = node->next;
                node->next->pre = node->pre;
                break;
            }
        }
    }
    else if (command->argc == 4 && strcmp(command->argv[2], "-v") == 0)
    {
        /*删除值对应数据节点*/
        while (strcmp(node->key, "TAIL"))
        {
            pos++;
            if (strcmp(command->argv[3], node->val) == 0 /*核心点在与对比这里*/)
            {
                printf("find in val %s in delist, pos:%d, deleted!\n", node->val, pos);
                node->pre->next = node->next;
                node->next->pre = node->pre;
                break;
            }
        }
    }
    // LOG_PRINT("end search %d", val);
    return OK;
}
