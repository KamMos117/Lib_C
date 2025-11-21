#include <stdio.h>
#include "vector.h"

VECTOR_DECLARE(int);

int cmp_int(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    vector_int v;
    vector_int_init(&v);

    int n = 0, i;
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        int input;
        scanf("%d", &input);
        vector_int_push_back(&v,input);
    }

    //vector_int_sort(&v, 0, 4, cmp_int, 1);

    //for (size_t i = 0; i < vector_int_size(&v); ++i)
    //{
    //    printf("%d ", *vector_int_at(&v, i));
    //}
    //printf("\n");

    //vector_int_sort(&v, SIZE_MAX, SIZE_MAX, cmp_int, 1);

    //for (size_t i = 0; i < vector_int_size(&v); ++i)
    //{
    //    printf("%d ", *vector_int_at(&v, i));
    //}
    //printf("\n");    

    vector_int_sort(&v, SIZE_MAX, SIZE_MAX, cmp_int, 0);

    
    for (size_t i = 0; i < vector_int_size(&v); ++i)
    {
        printf("%d", *vector_int_at(&v, i));
    }
    printf("\n");

    vector_int_free(&v);
}
