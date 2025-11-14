#include <stdio.h>
#include "vector.h"

int cmp_int(const void *a, const void *b) {
    int ia = *(const int*)a;
    int ib = *(const int*)b;
    if (ia < ib) return -1;
    if (ia > ib) return +1;
    return 0;
}
