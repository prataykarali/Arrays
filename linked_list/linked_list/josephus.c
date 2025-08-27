#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
} Node;
Node *insert(Node *head,int data){
    Node *ptr=head;
    Node *s=(Node *)calloc(1,sizeof(Node));
    s->data=data;
    if(head==NULL){
        s->next=s;
        return s;
    }
    while(ptr->next!=head){
        ptr=ptr->next;
    }
    ptr->next=s;
    s->next=head;
    return head;
}
int josephus(Node *head,int k){
    int c=0,i=0;
    Node *p=head;
    // Move p to last node so that p->next == head
    while (p->next != head) {
        p = p->next;
    }
    // Node *ptr=NULL;
    while(p->next!=p){
        for(i=1;i<k;i++){
            // ptr=p;
            p=p->next;
        }
        // j=k;
        Node *temp=p->next;
        p->next=temp->next;
        free(temp);
    }
    return p->data;
}
void display(Node *head){
     Node *p=head;
     if (head==NULL)
         printf("List empty");
     while(p->next!=head){
         printf("%d ",p->data);
         p=p->next;
     }
     printf("%d ",p->data);
}
int main(){
Node *head = NULL;
head = insert(head, 1);
// head = insert(head, 2);
head = insert(head, 3);
head=insert(head,4);
printf("\n");
head=insert(head,2);
// display(head);
int a=josephus(head,5);
printf("%d",a);
return 1;
}