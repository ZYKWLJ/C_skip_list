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
 * func descp: 跳表初始化
 */
L_skipList L_skipList_init(L_skipList sklist)
{
    L_skipList ret = (L_skipList)checked_malloc(sizeof(*sklist) * MAX_LEVEL); // 这么多个层级的双向链表联结
    /*把每一层都初始化好了*/
    for (int i = 0; i < MAX_LEVEL; i++)
    {
        ret[i].delist = D_init_delist(NULL);
    }
    /*再把每一层都连接起来(通过down指针)*/
    for (int i = 0; i < MAX_LEVEL - 1; i++)
    {
        ret[i].delist->L->down = ret[i + 1].delist->L;
        ret[i].delist->R->down = ret[i + 1].delist->R;
    }
    ret[MAX_LEVEL - 1].delist->L->down = NULL;
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
S_Status L_search(L_skipList sklist, string val)
{
    N_node node = sklist[0].delist->L;
    for (int i = 0; i < MAX_LEVEL; i++)
    {
        node = sklist[i].delist->L;
        int pos = 0;
        while (strcmp(node->key, "TAIL") == 0)
        {
            pos++;
            if (strcmp(val, node->key) == 0)
            {
                printf("find in val %s in sklist, level:%d, pos:%d\n", val, i, pos);
                return OK;
            }
            /*说明本层太稀疏，数据在下一层*/
            else if (strcmp(val, node->key) > 0)
            {
                /*先往前回跳一格，再往下*/
                node = node->pre;
                node = node->down;
            }
            /*否则就是还可以本层往后查找*/
        }
    }
    printf("not find in val %s in sklist\n", val);
    return OK;
}

S_Status L_insert(L_skipList sklist, string val)
{
    /**
     * data descp: 获取随机层级
     */
    int level = D_get_random_level();
    /*随机层级以下的全部都有该数据*/
    for (int i = 0; i < level; i++){
        

    }
    return OK;
}

S_Status L_delete(L_skipList sklist, string val)
{
    return OK;
}
