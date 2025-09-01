#include <stdio.h>

#define MAX 100

void stock_span(int prices[], int n, int span[]) {
    int st[MAX]; // stack to store indices
    int top = -1;

    for (int i = 0; i < n; i++) {
        // Pop indices where price <= current price
        while (top != -1 && prices[st[top]] <= prices[i]) {
            top--;
        }

        // If stack empty, all previous prices are smaller
        span[i] = (top == -1) ? (i + 1) : (i - st[top]);

        // Push current index onto stack
        st[++top] = i;
    }
}

int main() {
    int prices[] = {100, 80, 60, 70, 60, 75, 85};
    int n = sizeof(prices)/sizeof(prices[0]);
    int span[n];

    stock_span(prices, n, span);

    printf("Stock span: ");
    for (int i = 0; i < n; i++)
        printf("%d ", span[i]);
    printf("\n");

    return 0;
}
