#ifndef SKIPLIST_H_
#define SKIPLIST_H_
#if 0
typedef struct skipList_
{
    D_delist delist;
} * L_skipList;

#endif
typedef struct skipList_
{
    D_delist delist; /*这是实现核心，完成二维织网的核心*/
} *L_skipList;

L_skipList L_skipList_init(L_skipList sklist);
void L_print_skiplist(L_skipList sklist);
S_Status L_search(L_skipList sklist, O_OPERATION_NODE operation_node);
S_Status L_insert(L_skipList sklist, O_OPERATION_NODE operation_node);
S_Status L_delete(L_skipList sklist, O_OPERATION_NODE operation_node);
S_Status L_update(L_skipList sklist, O_OPERATION_NODE operation_node);
#endif /* SKIPLIST_H_ */