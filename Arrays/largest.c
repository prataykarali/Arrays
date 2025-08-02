#include <stdio.h>

int main() {
    int arr[100];
    int size, i, max;

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

    max = arr[0];
    for (i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    printf("Largest element is: %d\n", max);

    return 0;
}
