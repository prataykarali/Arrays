class Node:
    def __init__(self,data):
        self.data=data
        self.next=None
        self.prev=None
def insert(head,data):
    n=Node(data)
    if head==None:
        return n
    else:
        p=head
        while(p.next!=None):
            p=p.next
        p.next=n
        n.prev=p
        n.next=None
        return head
def delete(head,k):
    if head==None:
        print("Empty list")
        return head
    else:
        ptr=head.next
        p=head
        if k==1:
            head=ptr
            head.prev=None
        for i in range(1,k-1):
            ptr=ptr.next
            p=p.next
        p.next=ptr.next
        return head
def display(head):
     p=head
     while(p!=None):
         print(p.data,end=" ")
         p=p.next
head=None

head=insert(head,10)
head=insert(head,20)
head=insert(head,30)
head=insert(head,40)
display(head)
print("\n")
head=delete(head,3)
head=delete(head,1)
display(head)