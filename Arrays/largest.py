class Solution:
    def largest(self, arr):
        # code here
        return max(arr)
s=eval(input("Enter array size"))
arr=[]
for i in range(s):
    arr.append(eval(input("Enter value")))
sol=Solution()
arr=sol.largest(arr)
print(arr)
