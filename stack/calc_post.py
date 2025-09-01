def postfix_to_infix(exp):
    st = []
    for c in exp:
        if c.isalnum():  # operand
            st.append(c)
        else:  # operator
            op1 = st.pop()
            op2 = st.pop()
            st.append(f"({op2}{c}{op1})")
    return st[0]

exp = "543+*2/"
e=eval(postfix_to_infix(exp))
print(e)
