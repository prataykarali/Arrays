n = int(input("No of people: "))
a = [[int(input(f"Enter element for {i}th person at {j}th: ")) for j in range(n)] for i in range(n)]

# Step 1: Push all people into stack
stack = [i for i in range(n)]

# Step 2: Eliminate until one remains
while len(stack) > 1:
    A = stack.pop()
    B = stack.pop()

    if a[A][B] == 1:  
        # A knows B → A cannot be celeb
        stack.append(B)
    else:
        # A does not know B → B cannot be celeb
        stack.append(A)

# Step 3: Candidate
candidate = stack.pop()

# Step 4: Verify candidate
celebrity = candidate
for k in range(n):
    if k != celebrity:
        if a[celebrity][k] == 1 or a[k][celebrity] == 0:
            celebrity = -1
            break

print("Matrix:", a)
print("Celebrity:", celebrity)
