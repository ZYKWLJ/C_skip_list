#ifndef OPERATION_H_
#define OPERATION_H_
#include "../include.h"

/**
 * data descp: 操作类型+k-v(默认为NULL)就完了
 */
typedef struct operation_node
{
    enum
    {
        FIND,
        INSERT,
        DELETE,
        UPDATE,
    } operation_node_type;
    string key;
    string value;
} *O_OPERATION_NODE;
/*具体的操作=>词法分析、语法分析等*/
S_Status P_parser(C_command command, O_OPERATION_NODE operation_node);
O_OPERATION_NODE O_OPERATION_NODE_init(O_OPERATION_NODE o_operation_node);

#endif /* OPERATION_H_ */