#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* p = (struct Node*)malloc(sizeof(struct Node));
    p->data = data;
    p->next = p->prev = NULL;
    return p;
}

// Insert at end of circular doubly linked list
struct Node* insert(struct Node* head, int data) {
    struct Node* p = newNode(data);
    if (head == NULL) {
        p->next = p;
        p->prev = p;
        return p;
    } else {
        struct Node* ptr = head;
        while (ptr->next != head)
            ptr = ptr->next;
        ptr->next = p;
        p->prev = ptr;
        p->next = head;
        head->prev = p;
        return head;
    }
}

// Pairwise swap nodes
struct Node* pair(struct Node* head) {
    if (!head || head->next == head) return head; // 0 or 1 node case

    struct Node* p = head;
    struct Node* t = head;

    while (1) {
        struct Node* ptr = p->next;

        // Swap p and ptr
        ptr->prev = p->prev;
        p->prev->next = ptr;
        p->next = ptr->next;
        ptr->next->prev = p;
        ptr->next = p;
        p->prev = ptr;

        // If first swap, update head
        if (p == t) {
            head = ptr;
            head->prev->next = head;
        }

        // Move p forward by one pair
        p = p->next;
        if (p->next == head || p == head)
            break;
    }

    return head;
}

// Display circular doubly linked list
void display(struct Node* head) {
    if (!head) {
        printf("None\n");
        return;
    }
    struct Node* p = head;
    while (p->next != head) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("%d\n", p->data);
}

// Driver code
int main() {
    struct Node* head = NULL;

    head = insert(head, 10);
    head = insert(head, 20);
    head = insert(head, 40);
    head = insert(head, 50);
    head = insert(head, 60);

    display(head);

    head = pair(head);

    display(head);

    return 0;
}
