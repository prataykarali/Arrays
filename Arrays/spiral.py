# Input matrix
r = int(input("Enter number of rows: "))
c = int(input("Enter number of columns: "))

a = []
print("Enter elements row-wise:")
for i in range(r):
    row = []
    for j in range(c):
        row.append(int(input(f"Element [{i}][{j}]: ")))
    a.append(row)

# Clockwise Rotation (90°)
b = []
for j in range(c):
    new_row = []
    for i in range(r - 1, -1, -1):
        new_row.append(a[i][j])
    b.append(new_row)

print("\n90° Clockwise Rotation:")
for row in b:
    for val in row:
        print(val, end=' ')
    print()

# Anticlockwise Rotation (90°)
d = []
for j in range(c - 1, -1, -1):
    new_row = []
    for i in range(r):
        new_row.append(a[i][j])
    d.append(new_row)

print("\n90° Anticlockwise Rotation:")
for row in d:
    for val in row:
        print(val, end=' ')
    print()