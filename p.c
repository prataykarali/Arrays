#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

Node *insert(Node *head, int data) {
    Node *n = (Node *)malloc(sizeof(Node));
    n->data = data;
    n->next = n->prev = NULL;

    if (head == NULL) {
        n->next = n;
        n->prev = n;
        return n;
    } else {
        Node *t = head->prev; // last node
        t->next = n;
        n->prev = t;
        n->next = head;
        head->prev = n;
        return head;
    }
}

Node *insertAtK(Node *head, int data, int k) {
    Node *n = (Node *)malloc(sizeof(Node));
    n->data = data;

    if (head == NULL) {
        n->next = n;
        n->prev = n;
        return n;
    }

    if (k == 1) {
        Node *last = head->prev;
        n->next = head;
        n->prev = last;
        last->next = n;
        head->prev = n;
        head = n;
        return head;
    }

    Node *t = head;
    int i;
    for (i = 1; i < k - 1 && t->next != head; i++) {
        t = t->next;
    }

    n->next = t->next;
    n->prev = t;
    t->next->prev = n;
    t->next = n;

    return head;
}

void display(Node *head) {
    if (head == NULL) {
        printf("Empty\n");
        return;
    }
    Node *t = head;
    do {
        printf("%d ", t->data);
        t = t->next;
    } while (t != head);
    printf("\n");
}

int main() {
    Node *head = NULL;
    head = insert(head, 20);
    head = insert(head, 30);
    head = insert(head, 50);
    display(head);

    head = insertAtK(head, 4, 1);
    display(head);

    return 0;
}
