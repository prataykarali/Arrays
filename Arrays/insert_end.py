class Solution:
    def insertAtEnd(self, arr, val):
       arr.append(val)
       return arr
s=eval(input("Enter array size"))
arr=[]
for i in range(s):
    arr.append(eval(input("Enter value")))
sol=Solution()
val=eval(input())
arr=sol.insertAtEnd(arr,val)
print(arr)