#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to append a node to the linked list
void append(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to delete the x-th node (1-based index)
struct Node* deleteNode(struct Node* head, int x) {
    if (head == NULL)
        return NULL;

    // Deleting the first node
    if (x == 1) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    struct Node* current = head;
    for (int i = 1; i < x - 1 && current != NULL; i++) {
        current = current->next;
    }

    if (current == NULL || current->next == NULL)
        return head;  // Position out of bounds

    struct Node* temp = current->next;
    current->next = temp->next;
    free(temp);

    return head;
}

int main() {
    struct Node* head = NULL;
    int n, val, x;

    // Input number of nodes
    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Input node values
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        append(&head, val);
    }

    // Input position to delete
    printf("Enter position to delete (1-based): ");
    scanf("%d", &x);

    // Delete node
    head = deleteNode(head, x);

    // Print updated list
    printf("Updated linked list:\n");
    printList(head);

    return 0;
}
