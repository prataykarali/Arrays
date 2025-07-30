class Solution:
    def reverseString(self, s: str) -> str:
        # code here
        return s[::-1]
s=eval(input("Enter array size"))
arr=[]
for i in range(s):
    arr.append(eval(input("Enter value")))
sol=Solution()
arr=sol.reverseString(arr)
print(arr)