class Node:
    def __init__(self,data):
        self.data=data
        self.next=None
        self.prev=None
def insert(head,d):
    n=Node(d)
    t=head
    if t==None:
        return n
    else:
        while(t.next!=None):
            t=t.next
        t.next=n
        n.prev=t
        return head
def reverse(head):     
     ptr=head
     p=None
     while (ptr!=None):
         n=ptr.next
         ptr.prev=ptr.next
         ptr.next=p
         p=ptr
         ptr=n
     return p
def display(head):
    if(head==None):
        print("Empty")
    while(head):
        print(head.data,end=" ")
        head=head.next
head=None
head=insert(head,10)
head=insert(head,30)
head=insert(head,50)
display(head)
print("\n")
head=reverse(head)
display(head)