#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node* next;
};

struct Node* newNode(int v) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->val = v;
    n->next = NULL;
    return n;
}

void show(struct Node* h, char* name) {
    printf("%s: ", name);
    struct Node* cur = h;
    while (cur) {
        printf("%d -> ", cur->val);
        cur = cur->next;
    }
    printf("NULL\n");
}

int length(struct Node* h) {
    int l = 0;
    while (h) {
        l++;
        h = h->next;
    }
    return l;
}

struct Node* intersect(struct Node* f, struct Node* s) {
    int lf = length(f), ls = length(s);
    if (lf > ls) {
        for (int i = 0; i < lf - ls; i++) f = f->next;
    } else {
        for (int i = 0; i < ls - lf; i++) s = s->next;
    }
    while (f && s) {
        if (f == s) return f;
        f = f->next;
        s = s->next;
    }
    return NULL;
}

int main() {
    struct Node* c = newNode(30);
    c->next = newNode(40);
    c->next->next = newNode(50);

    struct Node* f = newNode(10);
    f->next = newNode(20);
    f->next->next = c;

    struct Node* s = newNode(15);
    s->next = c;

    show(f, "First");
    show(s, "Second");

    struct Node* x = intersect(f, s);
    if (x) printf("Intersect at: %d\n", x->val);
    else   printf("No intersection\n");

    return 0;
}
