#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
}Node;
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
        // printf("%d",p->next->data);
        return head;
    }
}
Node *sorted(Node *head,int d){
    Node *p=head;
    Node *ptr=(Node *)calloc(1,sizeof(Node));
    // printf("Hi");
    ptr->data=d;
    if (head==NULL){
        ptr->next=ptr;
        ptr->prev=ptr;
        return ptr;
    }
    else if(d<head->data){
        Node *t=head;
        head=ptr;
        head->prev=t->prev;
        t->prev->next=head;
        head->next=t;
        t->prev=head;
        return head;
    }
    else{
        while((p->data<d)&&(p->next!=head)){
            p=p->next;
        }
        // Node *t=p;
        ptr->next=p;
        ptr->prev=p->prev;
        p->prev->next=ptr;
        p->prev=ptr;
        // head->prev=p;
        // printf("%d",p->data);
        return head;
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
    head=sorted(head,0);
    display(head);
}