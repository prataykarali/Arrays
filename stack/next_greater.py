def next_greater(arr):
    n = len(arr)
    nge = [-1] * n
    st = []  

    for i in range(n):

        while st and arr[i] > arr[st[-1]]:
            idx = st.pop()
            nge[idx] = arr[i]
        st.append(i)

    return nge


arr = [4, 5, 2, 25]
print(next_greater(arr))  
