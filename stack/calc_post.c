#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX 100
#define MAX_LEN 50

// Stack of strings
typedef struct {
    char* a[MAX];
    int t;
} S;

void init(S* s) { s->t = -1; }
void push(S* s, char* str) { s->a[++s->t] = str; }
char* pop(S* s) { return s->t == -1 ? NULL : s->a[s->t--]; }
char* peek(S* s) { return s->t == -1 ? NULL : s->a[s->t]; }
int empty(S* s) { return s->t == -1; }

// Convert postfix to infix (with parentheses)
char* postfix_to_infix(char* exp) {
    S st;
    init(&st);
    int n = strlen(exp);

    for (int i = 0; i < n; i++) {
        char c = exp[i];

        if (isalnum(c)) { // operand
            char* op = (char*)malloc(2);
            op[0] = c;
            op[1] = '\0';
            push(&st, op);
        } else { // operator
            char* op1 = pop(&st);
            char* op2 = pop(&st);
            char* res = (char*)malloc(strlen(op1) + strlen(op2) + 4);
            sprintf(res, "(%s%c%s)", op2, c, op1);
            push(&st, res);
            free(op1);
            free(op2);
        }
    }
    return pop(&st);
}

// Evaluate simple postfix with single-digit operands
double eval_postfix(char* exp) {
    double stack[MAX];
    int t = -1;

    for (int i = 0; exp[i] != '\0'; i++) {
        char c = exp[i];
        if (isdigit(c)) stack[++t] = c - '0';
        else {
            double op1 = stack[t--];
            double op2 = stack[t--];
            switch(c) {
                case '+': stack[++t] = op2 + op1; break;
                case '-': stack[++t] = op2 - op1; break;
                case '*': stack[++t] = op2 * op1; break;
                case '/': stack[++t] = op2 / op1; break;
                case '^': stack[++t] = pow(op2, op1); break;
            }
        }
    }
    return stack[t];
}

int main() {
    char exp[] = "543+*2/";
    char* infix = postfix_to_infix(exp);
    printf("Infix: %s\n", infix);

    double val = eval_postfix(exp);
    printf("Value: %.2lf\n", val);

    free(infix);
    return 0;
}
