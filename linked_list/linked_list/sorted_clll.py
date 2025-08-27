class Node:
    def __init__(self,data):
        self.data=data
        self.next=None
        self.prev=None
def insert(head,data):
    p=head
    ptr=Node(data)
    if p==None:
       ptr.prev=ptr
       ptr.next=ptr
       return ptr
    else:
        while(p.next!=head):
            p=p.next
        p.next=ptr
        ptr.prev=p
        ptr.next=head
        head.prev=ptr
        return head
def sorted(head,data):
    ptr=Node(data)
    if head==None:
        return head
    elif data<head.data:
        p=head
        ptr.next=p
        ptr.prev=p.prev
        p.prev.next=ptr
        p.prev=ptr
        head=ptr
        return head
    else:
        p=head
        while(p.next!=head):
            if(p.data>data):
                temp=p
                ptr.next=temp
                p.prev.next=ptr
                ptr.prev=p.prev
                p.prev=ptr
                return head
            p=p.next
        temp=p
        ptr.next=temp
        p.prev.next=ptr
        ptr.prev=p.prev
        p.prev=ptr
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
head=sorted(head,6)
display(head)