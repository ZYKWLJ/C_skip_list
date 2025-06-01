#include "../../include/include.h"

S_Status L_E_exec(L_skip_list skiplist, O_OPERATION_NODE operation_node)
{
    LOG_PRINT("type:%d\n", operation_node->operation_node_type);
    switch (operation_node->operation_node_type)
    {
    case FIND:
        /* code */
        L_skip_list_search(skiplist, operation_node->key, NULL);
        break;
    case INSERT:
        /* code */
        LOG_PRINT("insert\tkey:%s\tvalue:%s\n", operation_node->key, operation_node->value);
        L_skip_list_insert(skiplist, operation_node->key, operation_node->value);
        break;
    case DELETE:
        /* code */
        L_skip_list_delete(skiplist, operation_node->key, NULL);
        break;
    case UPDATE:
        /* code */
        L_skip_list_update(skiplist, operation_node->key, operation_node->value);
        break;
    default:
        break;
    }
    TODO_PRINT("Exec over");
    return OK;
}
