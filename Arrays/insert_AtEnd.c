#include <stdio.h>

int main() {
    int arr[100]; // maximum capacity
    int size, i, val;

    printf("Enter array size: ");
    scanf("%d", &size);

    if (size < 0 || size > 100) {
        printf("Invalid size!\n");
        return 1;
    }

    printf("Enter %d elements:\n", size);
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter value to insert at end: ");
    scanf("%d", &val);

    // Insert at end
    arr[size] = val;
    size++;

    printf("Updated array:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
