/* vector.h */
#ifndef VECTOR_H
#define VECTOR_H

#include <stdlib.h>
#include <string.h>
#include <assert.h>

/*
  Makro do deklarowania typu vector dla typu T.
  Po użyciu: VECTOR_DECLARE(int); → definiuje typ vector_int
*/
#define VECTOR_DECLARE(T)                                                  \
    typedef struct {                                                       \
        T *data;                                                           \
        size_t size;                                                       \
        size_t capacity;                                                   \
    } vector_##T;                                                          \
                                                                           \
    static inline void vector_##T##_init(vector_##T *v) {                  \
        v->data = NULL;                                                    \
        v->size = 0;                                                       \
        v->capacity = 0;                                                   \
    }                                                                      \
                                                                           \
    static inline void vector_##T##_free(vector_##T *v) {                  \
        free(v->data);                                                     \
        v->data = NULL;                                                    \
        v->size = 0;                                                       \
        v->capacity = 0;                                                   \
    }                                                                      \
                                                                           \
    static inline void vector_##T##_reserve(vector_##T *v, size_t newcap) {\
        if (newcap > v->capacity) {                                        \
            T *newdata = (T*) realloc(v->data, newcap * sizeof(T));        \
            if (!newdata) {                                                \
                fprintf(stderr, "vector: allocation failed\n");            \
                exit(EXIT_FAILURE);                                        \
            }                                                              \
            v->data = newdata;                                             \
            v->capacity = newcap;                                          \
        }                                                                  \
    }                                                                      \
                                                                           \
    static inline void vector_##T##_push_back(vector_##T *v, T value) {    \
        if (v->size == v->capacity) {                                      \
            size_t newcap = v->capacity ? v->capacity * 2 : 4;             \
            vector_##T##_reserve(v, newcap);                               \
        }                                                                  \
        v->data[v->size++] = value;                                        \
    }                                                                      \
                                                                           \
    static inline void vector_##T##_pop_back(vector_##T *v) {              \
        assert(v->size > 0);                                               \
        v->size--;                                                         \
    }                                                                      \
                                                                           \
    static inline T *vector_##T##_at(vector_##T *v, size_t idx) {          \
        assert(idx < v->size);                                             \
        return &v->data[idx];                                              \
    }                                                                      \
                                                                           \
    static inline size_t vector_##T##_size(vector_##T *v) {                \
        return v->size;                                                    \
    }                                                                      \
                                                                           \
    static inline size_t vector_##T##_capacity(vector_##T *v) {            \
        return v->capacity;                                                \
    }                                                                      \
                                                                           \
    /* Sortowanie z opcjonalnym zakresem i kierunkiem (rosnąco/malejąco) */ \
    static inline void vector_##T##_sort(vector_##T *v, size_t start, size_t end, int (*cmp)(const void *, const void *), int ascending) { \
    if (start == SIZE_MAX && end == SIZE_MAX) { \
        start = 0; \
        end = v->size; \
    } \
    assert(start < end && end <= v->size); \
    \
    if (!ascending) { \
        int reversed_cmp(const void *a, const void *b) { \
            return -cmp(b, a); \
        } \
        cmp = reversed_cmp; \
    } \
    \
    qsort(&v->data[start], end - start, sizeof(T), cmp); \
    } \

#endif /* VECTOR_H */
