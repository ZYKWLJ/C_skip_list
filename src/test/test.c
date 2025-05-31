#include "../../include/include.h"

void statistics(int *total, int arrlen)
{
    if (arrlen <= 0)
    {
        printf("Error: Array length must be a positive integer\n");
        return;
    }

    // Calculate total nodes
    int total_nodes = 0;
    for (int i = 0; i < arrlen; i++)
    {
        if (total[i] < 0)
        {
            printf("Error: Negative node count at level %d\n", i);
            return;
        }
        total_nodes += total[i];
    }

    // Output statistics header
    printf("Level Distribution Statistics (Total nodes: %d, Levels: %d)\n", total_nodes, arrlen);
    printf("Level\tActual Nodes\tTheoretical Nodes(p=0.5)\tAbsolute Error\tRelative Error(%%)\n");

    double chi_square = 0.0;

// #define border
// #ifndef border
    for (int i = 0; i < arrlen; i++)
    {

        int actual = total[i];
        double theoretical = total_nodes * pow(0.5, i + 1); // Theoretical distribution: geometric with p=0.5
        double abs_error = fabs(actual - theoretical);
        double rel_error = (theoretical > 0) ? (abs_error / theoretical * 100) : 0.0;

        // Formatted output (two decimal places)
        printf("%d\t%d\t\t%.2f\t\t\t%.1f\t\t%.2f%%\n",
               i, actual, theoretical, abs_error, rel_error);

        // Calculate chi-square statistic (avoid division by zero)
        if (theoretical > 1e-9)
        { // Minuscule value check
            chi_square += pow(actual - theoretical, 2) / theoretical;
        }
    }
        // Calculate degrees of freedom (assuming only total nodes estimated, not p)
    int degrees_of_freedom = arrlen - 1;
    printf("\nChi-square Statistic: %.2f\tDegrees of Freedom: %d\n", chi_square, degrees_of_freedom);

    // Critical value approximation for significance test (α=0.05)
    printf("Note: Critical value at 0.05 significance level for df=%d is approximately %.2f\n",
           degrees_of_freedom,
           (degrees_of_freedom <= 30) ? 3.84 + (degrees_of_freedom - 1) * 0.5 : // Simplified approximation
               NAN); 


// #else
    // char *level[] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"}; // 层级数

    char *level[12] = {NULL}; // 全部初始化为NULL
    char *node_num[12] = {NULL};
    char *theoretical_node_num_arr[12] = {NULL};
    char *abs_error_arr[12] = {NULL};
    char *rel_error_arr[12] = {NULL};
    // 然后选择性初始化前10个
    for (int i = 0; i < 11; i++)
    {
        level[i] = (string)checked_malloc(2); // 分配足够空间
        sprintf(level[i], "%d", i);           // 复制字符串
        node_num[i] = (string)checked_malloc(20);
        theoretical_node_num_arr[i] = (string)checked_malloc(20);
        abs_error_arr[i] = (string)checked_malloc(20);
        rel_error_arr[i] = (string)checked_malloc(20);
    }


    level[0] = "Level";
    node_num[0] = "Actual Nodes";
    theoretical_node_num_arr[0] = "Theoretical Nodes(p=0.5)";
    abs_error_arr[0] = "Absolute Error(node)";
    rel_error_arr[0] = "Relative Error(%)";

    for (int i = 1; i < arrlen + 1; i++)
    {
        sprintf(node_num[i], "%d", total[i-1]);

        double theoretical = total_nodes * pow(0.5, i); // Theoretical distribution: geometric with p=0.5

        sprintf(theoretical_node_num_arr[i], "%.2f", theoretical);

        double abs_error = fabs(total[i-1] - theoretical);
        sprintf(abs_error_arr[i], "%.1f", abs_error);

        double rel_error = (theoretical > 0) ? (abs_error / theoretical * 100) : 0.0;
        sprintf(rel_error_arr[i], "%.2f%%", rel_error);

        // Calculate chi-square statistic (avoid division by zero)
        if (theoretical > 1e-9)
        { // Minuscule value check
            chi_square += pow(total[i-1] - theoretical, 2) / theoretical;
        }
    }

    char **data_arr[] = {level, node_num, theoretical_node_num_arr, abs_error_arr, rel_error_arr};
    text_print_head1_blank1(data_arr, sizeof(data_arr) / sizeof(data_arr[0]));

// #endif

    // Calculate degrees of freedom (assuming only total nodes estimated, not p)
    // int degrees_of_freedom = arrlen - 1;
    printf("\nChi-square Statistic: %.2f\tDegrees of Freedom: %d\n", chi_square, degrees_of_freedom);

    // Critical value approximation for significance test (α=0.05)
    printf("Note: Critical value at 0.05 significance level for df=%d is approximately %.2f\n",
           degrees_of_freedom,
           (degrees_of_freedom <= 30) ? 3.84 + (degrees_of_freedom - 1) * 0.5 : // Simplified approximation
               NAN);                                                            // Use normal distribution for df>30
}