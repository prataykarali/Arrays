class Node:
    def __init__(self, val):
        self.val = val
        self.next = None


def show(head, name):
    cur = head
    print(name, end=": ")
    while cur:
        print(cur.val, end=" -> ")
        cur = cur.next
    print("None")


def length(head):
    l = 0
    cur = head
    while cur:
        l += 1
        cur = cur.next
    return l


def intersect(f, s):
    lf, ls = length(f), length(s)

    if lf > ls:
        for _ in range(lf - ls):
            f = f.next
    else:
        for _ in range(ls - lf):
            s = s.next

    while f and s:
        if f is s:
            return f
        f, s = f.next, s.next
    return None


c = Node(30)
c.next = Node(40)
c.next.next = Node(50)

f = Node(10)
f.next = Node(20)
f.next.next = c

s = Node(15)
s.next = c

show(f, "First")
show(s, "Second")

x = intersect(f, s)
if x:
    print("Intersect at:", x.val)
else:
    print("No intersection")
