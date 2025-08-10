# Node class
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

# Function to delete the x-th node
def deleteNode(head, x):
    if head is None:
        return None

    # Deleting the first node
    if x == 1:
        return head.next

    current = head
    # Traverse to the (x-1)-th node
    for i in range(1, x - 1):
        if current is None or current.next is None:
            return head  # Position out of bounds
        current = current.next

    # Delete x-th node if exists
    if current.next is not None:
        current.next = current.next.next

    return head

# Function to print the linked list
def printList(head):
    while head:
        print(head.data, end=' ')
        head = head.next
    print()

# Function to build the linked list from a list of values
def buildLinkedList(values):
    if not values:
        return None
    head = Node(values[0])
    current = head
    for val in values[1:]:
        current.next = Node(val)
        current = current.next
    return head

# Main program
if __name__ == "__main__":
    # Input: list elements
    elements = list(map(int, input("Enter elements of linked list: ").split()))
    head = buildLinkedList(elements)

    # Input: position to delete
    x = int(input("Enter position to delete (1-based): "))

    # Delete node
    head = deleteNode(head, x)

    # Output: updated list
    print("Updated linked list:")
    printList(head)
