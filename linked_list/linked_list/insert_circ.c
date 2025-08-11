#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
}Node;
Node *insert(Node *head,int data){
    Node *n=(Node *)calloc(1,sizeof(Node));
    n->data=data;
    if(head==NULL){
        n->next=n;
        n->prev=n;
        // printf("1");
        return n;
    }
    else{
        Node *t=head;
        while((t->next!=head)){
            t=t->next;
        }
        t->next=n;
        n->prev=t;
        head->prev=n;
        n->next=head;
        // printf("1");
        return head;
    }
}
Node *ind_ins(Node *head,int k,int data){
    Node *n=(Node *)calloc(1,sizeof(Node));
    n->data=data;
    if(head==NULL){
        n->next = n;
        n->prev = n;
        printf("Empty");
    }
    else{
        int i=1;
        Node *t=head;
        if (k == 1) {
        Node *last = head->prev;
        n->next = head;
        n->prev = last;
        last->next = n;
        head->prev = n;
        head = n;
        return head;
    }

        // Node *t = head;
    // int i;
    for (i = 1; i < k - 1 && t->next != head; i++) {
        t = t->next;
    }

    n->next = t->next;
    n->prev = t;
    t->next->prev = n;
    t->next = n;

        return head;
}
}
void display(Node *head) {
    if (head == NULL) {
        printf("Empty");
        return;
    }
    Node *t = head;
    do {
        printf("%d ", t->data);
        t = t->next;
    } while (t != head);
    printf("\n");
}
int main(){
    Node *head=NULL;
    // printf("1");
    head=insert(head,20);
    head=insert(head,30);
    head=insert(head,50);
    display(head);
    head=ind_ins(head,1,4);
    printf("\n");
    display(head);
    printf("\nhead->data = %d", head->data);
printf("\nhead->prev->data = %d", head->prev->data); // should be 50
printf("\nhead->next->data = %d", head->next->data); // should be 30

}


