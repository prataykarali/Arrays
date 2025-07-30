class Solution:
    def countFreq(self, arr):
        #code here
        if arr==[]:
            return [[],[]]
        else:
            arr=sorted(arr)
            s=[]
            u=[]
            p,c=0,0
            for i in range(len(arr)):
               if(arr[i]==arr[p]):
                  c+=1
               else:
                  u.append(arr[p])
                  s.append(c)
                  p+=c
                  c=1
            u.append(arr[i])
            s.append(c)
            return list(zip(u, s))
s=eval(input("Enter array size"))
arr=[]
for i in range(s):
    arr.append(eval(input("Enter value")))
sol=Solution()
a=[[],[]]
a=sol.countFreq(arr)
print(a)