class Solution:
        def getSecondLargest(self, arr):
            # Code Here
            arr = set(arr)
            m = max(arr)
            arr.remove(m)
            if len(arr) < 1:
                return -1
            else:
                return max(arr)
s=eval(input("Enter array size"))
arr=[]
for i in range(s):
    arr.append(eval(input("Enter value")))
sol=Solution()
arr=sol.getSecondLargest(arr)
print(arr)