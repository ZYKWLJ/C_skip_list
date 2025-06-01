#include "../../include/include.h"
/**
 * func descp: 两种模式，第一种是明确指定k-v(mod=0)，第二种是隐式存储v(mod=1)
 */
void N_print_node(N_node node)
{
    printf("[key:%s,val:%s]\t", node->key, node->val);
}
N_node N_init_node(N_node node)
{
    N_node ret = (N_node)checked_malloc(sizeof(*node));
    ret->key = (string)checked_malloc(sizeof(string) * 10000);
    ret->val = (string)checked_malloc(sizeof(string) * 10000);
    /*自动生成key，不会为负数的(如果指定为k-v，后面覆盖即可)*/
    sprintf(ret->key, "%d", rand());
    ret->next = NULL;
    ret->pre = NULL;
    ret->down = NULL;
    sprintf(ret->val, "default_val");
    // N_print_node(ret);
    return ret;
}
/**
 * func descp: 单层初始化
 */
D_delist D_init_delist(D_delist delist)
{
    D_delist ret = (D_delist)checked_malloc(sizeof(*delist));
    ret->L = N_init_node(NULL);
    ret->R = N_init_node(NULL);
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

// S_Status D_search(D_delist delist, O_OPERATION_NODE operation_node, char mod /*是search还是其他借用*/)
N_node D_search(D_delist delist, O_OPERATION_NODE operation_node, char mod /*是search还是其他借用*/)
{
    // hd \ -k xidian 等价于hd \ xidian
    // hd \ -v xidian
    // 提供键值搜索
    // LOG_PRINT("begin search %d", val);
    N_node node = delist->L->next;
    int pos = 0;
    if (operation_node->operation_node_type == K)
    {
        /*查找键对应数据节点*/
        while (strcmp(node->key, "TAIL"))
        {
            pos++;
            if (strcmp(operation_node->operation_node_data->operation_type_key->operation_key_data.find_key_data.key, node->key) == 0 /*核心点在与对比这里*/)
            {
                if (mod == 's')
                {
                    printf("find [key:%s,val:%s] in delist, pos:%d\n", node->key, node->val, pos);
                }
                // break;
                // exit(EXIT_SUCCESS);
                return node;
                // return OK;
            }
        }
        if (mod == 's')
        {
            printf("No data's key equals to %s\n", operation_node->operation_node_data->operation_type_key->operation_key_data.find_key_data.key);
        }
    }
    else if (operation_node->operation_node_type == V)
    {
        /*查找键对应数据节点*/
        while (strcmp(node->key, "TAIL"))
        {
            pos++;
            if (strcmp(operation_node->operation_node_data->operation_type_value->operation_value_data.find_value_data.value, node->val) == 0 /*核心点在与对比这里*/)
            {
                if (mod == 's')
                {
                    printf("find [key:%s,val:%s] in delist, pos:%d\n", node->key, node->val, pos);
                } // break;
                // exit(EXIT_SUCCESS);
                // return OK;
                return node;
            }
        }
        if (mod == 's')
        {

            printf("No data's value equals to %s\n", operation_node->operation_node_data->operation_type_value->operation_value_data.find_value_data.value);
        }
    }
    // LOG_PRINT("end search %d", val);
    // return NOT_EXIST;
    return NULL;
}

/**
 * func descp: 单层插入(注意一定是有序的!),返回值为当前层级的节点的指针!
 */
// S_Status D_insert(D_delist delist, O_OPERATION_NODE operation_node)
N_node D_insert(D_delist delist, O_OPERATION_NODE operation_node)
{
    LOG_PRINT("beign insert...");
    // 命令：hd + xidian
    N_node new_node;
    if (operation_node->operation_node_type == K)
    {
        /*显示存储,有k-v，只取前两个argv[i]，后面的自动截断,并当kv个数大于2时提醒*/
        new_node = N_init_node(NULL);
        sprintf(new_node->key, "%s", operation_node->operation_node_data->operation_type_key->operation_key_data.insert_key_data.key);
        sprintf(new_node->val, "%s", operation_node->operation_node_data->operation_type_key->operation_key_data.insert_key_data.value);
        /*开始遍历找到合适的位置*/
        N_node node = delist->L->next;
        while (strcmp(node->key, "TAIL"))
        {
            /*时间局部性，先加入的很可能被访问到，所以=时，将最新的放在前面*/
            if (strcmp(node->key, new_node->key) >= 0)
            {
                /*说明找到了合适的位置*/
                N_node pre = node->pre;
                pre->next = new_node;
                new_node->pre = pre;
                new_node->next = node;
                node->pre = new_node;
                return new_node;
                // break;
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
            return new_node;
        }
    }
    else if (operation_node->operation_node_type == V)
    {
        /*隐式存储,显然只有一个val*/
        new_node = N_init_node(NULL);
        sprintf(new_node->val, "%s", operation_node->operation_node_data->operation_type_value->operation_value_data.insert_value_data.value);
        /*开始遍历找到合适的位置*/
        N_node node = delist->L->next;
        while (strcmp(node->key, "TAIL"))
        {
            /*时间局部性，先加入的很可能被访问到，所以=时，将最新的放在前面*/
            if (strcmp(node->val, new_node->val) >= 0)
            {
                /*说明找到了合适的位置*/
                N_node pre = node->pre;
                pre->next = new_node;
                new_node->pre = pre;
                new_node->next = node;
                node->pre = new_node;
                return new_node;

                // break;
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
            return new_node;
        }
    }

    LOG_PRINT("insert successed...");
    // D_search(delist,operation_node);
    D_print_delist(delist);
    return OK;
}

/**
 * func descp: 单层删除
 */
S_Status D_delete(D_delist delist, O_OPERATION_NODE operation_node)
{
    // hd - -k xidian 等价于hd - xidian
    // hd - -v xidian
    // 分别对应了删除键、删除值的情况
    // 默认为删除键
    // LOG_PRINT("begin search %d", val);

    N_node node = delist->L->next;
    int pos = 0;
    if (operation_node->operation_node_type == K)
    {
        /*删除键对应数据节点*/
        while (strcmp(node->key, "TAIL"))
        {
            pos++;
            if (strcmp(operation_node->operation_node_data->operation_type_key->operation_key_data.delete_key_data.key, node->key) == 0 /*核心点在与对比这里*/)
            {
                N_print_node(node);
                printf("pos:%d, deleted!\n", pos);
                node->pre->next = node->next;
                node->next->pre = node->pre;
                break;
            }
        }
    }
    else if (operation_node->operation_node_type == V)
    {
        /*删除值对应数据节点*/
        while (strcmp(node->key, "TAIL"))
        {
            pos++;
            if (strcmp(operation_node->operation_node_data->operation_type_value->operation_value_data.delete_value_data.value, node->val) == 0 /*核心点在与对比这里*/)
            {
                N_print_node(node);
                printf("pos:%d, deleted!\n", pos);
                node->pre->next = node->next;
                node->next->pre = node->pre;
                break;
            }
        }
    }
    // LOG_PRINT("end search %d", val);
    return OK;
}

/**
 * func descp: 单层修改
 */
S_Status D_update(D_delist delist, O_OPERATION_NODE operation_node)
{
    // hd - -k xidian 等价于hd - xidian
    // hd - -v xidian
    // 分别对应了删除键、删除值的情况
    // 默认为删除键
    // LOG_PRINT("begin search %d", val);

    N_node node = delist->L->next;
    int pos = 0;
    if (operation_node->operation_node_type == K)
    {
        /*删除键对应数据节点*/
        while (strcmp(node->key, "TAIL"))
        {
            pos++;
            if (strcmp(operation_node->operation_node_data->operation_type_key->operation_key_data.update_key_data.key, node->key) == 0 /*核心点在与对比这里*/)
            {
                N_print_node(node);
                printf("pos:%d, update!\n", pos);
                sprintf(node->val, operation_node->operation_node_data->operation_type_key->operation_key_data.update_key_data.value);
                exit(EXIT_SUCCESS);
            }
        }
    }
    else if (operation_node->operation_node_type == V)
    {
        /*删除值对应数据节点*/
        while (strcmp(node->key, "TAIL"))
        {
            pos++;
            if (strcmp(operation_node->operation_node_data->operation_type_value->operation_value_data.delete_value_data.value, node->val) == 0 /*核心点在与对比这里*/)
            {
                N_print_node(node);
                printf("pos:%d, update!\n", pos);
                sprintf(node->val, operation_node->operation_node_data->operation_type_key->operation_key_data.update_key_data.value);
                exit(EXIT_SUCCESS);
            }
        }
    }
    // LOG_PRINT("end search %d", val);
    return OK;
}
