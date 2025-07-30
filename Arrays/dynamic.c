#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *array;
    int count;
    int size;
} DynamicArray;

// Initialize dynamic array
void init(DynamicArray *da) {
    da->size = 1;
    da->count = 0;
    da->array = (int *)malloc(sizeof(int) * da->size);
}

// Resize array to new size
void resize(DynamicArray *da, int new_size) {
    da->array = (int *)realloc(da->array, sizeof(int) * new_size);
    int i;
    for (i = da->size; i < new_size; i++) {
        da->array[i] = 0;
    }
    da->size = new_size;
}

// Add element at end
void add(DynamicArray *da, int data) {
    if (da->count == da->size) {
        resize(da, da->size * 2);
    }
    da->array[da->count++] = data;
}

// Shrink size to match count
void shrink(DynamicArray *da) {
    da->array = (int *)realloc(da->array, sizeof(int) * da->count);
    da->size = da->count;
}

// Add element at specific index
void add_at(DynamicArray *da, int index, int data) {
    if (index < 0 || index > da->count) {
        printf("Invalid index!\n");
        return;
    }

    if (da->count == da->size) {
        resize(da, da->size * 2);
    }
    int i;
    for (i = da->count; i > index; i--) {
        da->array[i] = da->array[i - 1];
    }

    da->array[index] = data;
    da->count++;
}

// Remove last element
void remove_last(DynamicArray *da) {
    if (da->count > 0) {
        da->count--;
        da->array[da->count] = 0;
    }
}

// Remove element at index
void remove_at(DynamicArray *da, int index) {
    if (index < 0 || index >= da->count) {
        printf("Invalid index!\n");
        return;
    }
    int i;
    for (i = index; i < da->count - 1; i++) {
        da->array[i] = da->array[i + 1];
    }

    da->array[da->count - 1] = 0;
    da->count--;
}

// Print all elements
void print_all(DynamicArray *da) {
    printf("Array: ");
    int i;
    for (i = 0; i < da->size; i++) {
        printf("%d ", da->array[i]);
    }
    printf("\nCount: %d, Size: %d\n", da->count, da->size);
}

// Free memory
void free_array(DynamicArray *da) {
    free(da->array);
    da->array = NULL;
    da->size = 0;
    da->count = 0;
}

// Main to test
int main() {
    DynamicArray da;
    init(&da);
    int i;
    for (i = 1; i < 10; i++) {
        add(&da, i);
    }
    print_all(&da);

    shrink(&da);
    print_all(&da);

    add_at(&da, 1, 22);
    print_all(&da);

    remove_last(&da);
    print_all(&da);

    remove_at(&da, 1);
    print_all(&da);

    free_array(&da);
    return 0;
}
