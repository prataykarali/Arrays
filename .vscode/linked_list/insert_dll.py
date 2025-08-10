class Node:
    def __init__(self,data):
        self.data=data
        self.next=None
        self.prev=None
def insert(head,d):
     n=Node(d)
     n.next=head
     n.prev=None
     if head!=None:
         head.prev=n
     return n
def display(head):
     if head==None:
         print("List empty")
     while(head.next!=None):
         print("{}->".format(head.data),end="")
         head=head.next
     print("{}\n".format(head.data))
head = None
head = insert(head, 4)
head = insert(head, 20)
head = insert(head, 14)
display(head) 