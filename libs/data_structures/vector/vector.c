#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "vector.h"

vector createVector(size_t capacity) {
    int *data = (int*) malloc(capacity * sizeof(int));
    if (data == NULL) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }
    return (vector) {data, 0, capacity};
}

void reserve(vector *v, size_t newCapacity) {
    int *data = (int*) realloc(v->data, newCapacity * sizeof(int));
    if (data == NULL) {
        v->data = NULL;
        fprintf(stderr, "bad alloc");
        exit(1);
    }

    v->data = data;

    v->capacity = newCapacity;

    if (v->size > v->capacity) {
        v->size = newCapacity;
    }
}

void clear(vector *v) {
    v->size = 0;
}

void shrinkToFit(vector *v) {
    v->capacity = v->size;
}

void deleteVector(vector *v) {
    free(v->data);
    v->data = NULL;
    v->size = 0;
    v->capacity = 0;
}

bool isEmpty(vector *v) {
    return v->size == 0;
}

bool isFull(vector *v) {
    return v->size == v->capacity;
}

int getVectorValue(vector *v, size_t i) {
    return v->data[i];
}

void pushBack(vector *v, int x) {
    if (v->size + 1 > v->capacity) {
        reserve(v, v->size * 2);
    }
    v->data[v->size++] = x;
}

void popBack(vector *v) {
     if (v->size == 0) {
         fprintf(stderr, "bad alloc");
         exit(1);
     }
     v->size--;
}
