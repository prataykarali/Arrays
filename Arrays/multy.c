#include <stdio.h>

void multiplyPolynomials(int A[], int degA, int B[], int degB, int result[]) {
    for (int i = 0; i <= degA + degB; i++)
        result[i] = 0;  // Initialize result array with 0

    for (int i = 0; i <= degA; i++) {
        for (int j = 0; j <= degB; j++) {
            result[i + j] += A[i] * B[j];
        }
    }
}

void inputPolynomial(int poly[], int degree, char name) {
    printf("Enter %d coefficients for Polynomial %c (from constant to x^%d):\n", degree + 1, name, degree);
    for (int i = 0; i <= degree; i++) {
        printf("Coefficient of x^%d: ", i);
        scanf("%d", &poly[i]);
    }
}

void printPolynomial(int poly[], int degree) {
    for (int i = degree; i >= 0; i--) {
        if (poly[i] != 0) {
            if (i != degree && poly[i] > 0)
                printf(" + ");
            if (i == 0)
                printf("%d", poly[i]);
            else if (i == 1)
                printf("%dx", poly[i]);
            else
                printf("%dx^%d", poly[i], i);
        }
    }
    printf("\n");
}

int main() {
    int A[100], B[100], result[200];
    int degA, degB;

    printf("Enter degree of Polynomial A: ");
    scanf("%d", &degA);
    inputPolynomial(A, degA, 'A');

    printf("Enter degree of Polynomial B: ");
    scanf("%d", &degB);
    inputPolynomial(B, degB, 'B');

    multiplyPolynomials(A, degA, B, degB, result);

    printf("\nPolynomial A: ");
    printPolynomial(A, degA);

    printf("Polynomial B: ");
    printPolynomial(B, degB);

    printf("Product of A and B: ");
    printPolynomial(result, degA + degB);

    return 0;
}
