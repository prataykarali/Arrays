#include <stdio.h>
int isSparse(int matrix[100][100], int rows, int cols) {
    int zero_count = 0;
    int total = rows * cols;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == 0)
                zero_count++;
        }
    }

    return zero_count > (total / 2);
}

int main() {
    int rows, cols;
    int matrix[100][100];

    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);

    printf("Enter %d elements (row-wise):\n", rows * cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    if (isSparse(matrix, rows, cols)) {
        printf("Matrix is Sparse.\n");
    } else {
        printf("Matrix is NOT Sparse.\n");
    }

    return 0;
}