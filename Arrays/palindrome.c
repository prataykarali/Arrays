#include <stdio.h>
#include <stdbool.h>

bool isPalindrome(int arr[], int size) {
    for (int i = 0; i < size / 2; i++) {
        if (arr[i] != arr[size - 1 - i]) {
            return false;
        }
    }
    return true;
}

int main() {
    int arr[100], size;

    printf("Enter array size: ");
    scanf("%d", &size);

    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    if (isPalindrome(arr, size)) {
        printf("Palindrome ?\n");
    } else {
        printf("Not a Palindrome ?\n");
    }

    return 0;
}
