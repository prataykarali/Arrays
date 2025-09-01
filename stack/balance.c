#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct S {
    char a[MAX];
    int t;
} S;

// Stack functions
void init(S* s) { s->t = -1; }
void push(S* s, char c) { s->a[++s->t] = c; }
char pop(S* s) { return s->t == -1 ? '\0' : s->a[s->t--]; }
char peek(S* s) { return s->t == -1 ? '\0' : s->a[s->t]; }
int empty(S* s) { return s->t == -1; }

// Balanced parentheses checker
int pos(char* s) {
    S st;
    init(&st);

    for (int i = 0; s[i] != '\0'; i++) {
        char c = s[i];
        if (c == '(' || c == '{' || c == '[')
            push(&st, c);
        else if (c == ')' || c == '}' || c == ']') {
            char t = pop(&st);
            if ((c == ')' && t != '(') ||
                (c == '}' && t != '{') ||
                (c == ']' && t != '['))
                return 0;  // False
        }
    }
    return empty(&st); // True if stack is empty
}

int main() {
    char st[] = "[()()]";
    if (pos(st))
        printf("Balanced\n");
    else
        printf("Not Balanced\n");
    return 0;
}
