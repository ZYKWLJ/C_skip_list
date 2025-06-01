#include "../../include/include.h"
/**
 * func descp: 随机层级获取函数
 */
int D_get_random_level()
{
    int a = 1;
    int level = 0;
    while (a) // 第一层是肯定能进来的
    {
        level++;
        a = rand() % 2;
        if (level > MAX_LEVEL)
        {
            level = MAX_LEVEL;
            break;
        }
    }
    // printf("level=%d\n", level);
    return level;
}
/**
 * func descp: 找到每次增加、插入时，数据在每一层的前驱节点。理论上来说，可以传入层数仅仅遍历需要修改的层数即可，为了方便仅仅全遍历。
 */
N_node *pre_pointer_eve_level(L_skipList sklist, string key, string value, char mod)
{
    LOG_PRINT("pre_pointer_eve_level func begin...");

    /*因为理论上来说，每一层都有需要获取的前驱节点*/
    N_node *pre_pointer_arr = (N_node *)checked_malloc(sizeof(N_node) * MAX_LEVEL);
    for (int i = 0; i < MAX_LEVEL; i++)
    {
        pre_pointer_arr[i] = (N_node)checked_malloc(sizeof(struct node_));
    }
    N_node node = sklist[0].delist->L;

    /*开始遍历每一层，找到合适的插入前驱位置,即找到`最后一个`比自己的大的元素即可*/
    if (mod == 'k')
    {
        LOG_PRINT("pre_pointer_arr k begin...");

        for (int i = 0; i < MAX_LEVEL; i++)
        {
            /*该层一直遍历到末尾*/
            while (strcmp(node->key, "TAIL"))
            {
                /*如果找到了key了，就一直下沉就好了*/
                while (strcmp(key, node->key) >= 0)
                {
                    LOG_PRINT("pre_pointer_arr k find ...");

                    pre_pointer_arr[i] = node->pre;
                    /*下沉，因为下一层的元素一定在该元素的下层的元素的后面*/
                    node = node->next;
                    node = node->down;
                }
            }
        }
        return pre_pointer_arr;
    }
    else if (mod == 'v')
    // 此处不知道key，所以需要先求出k，在用k来做上面的动作,此时k已经写在operation_node中了
    // 这是一般用来删除数据的！
    {
        LOG_PRINT("pre_pointer_arr v begin...");

        N_node node = N_init_node(NULL);
        for (int i = 0; i < MAX_LEVEL; i++)
        {
            O_OPERATION_NODE operation_node = O_OPERATION_NODE_init(NULL);
            operation_node->operation_node_type = V;
            sprintf(operation_node->operation_node_data->operation_type_value->operation_value_data.find_value_data.value, "%s", value);
            node = D_search(sklist[i].delist, operation_node, 's');
            /*一旦找到，下面层一定都有！直接内含循环即可*/
            if (node)
            {
                while (strcmp(node->key, "TAIL"))
                {
                    if (strcmp(node->val, value) == 0)
                    {
                        node = node->pre;
                        pre_pointer_arr[i] = node;
                        /*下沉，因为下一层的元素一定在该元素的下层的元素的后面*/
                        node = node->down;
                        /*一旦在该层找到了，就立即直接遍历下面所以的*/
                    }
                    node = node->next;
                }
            }
            else
            {
                pre_pointer_arr[i] = NULL;
            }
        }
        return pre_pointer_arr;
    }
    return pre_pointer_arr;
}

/**
 * func descp: 跳表初始化
 */
L_skipList L_skipList_init(L_skipList sklist)
{
    L_skipList ret = (L_skipList)checked_malloc(sizeof(*sklist) * MAX_LEVEL); // 这么多个层级的双向链表联结
    /*把每一层都初始化好了*/
    for (int i = 0; i < MAX_LEVEL - 1; i++)
    {
        ret[i].delist = D_init_delist(NULL);
        /*开始织网*/
        ret[i].delist->L->down = ret[i + 1].delist->L->down;
        ret[i].delist->R->down = ret[i + 1].delist->R->down;
    }
    return ret;
}

/**
 * func descp: 全表打印
 */
