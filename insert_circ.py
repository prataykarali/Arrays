class Node:
    def __init__(self,data):
        self.data=data
        self.next=None
        self.prev=None
def insert(head,data):
    n=Node(data)
    if(head==None):
        n.next=n
        n.prev=n
        return n
    else:
        t=head
        while(t.next!=head):
            t=t.next
        t.next=n
        n.prev=t
        n.next=head
        head.prev=n
        return head
def ins_ind(head,k,d):
    n=Node(d)
    p=head
    if head==None:
        print("Empty")
        return head
    if k<1:
        print("Index out of bound")
        return None
    if k==1:
        s=head.prev
        head.prev=n
        n.next=head
        n.prev=s
        s.next=n
        head=n
        return head
    else:
        for i in range(1,k-1):
            if (p.next==head and (i!=k)):
                print("index out bound")
                return None
            else:
                p=p.next
        t=p.next
        p.next=n
        n.prev=p
        n.next=t
        t.prev=n
        return head
def display(head):
    if (not head):
        print("Empty")
    else:
        t=head
        while(t.next!=head):
            print(t.data,end=" ")
            t=t.next
        print(t.data)
head=None
head=insert(head,10)
head=insert(head,20)
head=insert(head,40)
display(head)
head=ins_ind(head,0,2)
display(head)