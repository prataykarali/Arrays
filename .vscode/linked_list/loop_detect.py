# Node class
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

# Solution class
class Solution:
    def detectLoop(self, head):
        slow = head
        fast = head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
            if slow == fast:
                return True
        return False

# Utility: Create linked list from list
def createLinkedList(values):
    if not values:
        return None
    head = Node(values[0])
    current = head
    for val in values[1:]:
        current.next = Node(val)
        current = current.next
    return head

# Utility: Create a loop at given position (1-based)
def createLoop(head, pos):
    if pos <= 0:
        return head
    loop_start = head
    for _ in range(pos - 1):
        if loop_start.next:
            loop_start = loop_start.next
        else:
            return head  # Position out of bounds
    end = head
    while end.next:
        end = end.next
    end.next = loop_start
    return head

# Main
if __name__ == "__main__":
    # Input linked list elements
    elements = list(map(int, input("Enter elements of linked list separated by space: ").split()))
    head = createLinkedList(elements)

    # Input loop position
    loop_pos = int(input("Enter loop position (0 for no loop, 1-based index): "))
    head = createLoop(head, loop_pos)

    # Detect loop
    sol = Solution()
    if sol.detectLoop(head):
        print("Loop detected ✅")
    else:
        print("No loop detected ❌")
