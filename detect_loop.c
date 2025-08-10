#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to append to the list
void append(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

// Function to create a loop at a given position (1-based)
void createLoop(struct Node* head, int pos) {
    if (pos <= 0) return;
    
    struct Node* loopStart = head;
    for (int i = 1; i < pos && loopStart != NULL; i++) {
        loopStart = loopStart->next;
    }

    if (loopStart == NULL) return;

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    
    temp->next = loopStart;
}

// Function to detect loop using Floyd’s algorithm
int detectLoop(struct Node* head) {
    struct Node* slow = head;
    struct Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return 1; // Loop found
    }
    return 0; // No loop
}

int main() {
    struct Node* head = NULL;
    int n, value, pos;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        append(&head, value);
    }

    printf("Enter loop position (0 for no loop, 1-based index): ");
    scanf("%d", &pos);
    createLoop(head, pos);

    if (detectLoop(head))
        printf("Loop detected ✅\n");
    else
        printf("No loop detected ❌\n");

    return 0;
}
