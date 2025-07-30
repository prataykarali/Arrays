class Solution:
    def rotate(self, arr):
        arr.insert(0,arr[-1])
        arr.pop(-1)
        return arr
s=eval(input("Enter array size"))
arr=[]
for i in range(s):
    arr.append(eval(input("Enter value")))
sol=Solution()
arr=sol.rotate(arr)
print(arr)