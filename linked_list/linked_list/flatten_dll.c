#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node* next;
    struct Node* down;
};

struct Node* newNode(int v) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->val = v;
    n->next = NULL;
    n->down = NULL;
    return n;
}

void show(struct Node* h) {
    while (h) {
        printf("%d -> ", h->val);
        h = h->down;
    }
    printf("NULL\n");
}

struct Node* merge(struct Node* a, struct Node* b) {
    if (!a) return b;
    if (!b) return a;

    struct Node* res;
    if (a->val < b->val) {
        res = a;
        res->down = merge(a->down, b);
    } else {
        res = b;
        res->down = merge(a, b->down);
    }
    res->next = NULL;  
    return res;
}

struct Node* flatten(struct Node* h) {
    if (!h || !h->next) return h;

    h->next = flatten(h->next);   
    h = merge(h, h->next);        
    return h;
}

int main() {
    struct Node* h = newNode(5);
    h->down = newNode(7);
    h->down->down = newNode(8);
    h->down->down->down = newNode(30);

    h->next = newNode(10);
    h->next->down = newNode(20);

    h->next->next = newNode(19);
    h->next->next->down = newNode(22);
    h->next->next->down->down = newNode(50);

    h->next->next->next = newNode(28);
    h->next->next->next->down = newNode(35);
    h->next->next->next->down->down = newNode(40);
    h->next->next->next->down->down->down = newNode(45);

    struct Node* flat = flatten(h);

    printf("Flattened list:\n");
    show(flat);

    return 0;
}
