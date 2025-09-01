#include <stdio.h>
#include <string.h>

#define MAX 100

// Stack for operators
typedef struct {
    char a[MAX];
    int t;
} S;

void init(S* s) { s->t = -1; }
void push(S* s, char c) { s->a[++s->t] = c; }
char pop(S* s) { return s->t == -1 ? '\0' : s->a[s->t--]; }
char peek(S* s) { return s->t == -1 ? '\0' : s->a[s->t]; }
int empty(S* s) { return s->t == -1; }

// Operator precedence
int count(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

// Infix to Postfix
void in_pos(char* s, char* p) {
    S st;
    init(&st);
    int k = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        char c = s[i];
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
            p[k++] = c;  // operand
        }
        else if (c == '(') {
            push(&st, c);
        }
        else if (c == ')') {
            while (!empty(&st) && peek(&st) != '(')
                p[k++] = pop(&st);
            pop(&st); // remove '('
        }
        else { // operator
            while (!empty(&st) && peek(&st) != '(' && count(peek(&st)) >= count(c))
                p[k++] = pop(&st);
            push(&st, c);
        }
    }

    while (!empty(&st))
        p[k++] = pop(&st);

    p[k] = '\0'; // null terminate
}

int main() {
    char s[] = "a*(b+c)/d";
    char p[100];
    in_pos(s, p);
    printf("%s\n", p);  // Output: abc+*d/
    return 0;
}
