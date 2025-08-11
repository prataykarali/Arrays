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
    if(head==NULL){
        return n;
    }
    else{
        Node *t=head;
        while(t->next!=NULL){
            t=t->next;
        }
        t->next=n;
        n->prev=t;
        t->next->prev=n;
        n->next=NULL;
        return head;
    }   
}
Node *delete(Node *head,int k){
    if(head==NULL){
        printf("List empty");
        return head;
    }
    else{
        int i=0;
        Node *t=head->next;
        Node *p=head;
        if (k==1){
            head=t;
        }
        for(i=1;i<k-1;i++){
            t=t->next;
            p=p->next;
         }
         p->next=t->next;
         return head;
    }
}
void display(Node *head){
     if (head==NULL)
         printf("List empty");
     while(head!=NULL){
         printf("%d ",head->data);
         head=head->next;
     }
    //  print("{}\n".format(head.data))
}
int main(){
Node *head = NULL;
head = insert(head, 4);
head = insert(head, 20);
head = insert(head, 14);
display(head) ;
// head=delete(head,3);
printf("\n");
// head=delete(head,2);
head=delete(head,1);
display(head);
return 1;
}