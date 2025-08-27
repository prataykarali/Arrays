class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
        self.prev = None

def insert(head, data):
    ptr = Node(data)
    if head is None:
        ptr.next = ptr
        ptr.prev = ptr
        return ptr
    else:
        p = head
        while p.next != head:
            p = p.next
        p.next = ptr
        ptr.prev = p
        ptr.next = head
        head.prev = ptr
        return head

def check(head):
    if head is None:
        print("NULL")
        return True  # GFG convention: empty list is circular
    else:
        p = head
        while p.next is not None and p.next != head:
            p = p.next
        if p.next == head:
            return True
        else:
            return False

def display(head):
    if head is None:
        print("NULL")
        return
    p = head
    while p.next != head:
        print(p.data, end="->")
        p = p.next
    print(p.data)

if __name__ == "__main__":
    head = None
    head = insert(head, 10)
    head = insert(head, 10)
    head = insert(head, 30)
    t = check(head)
    print("Is circular?", "true" if t else "false")
    display(head)