#include <stdio.h>
#include <stdlib.h>

// Function to read polynomial coefficients
void inputPolynomial(int *coeff, int degree, char name) {
    printf("Enter %d coefficients for polynomial %c (from constant term):\n", degree + 1, name);
    for (int i = 0; i <= degree; i++) {
        scanf("%d", &coeff[i]);
    }
}

// Function to add two polynomials
void addPolynomials(int *A, int degA, int *B, int degB, int *result, int *degResult) {
    int maxDeg = (degA > degB) ? degA : degB;
    *degResult = maxDeg;

    for (int i = 0; i <= maxDeg; i++) {
        int coeffA = (i <= degA) ? A[i] : 0;
        int coeffB = (i <= degB) ? B[i] : 0;
        result[i] = coeffA + coeffB;
    }
}

// Function to print polynomial
void printPolynomial(int *poly, int degree) {
    int printed = 0;
    for (int i = degree; i >= 0; i--) {
        if (poly[i] == 0) continue;

        if (printed) printf(" + ");

        if (i == 0)
            printf("%d", poly[i]);
        else if (i == 1)
            printf("%dx", poly[i]);
        else
            printf("%dx^%d", poly[i], i);

        printed = 1;
    }

    if (!printed) printf("0"); // If all coefficients are 0
    printf("\n");
}

int main() {
    int degA, degB, maxDeg;
    int A[100], B[100], result[100];

    printf("Polynomial Addition Program\n");

    // Input polynomial A
    printf("Enter the degree of polynomial A: ");
    scanf("%d", &degA);
    inputPolynomial(A, degA, 'A');

    // Input polynomial B
    printf("Enter the degree of polynomial B: ");
    scanf("%d", &degB);
    inputPolynomial(B, degB, 'B');

    // Add and print result
    int degResult;
    addPolynomials(A, degA, B, degB, result, &degResult);

    printf("Sum of polynomials (coefficients): ");
    for (int i = 0; i <= degResult; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    printf("Polynomial form: ");
    printPolynomial(result, degResult);

    return 0;
}
