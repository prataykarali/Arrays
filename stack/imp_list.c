#include <stdio.h>
#include <stdlib.h>

typedef struct N {
    int d;
    struct N* n;
} N;

typedef struct S {
    N* t;
} S;

// Push
void push(S* s, int x) {
    N* p = (N*)malloc(sizeof(N));
    p->d = x;
    p->n = s->t;
    s->t = p;
}

// Pop
int pop(S* s) {
    if (!s->t) {
        printf("Stack Underflow\n");
        return -1;
    }
    int x = s->t->d;
    N* temp = s->t;
    s->t = s->t->n;
    free(temp);
    return x;
}

// Peek
int peek(S* s) {
    return s->t ? s->t->d : -1;
}

// Check empty
int empty(S* s) {
    return s->t == NULL;
}

// Display
void disp(S* s) {
    N* c = s->t;
    while (c) {
        printf("%d ", c->d);
        c = c->n;
    }
    printf("\n");
}

int main() {
    S stk = {NULL};
    push(&stk, 10);
    push(&stk, 20);
    push(&stk, 30);

    disp(&stk);          
    printf("%d\n", pop(&stk));   
    printf("%d\n", peek(&stk));  
    disp(&stk);          

    return 0;
}
