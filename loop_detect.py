    # Node Class
    class Node:
		 def __init__(self, data):
    		 self.data = data
    		 self.next = None
	
'''

class Solution:
    #Function to check if the linked list has a loop.
    def detectLoop(self, head):
        #code here
        c=head
        p=head
        while p and p.next:
            c=c.next
            p=p.next.next
            if p==c:
               return True
            
        return False