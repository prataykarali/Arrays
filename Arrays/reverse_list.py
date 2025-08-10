# Node class
class Node:
    def __init__(self, val):
        self.data = val
        self.next = None

# Solution class with reverseList function
class Solution:
    def reverseList(self, head):
        prev = None
        current = head

        while current is not None:
            next_node = current.next  # Store next
            current.next = prev       # Reverse current node's pointer
            prev = current            # Move prev and current one step forward
            current = next_node

        return prev  # New head after reversal

# --- Helper Functions (for testing) ---

# Build linked list from list of values
def buildLinkedList(values):
    if not values:
        return None
    head = Node(values[0])
    current = head
    for val in values[1:]:
        current.next = Node(val)
        current = current.next
    return head

# Print linked list
def printList(head):
    while head:
        print(head.data, end=' ')
        head = head.next
    print()

# --- Example Usage ---
if __name__ == "__main__":
    elements = list(map(int, input("Enter linked list elements: ").split()))
    head = buildLinkedList(elements)

    sol = Solution()
    reversed_head = sol.reverseList(head)

    print("Reversed linked list:")
    printList(reversed_head)
