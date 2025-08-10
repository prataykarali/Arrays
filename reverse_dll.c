#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
}Node;
Node *insert(Node *head,int d){
    Node *n=(Node *)calloc(1,sizeof(Node));
    n->data=d;
    Node *temp=head;
    if(temp==NULL){
        return n;
    }
    else{
        while(temp->next!=NULL){
        temp=temp->next;
        }
        temp->next=n;
        n->prev=temp;
        n->next=NULL;
        return head;
        // head->prev=NULL;
    }
}
    Node *reverse(Node *head){
        Node *ptr=head;
        Node *p=NULL;
        Node *n=head;
        // p->prev=NULL;
        while(ptr!=NULL){
           n=ptr->next;
           ptr->prev=ptr->next;
           ptr->next=p;
           p=ptr;
           ptr=n;
        }
        // ptr->next=p;
        return p;
    }
void display(Node *head){
    if (head==NULL){
        printf("Null");
    }
    else{
        while(head!=NULL){
            printf("%d->",head->data);
            head=head->next;
        }
    }
}
int main(){
    Node *head=NULL;
    head=insert(head,20);
    head=insert(head,30);
    head=insert(head,40);
    // display(head);
    head=reverse(head);
    display(head);
}
