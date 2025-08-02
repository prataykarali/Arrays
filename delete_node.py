class node:
    def __init__(self):
        self.data = None
        self.next = None
'''

def deleteNode(head, x):
    # Code here
    if x==1:
        return head.next
    c=head
    p=head
    for i in range(1,x):
        if i==x-1:
            p=c.next
            c.next=p.next
        c=c.next
    while c is not None:
        c=c.next
    return head