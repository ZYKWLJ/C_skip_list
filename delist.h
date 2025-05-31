/**
 * filename:delist.c
 * description: 双向链表C语言实现
 * author:EthanYankang
 * create time:2025/05/30 13:59:09
 */
#include "utils.h"
#ifndef DELIST_H_
#define DELIST_H_
#include <string.h>
#include <time.h>
typedef char *string;
typedef struct node_
{
    struct node_ *pre;
    struct node_ *next;
    int key;
    string val;
} *N_node;

/**
 * data descp: 双向链表只记录两边就可以了
 */
typedef struct delist_
{
    N_node L;
    N_node R;
    // N_node
} *D_delist;

typedef struct skipList_
{
    D_delist delist; // 本身具有横向功能

} *L_skipList;

typedef enum Status_
{
    OK,
    ERROR,
    NOT_EXIST,
} S_Status;

D_delist D_init_list(D_delist list);
N_node D_init_node(N_node node);
void D_print_list(D_delist list);
S_Status D_search(D_delist list, string val);
S_Status D_insert(D_delist list, string val);
S_Status D_delete(D_delist list, string val);
// S_Status D_delete(D_delist list,int val);

#endif /* DELIST_H_ */

/*
1                            10
1      2                     10
1      2  3                  10
1      2  3  4               10

每一级节点，如果后面的节点key比目标的节点小，那么就后移，如果比目标的key大，那么就下沉。
直至下沉到到最底层。还是没有就说明不存在数据库中。


*/