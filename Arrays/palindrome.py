class Solution:
    def isPalindrome(self, s: str) -> bool:
	    for i in s:
		    if s[::-1]!=s[::1]:
		       return False
		    else:
		        return True
s=eval(input("Enter array size"))
arr=[]
for i in range(s):
    arr.append(eval(input("Enter value")))
sol=Solution()
a=sol.isPalindrome(arr)
print(a)