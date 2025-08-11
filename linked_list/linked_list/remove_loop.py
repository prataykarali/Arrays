# Node class
class Node:
    def __init__(self, val):
        self.next = None
        self.data = val

# Solution class with removeLoop method
class Solution:
    def removeLoop(self, head):
        slow = head
        fast = head

        # Step 1: Detect loop using Floyd’s algorithm
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
            if slow == fast:
                break
        else:
            # No loop found
            return

        # Step 2: Find the start of the loop
        slow = head
        if slow == fast:
            # Special case: loop starts at head
            while fast.next != slow:
                fast = fast.next
        else:
            while slow.next != fast.next:
                slow = slow.next
                fast = fast.next

        # Step 3: Remove the loop
        fast.next = None
