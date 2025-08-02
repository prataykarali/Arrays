#include <stdio.h>

int countZeroes(int a[][100], int n) {
    int row = 0, col = n - 1;
    int count = 0;
    while (row < n && col >= 0) {
        if (a[row][col] == 0) {
            count += (col + 1);
            row++;
        } else {
            col--;
        }
    }
    return count;
}

int main() {
    int n;
    printf("Enter the size of the matrix (n x n): ");
    scanf("%d", &n);

    int a[100][100];

    printf("Enter the matrix elements (0 or 1 only):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    int result = countZeroes(a, n);
    printf("Number of 0s in the matrix: %d\n", result);

    return 0;
}