void L_print_skiplist(L_skipList sklist)
{
    /*本质是单层打印的循环遍历*/
    for (int i = 0; i < MAX_LEVEL; i++)
    {
        printf("level %d\n", i);
        D_print_delist(sklist[i].delist);
        printf("\n\n");
    }
}
/**
 * func descp: 全表搜索，从上到下开始，具有二分的效率
 */
S_Status L_search(L_skipList sklist, O_OPERATION_NODE operation_node)
{
    N_node node = sklist[0].delist->L;
    if (operation_node->operation_node_type == K)
    {
        for (int i = 0; i < MAX_LEVEL; i++)
        {
            node = sklist[i].delist->L;
            int pos = 0;
            while (strcmp(node->key, "TAIL") == 0)
            {
                pos++;
                if (strcmp(operation_node->operation_node_data->operation_type_key->operation_key_data.find_key_data.key, node->key) == 0)
                {
                    N_print_node(node);
                    printf("find in level:%d, pos:%d\n", i, pos);
                    exit(EXIT_SUCCESS);
                    // return OK;
                }
                /*说明本层太稀疏，数据在下一层*/
                else if (strcmp(operation_node->operation_node_data->operation_type_key->operation_key_data.find_key_data.key, node->key) > 0)
                {
                    /*先往前回跳一格，再往下*/
                    node = node->pre;
                    node = node->down;
                }
                /*否则就是还可以本层往后查找*/
                node = node->next;
            }
        }
        printf("No data's key equals to %s\n", operation_node->operation_node_data->operation_type_key->operation_key_data.find_key_data.key);
    }
    else if (operation_node->operation_node_type == V)
    {
        for (int i = 0; i < MAX_LEVEL; i++)
        {

            node = sklist[i].delist->L;
            int pos = 0;
            while (strcmp(node->key, "TAIL") == 0)
            {
                pos++;
                if (strcmp(operation_node->operation_node_data->operation_type_value->operation_value_data.find_value_data.value, node->val) == 0)
                {
                    N_print_node(node);
                    printf("find in level:%d, pos:%d\n", i, pos);
                    exit(EXIT_SUCCESS);
                    // return OK;
                }
                /*说明本层太稀疏，数据在下一层*/
                else if (strcmp(operation_node->operation_node_data->operation_type_value->operation_value_data.find_value_data.value, node->val) > 0)
                {
                    /*先往前回跳一格，再往下*/
                    node = node->pre;
                    node = node->down;
                }
                /*否则就是还可以本层往后查找*/
                node = node->next;
            }
        }
        printf("No data's value equals to %s\n", operation_node->operation_node_data->operation_type_value->operation_value_data.find_value_data.value);
    }
    // return OK;
    exit(EXIT_SUCCESS);
}
/**
 * func descp: 这个直接调用单层逻辑即可，但是注意，还要完成下指针的连接！此为最核心的一点。
 */
