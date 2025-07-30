class Solution:
    def isSorted(self, arr) -> bool:
        # code here
        return arr==sorted(arr)

s = eval(input("Enter array size"))
arr = []
for i in range(s):
     arr.append(eval(input("Enter value")))
sol = Solution()
b = sol.isSorted(arr)
print(b)