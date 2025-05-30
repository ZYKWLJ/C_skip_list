#include "utils.h"

void *checked_malloc(size_t len)
{
    void *p = calloc(1, len); // 分配len这么大小的空间，并初始化为0
    if (!p)
    {
        fprintf(stderr, "failed to calloc\n");
        exit(EXIT_FAILURE);
    }
    return p;
}
