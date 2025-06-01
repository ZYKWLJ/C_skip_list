/**
 * filename:delist.c
 * description: 双向链表C语言实现
 * author:EthanYankang
 * create time:2025/05/30 13:59:09
 */
// #include "utils.h"
#include "../include.h"
#ifndef DELIST_H_
#define DELIST_H_
#include <string.h>
#include <time.h>
typedef char *string;
#define MAX_LEVEL 10 // 最大层级数

/*每一个节点就是一个网络点，有上下左右的四个触手*/
typedef struct node_
{
    struct node_ *pre;
    struct node_ *next;
    struct node_ *down; // 向下的指针，//不需要了，因为只要双向链表数组就可以实现网了
    string key;
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

N_node N_init_node(N_node node);
void N_print_node(N_node node);

D_delist D_init_delist(D_delist delist);
void D_print_delist(D_delist delist);
// S_Status D_search(D_delist delist, O_OPERATION_NODE operation_node, char mod /*是search还是其他借用*/);
N_node D_search(D_delist delist, O_OPERATION_NODE operation_node, char mod /*是search还是其他借用*/);
// S_Status D_insert(D_delist delist, O_OPERATION_NODE operation_node);
N_node D_insert(D_delist delist, O_OPERATION_NODE operation_node);
S_Status D_delete(D_delist delist, O_OPERATION_NODE operation_node);
S_Status D_update(D_delist delist, O_OPERATION_NODE operation_node);

// S_Status D_delete(D_delist list,int val);

int D_get_random_level();

#endif /* DELIST_H_ */

/*
1                     6       10
1      2              6       10
1      2  3           6       10
1      2  3  5        6       10

每一级节点，如果后面的节点key比目标的节点小，那么就后移，如果比目标的key大，那么就下沉。
直至下沉到到最底层。还是没有就说明不存在数据库中。

插入：找到数据的层级，然后对这个层级之下的所有层，找到第一个比该数据key大的数，在他的前面插入，如果没有，就在末尾插入。
查找：从第一层开始，如果后面的节点key比目标的节点小，那么就后移，如果比目标的key大，那么就下沉。直至下沉到到最底层。还是没有就说明不存在数据库中。
删除：先查找数据的层级，然后删除这个层级之下的所有层的该数据(下面所有层级都有)。
修改：先查找数据的层级，然后修改这个层级之下的所有层的该数据(下面所有层级都有)。
打印：下沉到第一层，直接打印数据。

// 所有本质上来说，只有从上往下的指针，没有从下往上的指针，并且数据量巨大时，指针也挺耗费内存，不值得。

如果要打印全部数据的话，就直接跳转到第一层，直接打印就好了！

*/