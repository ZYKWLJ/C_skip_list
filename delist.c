#include "delist.h"
N_node D_init_node(N_node node)
{
    N_node ret = (N_node)checked_malloc(sizeof(*node));
    ret->val = 0;
    ret->next = NULL;
    ret->pre = NULL;
    return ret;
}

D_delist D_init_list(D_delist list)
{
    D_delist ret = (D_delist)checked_malloc(sizeof(*list));
    ret->L = D_init_node(NULL);
    ret->R = D_init_node(NULL);
    ret->L->pre = NULL;
    ret->L->next = ret->R;
    ret->L->val = -1; // 首
    ret->R->pre = ret->L;
    ret->R->next = NULL;
    ret->R->val = -2; // 尾
    return ret;
}

void D_print_list(D_delist list)
{
    N_node node = list->L->next;
    printf("begin->");
    while (node->val != -2)
    {
        printf("%d->", node->val);
        node = node->next;
    }
    printf("end\n");
}

S_Status D_search(D_delist list, int val)
{
    // LOG_PRINT("begin search %d", val);
    N_node node = list->L->next;
    int pos = 0;
    while (node->val != -2)
    {
        // LOG_PRINT("node val: %d", node->val);
        pos++;
        if (node->val == val)
        {
            printf("find in val %d in delist, pos:%d\n", val, pos);
        }
        node = node->next;
    }
    // LOG_PRINT("end search %d", val);

    return OK;
}

S_Status D_insert(D_delist list, int val)
{
    // 先默认插入尾部吧
    N_node node = D_init_node(NULL);
    node->val = val;
    N_node pre = list->R->pre;
    pre->next = node;
    node->pre = pre;
    node->next = list->R;
    list->R->pre = node;
    printf("value %d inserted!\n", val);
    return OK;
}

S_Status D_delete(D_delist list, int val)
{

    return OK;
}
