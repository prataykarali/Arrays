#include <stdio.h>
#include <stdbool.h>

// Function to check if matrix is identity
bool is_identity(int matrix[100][100], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if ((i == j && matrix[i][j] != 1) || (i != j && matrix[i][j] != 0)) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int n;
    int matrix[100][100];

    printf("Enter size of square matrix: ");
    scanf("%d", &n);

    printf("Enter matrix row by row:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    if (is_identity(matrix, n)) {
        printf("Identity Matrix ?\n");
    } else {
        printf("Not an Identity Matrix ?\n");
    }

    return 0;
}
