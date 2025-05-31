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
    } operation_key;
    union
    {
        struct
        {
            char key[10000];
        } find_key_data;
        struct
        {
            char key[10000];
            char value[10000];
        } insert_key_data;
        struct
        {
            char key[10000];
        } delete_key_data;
        struct
        {
            char key[10000];
            char value[10000];
        } update_key_data;
    } operation_key_data;

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
    } operation_value;
    union
    {
        struct
        {
            char value[10000];
        } find_value_data;
        struct
        {
            char value[10000];
        } insert_value_data;
        struct
        {
            char value[10000];
        } delete_value_data;
        struct
        {
            char value[10000];
        } update_value_data;
    } operation_value_data;

} *OPERATION_TYPE_VALUE;
/**
 * data descp: 具体操作是哪一种操作，显示(k-v)还是隐式(v)
 */
typedef struct operation_node
{
    enum
    {
        K,
        V,
    } operation_node_type;

    union node_data
    {
        OPERATION_TYPE_KEY operation_type_key;
        OPERATION_TYPE_VALUE operation_type_value;
    } *operation_node_data;

} *O_OPERATION_NODE;
/*具体的操作=>词法分析、语法分析等*/
S_Status P_parser(C_command command, O_OPERATION_NODE operation_node);
O_OPERATION_NODE O_OPERATION_NODE_init(O_OPERATION_NODE o_operation_node);

#endif /* OPERATION_H_ */