#include <stdio.h>

int main() {
    int n, i;
    printf("Enter array size: ");
    scanf("%d", &n);

    if (n < 2) {
        printf("Not enough elements\n");
        return 0;
    }

    int arr[100];
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int first = -1e9, second = -1e9;

    // Find the first and second largest
    for (i = 0; i < n; i++) {
        if (arr[i] > first) {
            second = first;
            first = arr[i];
        } else if (arr[i] > second && arr[i] != first) {
            second = arr[i];
        }
    }

    if (second == -1e9) {
        printf("Second largest does not exist\n");
    } else {
        printf("Second largest element is: %d\n", second);
    }

    return 0;
}
