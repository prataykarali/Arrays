#include <stdio.h>
#include <stdlib.h>

// Function to check if person A knows person B
int knows(int **a, int A, int B) {
    return a[A][B];
}

int main() {
    int n;
    printf("No of people: ");
    scanf("%d", &n);

    // Allocate adjacency matrix
    int **a = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        a[i] = (int *)malloc(n * sizeof(int));
    }

    // Input matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("Enter element for %dth person at %dth: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    // Step 1: Push all people into stack
    int *stack = (int *)malloc(n * sizeof(int));
    int top = -1;
    for (int i = 0; i < n; i++) {
        stack[++top] = i;
    }

    // Step 2: Eliminate until one remains
    while (top > 0) {
        int A = stack[top--];
        int B = stack[top--];

        if (knows(a, A, B)) {
            // A knows B → A cannot be celebrity
            stack[++top] = B;
        } else {
            // A does not know B → B cannot be celebrity
            stack[++top] = A;
        }
    }

    // Step 3: Candidate
    int candidate = stack[top];

    // Step 4: Verify candidate
    int celebrity = candidate;
    for (int i = 0; i < n; i++) {
        if (i != candidate) {
            if (knows(a, candidate, i) || !knows(a, i, candidate)) {
                celebrity = -1;
                break;
            }
        }
    }

    // Print results
    printf("Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    if (celebrity != -1)
        printf("Celebrity is person: %d\n", celebrity);
    else
        printf("No celebrity found\n");

    // Free memory
    for (int i = 0; i < n; i++) free(a[i]);
    free(a);
    free(stack);

    return 0;
}
