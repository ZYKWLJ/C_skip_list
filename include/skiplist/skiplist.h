#ifndef SKIPLIST_H_
#define SKIPLIST_H_
/**
 * data descp: 跳表节点结构
 */

/*
前向指针：

每个节点包含1到MAX_LEVEL个前向指针
forward[1]指向最底层(第1层)的下一个节点
forward[2]指向第2层的下一个节点
...
forward[n]指向第n层的下一个节点

Level 3: 1 ----------------------------> 9
Level 2: 1 --------> 5 --------> 9
Level 1: 1 -> 3 -> 5 -> 7 -> 9

如图：
节点1的forward[1]指向3，forward[2]指向5，forward[3]指向9
节点5的forward[1]指向7，forward[2]指向9

*/
#define MAX_LEVEL 16
typedef char *string;
typedef struct skip_node
{
    string key;   // 键值
    string value; // 存储的值
    // 前向指针数组(使得每个跳表节点具有二维性，其值该元素在每一层的下一个元素，那显然是一个指针数组，保存这每一层的下一个节点指针)
    struct skip_node **forward;

} *N_skip_node;

/**
 * data descp: 跳表结构
 */
typedef struct skip_list
{
    int level;          // 当前层数
    int size;           // 节点数量
    N_skip_node header; // 头节点
} *L_skip_list;

/**
 * data descp: 数据操作模式，这里使用枚举，两种数据用一个表存储，那么就得给key默认值。
 */
typedef enum MOD_
{
    K,
    V
} MOD;
#if 0
/*这就是完备集合了，不用搞这么复杂*/
S_Status func(L_skipList sklist, string key, string value);

#endif
/*初始化跳表节点*/
N_skip_node N_skip_node_init(int level, string key, string value);
/*初始化跳表*/
L_skip_list L_skip_list_init();
/*随机层数算法*/
int random_level();
typedef enum INSERT_ON_ODD_SHOW_
{
    INSERT_ON,
    INSERT_OFF
} INSERT_ON_ODD_SHOW;
/*插入节点*/
void L_skip_list_insert(L_skip_list list, string key, string value);
/*查找节点,返回节点*/
typedef enum SEARCH_ON_ODD_SHOW_
{
    SEARCH_ON,
    SEARCH_OFF
} SEARCH_ON_ODD_SHOW;
N_skip_node L_skip_list_search(L_skip_list list, string key, string value);
/*修改节点值*/
void L_skip_list_update(L_skip_list list, string key, string new_value);
/*删除节点*/
void L_skip_list_delete(L_skip_list list, string key, string value);

/*打印调表*/
void L_skip_list_print(L_skip_list list);
#endif /* SKIPLIST_H_ */