#include <stdio.h>

int main() {
    int n, i, j, sum = 0;
    int matrix[100][100];

    // Input matrix size
    printf("Enter size of square matrix (n x n): ");
    scanf("%d", &n);

    // Input matrix elements
    printf("Enter elements of the matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    // Sum main diagonal elements
    for (i = 0; i < n; i++) {
        sum += matrix[i][i];  // main diagonal: row == column
    }

    // Output result
    printf("Sum of main diagonal elements: %d\n", sum);
    return 0;
}
