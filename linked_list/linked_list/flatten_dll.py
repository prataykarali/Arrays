class Node:
    def __init__(self, val):
        self.val = val
        self.next = None
        self.down = None

def show(head):
    cur = head
    while cur:
        print(cur.val, end=" -> ")
        cur = cur.down
    print("None")

def merge(a, b):
    if not a:
        return b
    if not b:
        return a
    if a.val < b.val:
        res = a
        res.down = merge(a.down, b)
    else:
        res = b
        res.down = merge(a, b.down)
    res.next = None
    return res

def flatten(head):
    if not head or not head.next:
        return head
    head.next = flatten(head.next)
    head = merge(head, head.next)
    return head

if __name__ == "__main__":
    h = Node(5)
    h.down = Node(7)
    h.down.down = Node(8)
    h.down.down.down = Node(30)

    h.next = Node(10)
    h.next.down = Node(20)

    h.next.next = Node(19)
    h.next.next.down = Node(22)
    h.next.next.down.down = Node(50)

    h.next.next.next = Node(28)
    h.next.next.next.down = Node(35)
    h.next.next.next.down.down = Node(40)
    h.next.next.next.down.down.down = Node(45)

    flat = flatten(h)
    print("Flattened list:")
    show(flat)
