def pos(s):
    st = []
    for i in range(len(s)):
        if s[i] in "({[":
            st.append(s[i])
        if s[i] in ")}]":
            t = st.pop()
            if s[i] == ')' and t != '(':
                return False
            elif s[i]=='}' and t!='{':
                return False
            elif s[i]==']' and t!='[':
                return False
    if not st:
        return True
    else:
        return False\
st = "[()()]"
print(pos(st))