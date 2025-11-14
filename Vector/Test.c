#include <stdio.h>
#include "vector.h"

VECTOR_DECLARE(int);

int cmp_int(const void *a, const void *b) {
    int ia = *(const int*)a;
    int ib = *(const int*)b;
    if (ia < ib) return -1;
    if (ia > ib) return +1;
}

int main(void)
{
    int input = 0, n, i;

    scanf("%d", &n);

    vector_int vec;
    vector_int_init(&vec);

    for(i = 0; i < n;i++)
    {
        scanf("%d", &input);
        vector_int_push_back(&vec,input);
    }

    printf("Przed sortowaniem: ");
    for (size_t i = 0; i < vector_int_size(&vec); i++) {
        printf("%d ", *vector_int_at(&vec, i));
    }
    printf("\n");

    vector_int_sort(&vec, cmp_int);

    printf("Po sortowaniu: ");
    for (size_t i = 0; i < vector_int_size(&vec); i++) {
        printf("%d ", *vector_int_at(&vec, i));
    }
    printf("\n");

    vector_int_free(&vec);
}