'''
	{
		# Node Class
		class Node:
		    def __init__(self, data):   # data -> value stored in node
		        self.data = data
		        self.next = None
	}
'''
class Solution:
    def getKthFromLast(self, head, k):
        #code here
        prev=None
        g=head
        c=head
        co=0
        while c is not None:
            n=c.next
            c.next=prev
            prev=c
            c=n
            co+=1
        if(k>co):
            return -1
        for i in range(1,k):
                prev=prev.next
        return prev.data