#include "../../include/include.h"
// #include "exec.h"
/*那么这里注定了需要有两个文件保存k-v和v两种数据*/
S_Status D_E_exec(D_delist delist, O_OPERATION_NODE operation_node)
{
    LOG_PRINT("type:%d\n", operation_node->operation_node_type);
    switch (operation_node->operation_node_type)
    {
    case K:
        TODO_PRINT("Exec type key");
        LOG_PRINT("%d", operation_node->operation_node_data->operation_type_key->operation_key);
        switch (operation_node->operation_node_data->operation_type_key->operation_key)
        {
            TODO_PRINT("Exec  key");
        case FIND_KEY:
            TODO_PRINT("Exec find key:%s", operation_node->operation_node_data->operation_type_key->operation_key_data.find_key_data.key);
            D_search(delist, operation_node);
            /* code */
            break;
        case INSERT_KEY:
            TODO_PRINT("Exec insert [key:%s,value:%s]", operation_node->operation_node_data->operation_type_key->operation_key_data.insert_key_data.key, operation_node->operation_node_data->operation_type_key->operation_key_data.insert_key_data.value);
            D_insert(delist, operation_node);
            /* code */
            break;
        case DELETE_KEY:
            TODO_PRINT("Exec delete key");
            TODO_PRINT("Exec delete key:%s", operation_node->operation_node_data->operation_type_key->operation_key_data.delete_key_data.key);
            D_delete(delist, operation_node);
            /* code */
            break;
        case UPDATE_KEY:
            TODO_PRINT("Exec update key");
            TODO_PRINT("Exec insert [key:%s,value:%s]", operation_node->operation_node_data->operation_type_key->operation_key_data.update_key_data.key, operation_node->operation_node_data->operation_type_key->operation_key_data.update_key_data.value);
            D_update(delist, operation_node);
            /* code */
            break;
        }
        break;

    case V:
        TODO_PRINT("Exec type value");

        switch (operation_node->operation_node_data->operation_type_value->operation_value)
        {
        case FIND_VALUE:
            TODO_PRINT("Exec find value:%s", operation_node->operation_node_data->operation_type_value->operation_value_data.find_value_data.value);
            D_search(delist, operation_node);
            /* code */
            break;
        case INSERT_VALUE:
            TODO_PRINT("Exec insert [key:rand(),value:%s]", operation_node->operation_node_data->operation_type_value->operation_value_data.insert_value_data.value);
            D_insert(delist, operation_node);
            /* code */
            break;
        case DELETE_VALUE:
            TODO_PRINT("Exec delete value");
            TODO_PRINT("Exec delete value:%s", operation_node->operation_node_data->operation_type_value->operation_value_data.delete_value_data.value);
            D_delete(delist, operation_node);
            /* code */
            break;
        }
        break;
    }
    TODO_PRINT("Exec over");

    return OK;
}

S_Status L_E_exec(L_skipList skiplist, O_OPERATION_NODE operation_node)
{
    return OK;
}
