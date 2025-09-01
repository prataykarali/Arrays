#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct S {
    int a[MAX]; 
    int t;     
} S;

void init(S* s) {
    s->t = -1;
}

void push(S* s, int x) {
    if (s->t == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    s->a[++s->t] = x;
}

int pop(S* s) {
    if (s->t == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    return s->a[s->t--];
}

int peek(S* s) {
    return s->t == -1 ? -1 : s->a[s->t];
}

int empty(S* s) {
    return s->t == -1;
}


void disp(S* s) {
    for (int i = s->t; i >= 0; i--)
        printf("%d ", s->a[i]);
    printf("\n");
}

int main() {
    S stk;
    init(&stk);

    push(&stk, 10);
    push(&stk, 20);
    push(&stk, 30);

    disp(&stk);        
    printf("%d\n", pop(&stk));  
    printf("%d\n", peek(&stk)); 
    disp(&stk);       

    return 0;
}
