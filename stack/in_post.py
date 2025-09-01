def count(c):
    if c=='^':
        return 3
    if c=='*' or c=='/':
        return 2
    if c=='+' or c=='-':
        return 1
def in_pos(s):
  st=[]
  p=[]
  for i in s:
    if i in "^+-*/":
          # if st and count(i)>=count(st[-1]):
          #   st.append(i)
          if st:
            while st and st[-1]!='(' and count(st[-1])>=count(i):
                t=st.pop()
                p.append(t)
            st.append(i)
          else:
            st.append(i)
    elif i in "()":
        if i=='(':
            st.append(i)
        elif st and i==')':
            while st and st[-1]!='(':
              t=st.pop()
              p.append(t)
            st.pop()
    else:
        p.append(i)
  while st:
        p.append(st.pop())

  return p
s="a*(b+c)/d"
print(in_pos(s))
