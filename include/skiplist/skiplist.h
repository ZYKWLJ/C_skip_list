#ifndef SKIPLIST_H_
#define SKIPLIST_H_
typedef struct skipList_
{
    D_delist delist;
} *L_skipList;


L_skipList L_skipList_init(L_skipList sklist);
void L_print_skiplist(L_skipList sklist);
S_Status L_search(L_skipList sklist, string key);
S_Status L_insert(L_skipList sklist, string key);
S_Status L_delete(L_skipList sklist, string key);
#endif /* SKIPLIST_H_ */