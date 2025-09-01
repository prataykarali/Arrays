def span(p):
    n = len(p)
    s = [0]*n
    st = []
    for i in range(n):
        while st and p[st[-1]] <= p[i]:
            st.pop()
        s[i] = i+1 if not st else i - st[-1]
        st.append(i)
    return s

prices = [100, 80, 60, 70, 60, 75, 85]
print(span(prices))  
