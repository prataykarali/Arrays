# Nodel class
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

# Solution class
class Solution:
    def searchKey(self, n, head, key):
        while head is not None:
            if head.data == key:
                return True
            head = head.next
        return False

# Function to build linked list from list of values
def buildLinkedList(values):
    if not values:
        return None
    head = Node(values[0])
    current = head
    for val in values[1:]:
        current.next = Node(val)
        current = current.next
    return head

# Main Program
if __name__ == "__main__":
    # Input linked list size and elements
    n = int(input("Enter number of nodes: "))
    elements = list(map(int, input("Enter the linked list elements: ").split()))

    if len(elements) != n:
        print("Mismatch in number of elements!")
        exit()

    head = buildLinkedList(elements)

    # Input key to search
    key = int(input("Enter key to search: "))

    # Search using Solution class
    sol = Solution()
    found = sol.searchKey(n, head, key)

    if found:
        print(f"Key {key} found ✅")
    else:
        print(f"Key {key} not found ❌")
