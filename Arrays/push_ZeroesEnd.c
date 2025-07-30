#include <stdio.h>

int main() {
    int arr[100];
    int size, i, count = 0;

    printf("Enter array size: ");
    scanf("%d", &size);

    if (size <= 0 || size > 100) {
        printf("Invalid array size!\n");
        return 1;
    }

    printf("Enter %d elements:\n", size);
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Move non-zero elements to the front
    for (i = 0; i < size; i++) {
        if (arr[i] != 0) {
            arr[count++] = arr[i];
        }
    }

    // Fill remaining positions with zeros
    while (count < size) {
        arr[count++] = 0;
    }

    // Output result
    printf("Array after pushing zeros to end:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