S_Status L_insert(L_skipList sklist, O_OPERATION_NODE operation_node)
{
    LOG_PRINT("L_insert func begin...");
    /**
     * data descp: 先获取每一层的该数据的前驱节点
     */
    N_node *pre_pointer_arr;
    /**
     * data descp: 获取随机层级
     */
    int level = D_get_random_level();
    if (operation_node->operation_node_type == K)
    {
        pre_pointer_arr = pre_pointer_eve_level(sklist, operation_node->operation_node_data->operation_type_key->operation_key_data.insert_key_data.key, NULL, 'k');

        /**
         * data descp: 这里保存每一层的下节点！
         */
        N_node node_down_arr[MAX_LEVEL];
        for (int i = 0; i < MAX_LEVEL; i++)
        {
            node_down_arr[i] = NULL;
        }
        /*随机层级以下层级的都有该数据*/
        /**
         * data descp: 这里的指针操作是个难点！也是核心点！怎样操作down?
         * 必须从最底层开始，因为要保证下面的网织好了才行。
         */
        for (int i = MAX_LEVEL - 1; i >= level; i--)
        {
            /*每一层找到第一个比该数据大的数据即可,充分利用刚刚得到的前驱节点指针数组，完成织网*/
            // D_insert(sklist[i].delist, operation_node);
            N_node node = N_init_node(NULL);
            node->key = operation_node->operation_node_data->operation_type_key->operation_key_data.insert_key_data.key;
            node->val = operation_node->operation_node_data->operation_type_key->operation_key_data.insert_key_data.value;
            /*横向连接*/
            pre_pointer_arr[i]->next = node;
            node->pre = pre_pointer_arr[i];
            pre_pointer_arr[i]->next->pre = node;
            node->next = pre_pointer_arr[i]->next;
            if (i != MAX_LEVEL - 1) /*最后一层不用向下连接*/
            {
                /*纵向连接*/
                node->down = node_down_arr[i];
            }
            node_down_arr[i] = node;
        }
    }
    else if (operation_node->operation_node_type == V)
    {
        pre_pointer_arr = pre_pointer_eve_level(sklist, NULL, operation_node->operation_node_data->operation_type_value->operation_value_data.insert_value_data.value, 'v');
        /**
         * data descp: 这里保存每一层的下节点！
         */
        N_node node_down_arr[MAX_LEVEL];
        for (int i = 0; i < MAX_LEVEL; i++)
        {
            node_down_arr[i] = NULL;
        }
        /*随机层级以下层级的都有该数据*/
        /**
         * data descp: 这里的指针操作是个难点！也是核心点！怎样操作down?
         * 必须从最底层开始，因为要保证下面的网织好了才行。
         */
        for (int i = MAX_LEVEL - 1; i >= level; i--)
        {
            /*每一层找到第一个比该数据大的数据即可,充分利用刚刚得到的前驱节点指针数组，完成织网*/
            // D_insert(sklist[i].delist, operation_node);
            N_node node = N_init_node(NULL); /*自动生成key*/
            node->val = operation_node->operation_node_data->operation_type_key->operation_key_data.insert_key_data.value;
            /*横向连接*/
            pre_pointer_arr[i]->next = node;
            node->pre = pre_pointer_arr[i];
            pre_pointer_arr[i]->next->pre = node;
            node->next = pre_pointer_arr[i]->next;
            if (i != MAX_LEVEL - 1) /*最后一层不用向下连接*/
            {
                /*纵向连接*/
                node->down = node_down_arr[i];
            }
            node_down_arr[i] = node;
        }
    }
    LOG_PRINT("L_insert func end...");
    return OK;
}

/**
 * func descp: 找到每次删除、修改时，数据在每一层的节点。理论上来说，可以传入层数仅仅遍历需要修改的层数即可，为了方便仅仅全遍历。
 */
N_node *current_pointer_eve_level(L_skipList sklist, string key, string value, char mod)
{
    /*因为理论上来说，每一层都有需要获取的节点*/
    N_node *current_pointer_arr = (N_node *)checked_malloc(sizeof(N_node) * MAX_LEVEL);
    for (int i = 0; i < MAX_LEVEL; i++)
    {
        current_pointer_arr[i] = (N_node)checked_malloc(sizeof(struct node_));
    }
    N_node node = sklist[0].delist->L;

    /*开始遍历每一层，找到自己在每一层的节点,注意这里一定要用跳表的性质才行!*/
    if (mod == 'k')
    {
        for (int i = 0; i < MAX_LEVEL; i++)
        {

            while (strcmp(node->key, key) == 0)
            {
                current_pointer_arr[i] = node;
                node = node->down;
                i++;
            }
            current_pointer_arr[i] = NULL;
        }

        /**
         * data descp: 最后一层都是NULL，说明一定没有该数据，直接报错返回
         */
        if (current_pointer_arr[MAX_LEVEL - 1] == NULL)
        {

            printf("No data's key equals to %s\n", key);
            exit(EXIT_FAILURE);
        }
        return current_pointer_arr;
    }
    else if (mod == 'v')
    // 此处不知道key，所以需要先求出k，在用k来做上面的动作,此时k已经写在operation_node中了
    // 这是一般用来删除数据的！
    {
        // 这里如果直接调用单层循环的话，就没意义了，复杂度就变为了O(n)了，要结合跳表的性质来做。
        // 但是这里因为不知道key，所以必然要先找出key,一定要使用跳表的性质来找，从上向下二分速率，但是这个是基于key的，所以这里也只能从底层一次遍历以找到key。
        O_OPERATION_NODE operation_node = O_OPERATION_NODE_init(NULL);
        operation_node->operation_node_type = V;
        operation_node->operation_node_data = (union node_data_ *)checked_malloc(sizeof(union node_data));
        operation_node->operation_node_data->operation_type_value = (struct operation_type_value *)checked_malloc(sizeof(struct operation_type_value));
        sprintf(operation_node->operation_node_data->operation_type_value->operation_value_data.find_value_data.value, value);

        N_node my_node = D_search(sklist[MAX_LEVEL - 1].delist, operation_node, 's');
        if (my_node == NULL)
        {
            /**
             * data descp: 说明没有该数据，直接报错返回
             */
            printf("No data's value equals to %s\n", value);
            exit(EXIT_FAILURE);
        }
        N_node node = sklist[0].delist;
        for (int i = 0; i < MAX_LEVEL; i++)
        {
            while (strcmp(node->key, "TAIL"))
            {
                if (strcmp(node->key, my_node->key) == 0)
                {
                    current_pointer_arr[i] = node;
                    break;
                }
                else if (strcmp(node->key, my_node->key) > 0)
                {
                    current_pointer_arr[i] = NULL; // 该层不存在，因为找到比他大的了。
                    break;
                }
                node = node->next;
            }
        }
        return current_pointer_arr;
    }
    return current_pointer_arr;
}

