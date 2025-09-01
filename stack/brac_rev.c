#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to count minimum reversals for one bracket type
int countMinReversals(const char *expr, char openBr, char closeBr) {
    int n = strlen(expr);
    if (n % 2 != 0) return -1; // Odd length can't be balanced

    char *stack = (char *)malloc(n);
    int top = -1;

    // Process expression
    for (int i = 0; i < n; i++) {
        char ch = expr[i];
        if (ch == closeBr && top >= 0 && stack[top] == openBr) {
            top--; // pop matched pair
        } else {
            stack[++top] = ch; // push
        }
    }

    int unbalanced_len = top + 1;
    int opening_count = 0;

    for (int i = 0; i <= top; i++) {
        if (stack[i] == openBr) opening_count++;
    }

    free(stack);

    return (unbalanced_len / 2) + (opening_count % 2);
}

// Function to calculate total reversals for {}, [], ()
int minReversalsAll(const char *expr) {
    char curly[1000] = {0}, square[1000] = {0}, roundb[1000] = {0};
    int c = 0, s = 0, r = 0;

    // Separate brackets by type
    for (int i = 0; expr[i]; i++) {
        if (expr[i] == '{' || expr[i] == '}') curly[c++] = expr[i];
        if (expr[i] == '[' || expr[i] == ']') square[s++] = expr[i];
        if (expr[i] == '(' || expr[i] == ')') roundb[r++] = expr[i];
    }

    int resCurly = (c > 0) ? countMinReversals(curly, '{', '}') : 0;
    int resSquare = (s > 0) ? countMinReversals(square, '[', ']') : 0;
    int resRound = (r > 0) ? countMinReversals(roundb, '(', ')') : 0;

    if (resCurly == -1 || resSquare == -1 || resRound == -1)
        return -1;

    return resCurly + resSquare + resRound;
}

// Main function
int main() {
    char expr[1000];
    printf("Enter expression with {}, [], (): ");
    scanf("%s", expr);

    int result = minReversalsAll(expr);

    if (result == -1)
        printf("Cannot be balanced (odd length in one type)\n");
    else
        printf("Minimum reversals needed: %d\n", result);

    return 0;
}
