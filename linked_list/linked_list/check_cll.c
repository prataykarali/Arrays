#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
} Node;
Node *insert(Node *head,int data){
    Node *p=head;
    Node *ptr=(Node *)calloc(1,sizeof(Node));
    ptr->data=data;
    if (head==NULL){
        ptr->next=ptr;
        ptr->prev=ptr;
        return ptr;
    }
    else{
        while(p->next!=head){
            p=p->next;
        }
        p->next=ptr;
        ptr->prev=p;
        ptr->next=head;
        head->prev=ptr;
        return head;
    }
}
bool check(Node *head){
    if (head==NULL){
        printf("NULL");
        return true;
    }
    else{
        Node *p=head;
        while(p->next!=head && p->next!=NULL){
            p=p->next;
        }
        if(p->next==head){
            return true;
        }
        else{
            return false;
        }
    }
}
void display(Node *head){
    Node *p=head;
    if(head==NULL){
        printf("NULL");
    }
    else{
        while(p->next!=head){
            printf("%d->",p->data);
            p=p->next;
        }
        printf("%d",p->data);
    }
}
int main(){
    Node *head=NULL;
    head=insert(head,10);
    head=insert(head,10);
    head=insert(head,30);
    bool t=check(head);
    printf("Is circular? %s\n", t ? "true" : "false");
    display(head);
    return 0;
}