/**
 * func descp: 还是先获取每一层的该数据的前驱节点，直接删除即可！不用管down节点了
 */
S_Status L_delete(L_skipList sklist, O_OPERATION_NODE operation_node)
{
    /**
     * data descp: 先获取每一层的该数据的前驱节点，首先一定要该数据！
     */
    N_node *pre_pointer_arr;

    if (operation_node->operation_node_type == K)
    {
        pre_pointer_arr = pre_pointer_eve_level(sklist, operation_node->operation_node_data->operation_type_key->operation_key_data.insert_key_data.key, NULL, 'k');
        /*强制删除即可*/
        for (int i = 0; i < MAX_LEVEL; i++)
        {
            if (pre_pointer_arr[i] != NULL)
            {
                pre_pointer_arr[i]->next->pre = pre_pointer_arr[i];
                pre_pointer_arr[i]->next = pre_pointer_arr[i]->next->next;
            }
        }
    }
    else if (operation_node->operation_node_type == V)
    {
        pre_pointer_arr = pre_pointer_eve_level(sklist, NULL, operation_node->operation_node_data->operation_type_value->operation_value_data.insert_value_data.value, 'v');
        /*强制删除即可*/
        for (int i = 0; i < MAX_LEVEL; i++)
        {
            if (pre_pointer_arr[i] != NULL)
            {
                pre_pointer_arr[i]->next->pre = pre_pointer_arr[i];
                pre_pointer_arr[i]->next = pre_pointer_arr[i]->next->next;
            }
        }
    }
    return OK;
}

/**
 * func descp: 修改数据，找到每一层的前驱节点，然后直接修改即可！
 */
S_Status L_update(L_skipList sklist, O_OPERATION_NODE operation_node)
{
    /**
     * data descp: 先获取每一层的该数据的前驱节点
     */
    N_node *current_pointer_arr;

    if (operation_node->operation_node_type == K)
    {
        current_pointer_arr = current_pointer_eve_level(sklist, operation_node->operation_node_data->operation_type_key->operation_key_data.insert_key_data.key, NULL, 'k');
        /*修改即可*/
        for (int i = 0; i < MAX_LEVEL; i++)
        {
            if (current_pointer_arr[i] != NULL)
            {
                sprintf(current_pointer_arr[i]->val, operation_node->operation_node_data->operation_type_key->operation_key_data.update_key_data.value);
            }
        }
    }
    else if (operation_node->operation_node_type == V)
    {
        current_pointer_arr = current_pointer_eve_level(sklist, NULL, operation_node->operation_node_data->operation_type_value->operation_value_data.insert_value_data.value, 'v');
        /*修改即可*/
        for (int i = 0; i < MAX_LEVEL; i++)
        {
            if (current_pointer_arr[i] != NULL)
            {
                sprintf(current_pointer_arr[i]->val, operation_node->operation_node_data->operation_type_key->operation_key_data.update_key_data.key);
            }
        }
    }
    return OK;
}