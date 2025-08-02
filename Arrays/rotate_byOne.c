#include <stdio.h>

void rotate(int arr[], int n) {
    int last = arr[n - 1];

    // Shift all elements to the right
    for (int i = n - 1; i > 0; i--) {
        arr[i] = arr[i - 1];
    }

    // Set first element to last
    arr[0] = last;
}

int main() {
    int n;
    int arr[100]; // max size limit

    printf("Enter array size: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    rotate(arr, n);

    printf("Array after rotation:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
