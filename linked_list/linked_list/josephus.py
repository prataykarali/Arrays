class Node:
    def __init__(self,data):
        self.data=data
        self.next=None
        self.prev=None
def insert(head,data):
    n=Node(data)
    if head==None:
        n.next=n
        n.prev=n
        return n
    else:
        p=head
        while(p.next!=head):
            p=p.next
        p.next=n
        n.prev=p
        n.next=head
        head.prev=n
        return head
def josephus(head,k):
    p=head
    # ptr=head
    while(p.next!=p):
        for i in range(k-1):
            p=p.next
        t=p.next
        p.prev.next=t
        p.next.prev=p.prev
        del p
        p=t
    return p.data
def display(head):
    if head==None:
        return head
    else:
        p=head
        while(p.next!=head):
            print(p.data,end=" ")
            p=p.next
head=None
head=insert(head,1)
head=insert(head,2)
head=insert(head,3)
head=insert(head,4)
print(josephus(head,2))