#include "../include/include.h"
L_skip_list skip_list;
INSERT_ON_ODD_SHOW insert_on_or_show = INSERT_OFF;
SEARCH_ON_ODD_SHOW search_on_or_show = SEARCH_ON;

int main(int argc, char *argv[])
{
    LOG_PRINT("test main......");
    skip_list = L_skip_list_init();
    LOG_PRINT("L_skip_list_init over......");
    read_data_from_disk(get_appdata_path(DATE_FILE), skip_list);
    insert_on_or_show = INSERT_ON;
    O_OPERATION_NODE operation_node = O_OPERATION_NODE_init(NULL);
    LOG_PRINT("operation_init over......");

    C_command command = C_command_init(NULL, argc, argv);
    P_parser(command, operation_node);
    LOG_PRINT("parser over......");

    L_E_exec(skip_list, operation_node);
    LOG_PRINT("test main over......");
    // L_skip_list_print(skip_list);
    save_data_to_disk(get_appdata_path(DATE_FILE), skip_list);
    return 0;
}