#ifndef OPERATION_H_
#define OPERATION_H_

/**
 * data descp: 操作key
 */
typedef struct operation_type_key
{
    enum
    {
        FIND_KEY,
        INSERT_KEY,
        DELETE_KEY,
        UPDATE_KEY,
        INVALID_KEY
    } operation;
    union
    {
        struct find_data_key
        {
            int key;
        } find_data;
        struct insert_data_key
        {
            int key;
            int value;
        } insert_data;
        struct delete_data_key
        {
            int key;
        } delete_data;
        struct update_data_key
        {
            int key;
            int value;
        } update_data;
    } *operation_key_data;

} *OPERATION_TYPE_KEY;

/**
 * data descp: 操作value
 */
typedef struct operation_type_value
{
    enum
    {
        FIND_VALUE,
        INSERT_VALUE,
        DELETE_VALUE,
        UPDATE_VALUE,
        INVALID_VALUE
    } operation;
    union
    {
        struct find_data_value
        {
            int value;
        } find_data;
        struct insert_data_value
        {
            int value;
        } insert_data;
        struct delete_data_value
        {
            int value;
        } delete_data;
        struct update_data_value
        {
            int value;
        } update_data;
    } *operation_value_data;

} *OPERATION_TYPE_VALUE;
/**
 * data descp: 具体操作是哪一种操作，显示(k-v)还是隐式(v)
 */
typedef union operation_node
{
    enum
    {
        KV,
        V,
    } operation_node;
    union
    {
        OPERATION_TYPE_KEY operation_type_key;
        OPERATION_TYPE_VALUE operation_type_value;
    } *operation_node_data;

} *O_OPERATION_NODE;
/*具体的操作=>词法分析、语法分析等*/
S_Status get_operation_node(C_command command, O_OPERATION_NODE operation_node);
O_OPERATION_NODE O_OPERATION_NODE_init(O_OPERATION_NODE o_operation_node);

#endif /* OPERATION_H_ */