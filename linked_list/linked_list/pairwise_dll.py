class Node:
    def __init__(self,data):
        self.data=data
        self.next=None
        self.prev=None
def insert(head,data):
    p=Node(data)
    ptr=head
    if not head:
        p.next=p
        p.prev=p
        return p
    else:
        while(ptr.next!=head):
            ptr=ptr.next
        ptr.next=p
        p.prev=ptr
        p.next=head
        head.prev=p
        return head
def pair(head):
    p=head
    t=head
    while True:
        ptr=p.next
        ptr.prev=p.prev
        p.prev.next=ptr
        p.next=ptr.next
        ptr.next.prev=p
        ptr.next=p
        p.prev=ptr
        if(p==t):
          head=ptr
          head.prev.next=head
        p=p.next
        if p.next==head or p==head:
            break
    return head
def display(head):
    if not head:
        print("None")
    else:
        p=head
        while(p.next!=head):
            print(p.data,end=" ")
            p=p.next
        print(p.data)
head=None
head=insert(head,10)
head=insert(head,20)
head=insert(head,40)
head=insert(head,50)
head=insert(head,60)
display(head)
head=pair(head)
display(head)