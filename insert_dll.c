#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
}Node;
Node *insert(Node *head,int d){
    Node *newNode=(Node *)calloc(1,sizeof(Node));
    newNode->prev=NULL;
    newNode->data=d;
    newNode->next=head;
    if (head!=NULL){
        head->prev=newNode;
        }
        // head->prev=newNode;
    return newNode;

    }

void display(Node *head){
    if(head==NULL){
        printf("List is empty");
    }
    while(head->next!=NULL){
        printf("%d->",head->data);
        head=head->next;
    }
    printf("%d\n",head->data);
}
int main(){
    Node *head=NULL;
    head=insert(head,4);
    head=insert(head,20);
    head=insert(head,14);
    display(head);
    // printf("hi");
    return 0;
}